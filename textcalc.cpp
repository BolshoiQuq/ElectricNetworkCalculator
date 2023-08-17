#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <complex>

using namespace std;

int t=0;
const double inf=1.7976931348623157E+308;
const double pi=3.14159265358979323846264338;

struct Element
{
    vector<Element*> v;

    virtual void setU(complex<double> U, double nu)
    {
    }

    virtual void setU(complex<double> U)
    {
    }

    virtual void setI(complex<double> I, double nu)
    {
    }

    virtual void setI(complex<double> I)
    {
    }

    virtual double Rq()
    {
        return 0;
    }

    virtual double Xq(double nu)
    {
        return 0;
    }

    virtual complex<double> Zq(double nu)
    {
        return 0;
    }

    virtual complex<double> Uq()
    {
        return 0;
    }

    virtual complex<double> Iq()
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
    complex<double> U = 0.0;
    complex<double> I = 0.0;

    Resistor (double R)
    {
        this->R = R;
    }

    void setU(complex<double> U) override
    {
        this->U=U;
        this->I=U/R;
    }

    void setU(complex<double> U, double nu) override
    {
        setU(U);
    }

    void setI(complex<double> I) override
    {
        this->U=I*R;
        this->I=I;
    }

    void setI(complex<double> I, double nu) override
    {
        setI(I);
    }

    double Rq() override
    {
        return R;
    }

    double Xq(double nu) override
    {
        return 0;
    }

    complex<double> Zq(double nu) override
    {
        return R;
    }

    complex<double> Uq() override
    {
        return U;
    }

    complex<double> Iq() override
    {
        return I;
    }

    void print(ostream &ost) override
    {
        ost << "R(" << R << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "R(" << R << ";" << U.real() << ";" << I.real() << ")\n";
    }
};

/*struct Bulb : Resistor
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
};*/

struct Capacitor : Resistor
{
    double C = 0.0;

    Capacitor (double R, double C) : Resistor(R)
    {
        this->C = C;
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setU(complex<double> U, double nu) override
    {
        this->U=U;
        this->I=U/Zq(nu);
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        this->U=I*Zq(nu);
        this->I=I;
    }

    double Xq(double nu)
    {
        if (nu!=0)
            return -1/(2*pi*nu*C);
        else
            return -inf;
    }

    complex<double> Zq(double nu)
    {
        return (Rq(), Xq(nu));
    }

    void print(ostream &ost) override
    {
        ost << "C(" << R << ";" << C << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "B(" << R << ";" << U.real() << ";" << I.real() << ";" << C << ")\n";
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

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setU(complex<double> U, double nu) override
    {
        complex<double> I=U/Zq(nu);
        setI(I);
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        for (Element* e : v)
            e->setI(I, nu);
    }

    double Rq() override
    {
        double R=0.0;
        for (Element* e : v)
            R+=e->Rq();
        return R;
    }

    double Xq(double nu) override
    {
        double X=0.0;
        for (Element* e : v)
            X+=e->Xq(nu);
        return X;
    }

    complex<double> Zq(double nu) override
    {
        complex<double> Z=0.0;
        for (Element* e : v)
            Z+=e->Zq(nu);
        return Z;
    }

    complex<double> Uq() override
    {
        complex<double> U=0.0;
        for (Element* e : v)
            U+=e->Uq();
        return U;
    }

    complex<double> Iq() override
    {
        return v[0]->Iq();
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

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setU(complex<double> U, double nu) override
    {
        for (Element* e : v)
            e->setU(U, nu);
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        complex<double> U=I*Zq(nu);
        setU(U, nu);
    }

    double Rq() override
    {
        double G=0.0;
        for (Element* e : v)
            G+=(1/e->Rq());
        return 1/G;
    }

    complex<double> Zq(double nu) override
    {
        complex<double> Y=0.0;
        for (Element* e : v)
            Y+=(complex<double>(1, 0)/e->Zq(nu));
        return complex<double>(1, 0)/Y;
    }

    complex<double> Uq() override
    {
        return v[0]->Uq();
    }

    complex<double> Iq() override
    {
        complex<double> I=0.0;
        for (Element* e : v)
            I+=e->Iq();
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
    double Ee=1.0, nu=0.0, phi0=0.0, t;
    char c;
    Series s;
    fstream f;
    string in, out;

    cout << "Choose input file\n";
    cin >> in;

    cout << "Enter EMF\n";
    cin >> Ee;

    cout << "Enter frequence\n";
    cin >> nu;

    cout << "Enter basic phase\n";
    cin >> phi0;

    cout << "Enter time\n";
    cin >> t;

    cout << "Choose output file\n";
    cin >> out;

    f.open(in, ios::in);
    f >> c;
    if (c=='[')
        s.read(f);
    f.close();

    complex<double> U=Ee*exp(complex<double>(0, 1)*(2*pi*nu*t+phi0));
    s.setU(U, nu);

    f.open(out, ios::out);
    s.printe(f);
    f.close();

    return 0;
}
