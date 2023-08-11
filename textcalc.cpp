#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int t=0;
const double inf=1.7976931348623157E+308;

struct Element
{
    vector<Element*> v;
    virtual void setU(double U)
    {
    }

    virtual void setI(double I)
    {
    }

    virtual double Rm()
    {
        return 0;
    }

    virtual double Um()
    {
        return 0;
    }

    virtual double Im()
    {
        return 0;
    }

    double dphi()
    {
        return 0;
    }

    virtual void read(istream &ist)
    {
    }

    virtual void print(ostream &ost)
    {
        ost << "E()";
    }

    virtual void printe(ostream &ost)
    {
        ost << "E()";
    }
};

struct Resistor : Element
{
    double R = 0.0;
    double U = 0.0;
    double I = 0.0;

    Resistor (double R)
    {
        this->R = R;
    }

    void setU(double U) override
    {
        this->U=U;
        this->I=U/R;
    }

    void setI(double I) override
    {
        this->U=I*R;
        this->I=I;
    }

    double Rm() override
    {
        return R;
    }

    double Um() override
    {
        return U;
    }

    double Im() override
    {
        return I;
    }

    void print(ostream &ost) override
    {
        ost << "R(" << R << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "R(" << R << ";" << U << ";" << I << ")\n";
    }
};

struct Bulb : Resistor
{
    double W = inf;
    double b = 0.0;

    Bulb (double R, double W) : Resistor(R)
    {
        this->W = W;
    }

    void setU(double U) override
    {
        this->U=U;
        this->I=U/R;
        b=this->U*this->I/W;
        if (b>1)
            R=inf;
    }

    void setI(double I) override
    {
        this->U=I*R;
        this->I=I;
        b=this->U*this->I/W;
        if (b>1)
            R=inf;
    }

    void print(ostream &ost) override
    {
        ost << "B(" << R << ";" << W << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "B(" << R << ";" << U << ";" << I << ";" << W << ";" << b << ")\n";
    }
};

struct Series : Element
{
    Series ()
    {
        v.resize(0);
    }

    void push(Element* e)
    {
        v.push_back(e);
    }

    void setU(double U) override
    {
        double I=U/Rm();
        setI(I);
    }

    void setI(double I) override
    {
        for (Element* e : v)
            e->setI(I);
    }

    double Rm() override
    {
        double R=0.0;
        for (Element* e : v)
            R+=e->Rm();
        return R;
    }

    double Um() override
    {
        double U=0.0;
        for (Element* e : v)
            U+=e->Um();
        return U;
    }

    double Im() override
    {
        return v[0]->Im();
    }

    void read(istream &ist) override;

    void print(ostream &ost) override
    {
        ost << "[\n";
        for (Element* e : v)
            e->print(ost);
        ost << "]\n";
    }

    void printe(ostream &ost) override
    {
        ost << "[\n";
        for (Element* e : v)
            e->printe(ost);
        ost << "]\n";
    }
};

struct Parallel : Element
{
    Parallel ()
    {
        v.resize(0);
    }

    void push(Element* e)
    {
        v.push_back(e);
    }

    void setU(double U) override
    {
        for (Element* e : v)
            e->setU(U);
    }

    void setI(double I) override
    {
        double U=I*Rm();
        setU(U);
    }

    double Rm() override
    {
        double G=0.0;
        for (Element* e : v)
            G+=(1/e->Rm());
        return 1/G;
    }

    double Um() override
    {
        return v[0]->Um();
    }

    double Im() override
    {
        double I=0.0;
        for (Element* e : v)
            I+=e->Im();
        return I;
    }

    void read(istream &ist) override;

    void print(ostream &ost) override
    {
        ost << "{\n";
        for (Element* e : v)
            e->print(ost);
        ost << "}\n";
    }

    void printe(ostream &ost) override
    {
        ost << "{\n";
        for (Element* e : v)
            e->printe(ost);
        ost << "}\n";
    }
};

void Series::read(istream &ist)
{
    char c;
    ist >> c;
    if (c=='R')
    {
        double R;
        ist >> c;
        ist >> R;
        push(new Resistor{R});
        ist >> c;
        read(ist);
    } else
    if (c=='[')
    {
        push(new Series);
        (*v.back()).read(ist);
        read(ist);
    } else
    if (c=='{')
    {
        push(new Parallel);
        (*v.back()).read(ist);
        read(ist);
    } else
    if (c==']')
    {
        return;
    }
    return;
}


void Parallel::read(istream &ist)
{
    char c;
    ist >> c;
    if (c=='R')
    {
        double R;
        ist >> c;
        ist >> R;
        push(new Resistor{R});
        ist >> c;
        read(ist);
    } else
    if (c=='[')
    {
        push(new Series);
        (*v.back()).read(ist);
        read(ist);
    } else
    if (c=='{')
    {
        push(new Parallel);
        (*v.back()).read(ist);
        read(ist);
    } else
    if (c=='}')
    {
        return;
    }
    return;
}

int main() {
    double Ee=1.0, nu=0.0, phi0=0.0;
    char c;
    Series s;
    fstream f;
    string in, out;

    cout << "Choose input file\n";
    cin >> in;

    cout << "Enter EMF\n";
    cin >> Ee;

    cout << "Choose output file\n";
    cin >> out;

    f.open(in, ios::in);
    f >> c;
    if (c=='[')
        s.read(f);
    f.close();

    s.setU(Ee);

    f.open(out, ios::out);
    s.printe(f);
    f.close();

    return 0;
}
