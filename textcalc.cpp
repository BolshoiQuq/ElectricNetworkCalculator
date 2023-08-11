#include <iostream>
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

    virtual void read()
    {
    }

    virtual void print()
    {
        cout << "E()";
    }

    virtual void printe()
    {
        cout << "E()";
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

    void print() override
    {
        cout << "R(" << R << ")\n";
    }

    void printe() override
    {
        cout << "R(" << R << ";" << U << ";" << I << ")\n";
    }
};

struct Lamp : Resistor
{
    double W = inf;
    double l = 0.0;

    Lamp (double R, double W) : Resistor(R)
    {
        this->W = W;
    }

    void setU(double U) override
    {
        this->U=U;
        this->I=U/R;
        l=this->U*this->I/W;
        if (l>1)
            R=inf;
    }

    void setI(double I) override
    {
        this->U=I*R;
        this->I=I;
        l=this->U*this->I/W;
        if (l>1)
            R=inf;
    }

    void print() override
    {
        cout << "L(" << R << ";" << W << ")\n";
    }

    void printe() override
    {
        cout << "L(" << R << ";" << U << ";" << I << ";" << W << ";" << l << ")\n";
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

    void read() override;

    void print() override
    {
        cout << "[\n";
        for (Element* e : v)
            e->print();
        cout << "]\n";
    }

    void printe() override
    {
        cout << "[\n";
        for (Element* e : v)
            e->printe();
        cout << "]\n";
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

    void read() override;

    void print() override
    {
        cout << "{\n";
        for (Element* e : v)
            e->print();
        cout << "}\n";
    }

    void printe() override
    {
        cout << "{\n";
        for (Element* e : v)
            e->printe();
        cout << "}\n";
    }
};

void Series::read()
{
    char c;
    cin >> c;
    if (c=='R')
    {
        double R;
        cin >> c;
        cin >> R;
        push(new Resistor{R});
        cin >> c;
        read();
    } else
    if (c=='[')
    {
        push(new Series);
        (*v.back()).read();
        read();
    } else
    if (c=='{')
    {
        push(new Parallel);
        (*v.back()).read();
        read();
    } else
    if (c==']')
    {
        return;
    }
    return;
}


void Parallel::read()
{
    char c;
    cin >> c;
    if (c=='R')
    {
        double R;
        cin >> c;
        cin >> R;
        push(new Resistor{R});
        cin >> c;
        read();
    } else
    if (c=='[')
    {
        push(new Series);
        (*v.back()).read();
        read();
    } else
    if (c=='{')
    {
        push(new Parallel);
        (*v.back()).read();
        read();
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

    cin >> Ee;
    cin >> c;
    if (c=='[')
        s.read();

    s.setU(Ee);
    s.printe();

    return 0;
}
