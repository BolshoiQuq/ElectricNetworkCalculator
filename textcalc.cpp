#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <complex>
#include <QDebug>

using namespace std;

const double inf=1.7976931348623157E+308;
const double pi=3.1415926E+0;
const complex<double> i0(1,0);
const complex<double> i(0,1);

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

    virtual void printea(ostream &ost)
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

    void setU(complex<double> U, double nu) override
    {
        this->U=U;
        this->I=U/R;
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        this->U=I*R;
        this->I=I;
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
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
        ost << "R(" << R << " Ω; " << U.real() << " V; " << I.real() << " A)\n";
    }

    void printea(ostream &ost) override
    {
        ost << "R(" << U.real() << ";" << I.real() << ")\n";
    }
};

struct Capacitor : Resistor
{
    double C = 0.0;

    Capacitor (double R, double C) : Resistor(R)
    {
        this->C = C;
    }

    void setU(complex<double> U, double nu) override
    {
        this->U=U;
        this->I=U/Zq(nu);
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        this->U=I*Zq(nu);
        this->I=I;
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
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
        return complex<double>(Rq(), Xq(nu));
    }

    void print(ostream &ost) override
    {
        ost << "C(" << R << ";" << C << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "C(" << R << " Ω; " << C << " F; " << U.real() << " V; " << I.real() <<" A)\n";
    }

    void printea(ostream &ost) override
    {
        ost << "C(" << U.real() << ";" << I.real() <<")\n";
    }
};

struct Inductor : Resistor
{
    double L = 0.0;

    Inductor (double R, double L) : Resistor(R)
    {
        this->L = L;
    }

    void setU(complex<double> U, double nu) override
    {
        this->U=U;
        this->I=U/Zq(nu);
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        this->U=I*Zq(nu);
        this->I=I;
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
    }

    double Xq(double nu)
    {
        return 2*pi*nu*L;
    }

    complex<double> Zq(double nu)
    {
        return complex<double>(Rq(), Xq(nu));
    }

    void print(ostream &ost) override
    {
        ost << "L(" << R << ";" << L << ")\n";
    }

    void printe(ostream &ost) override
    {
        ost << "L(" << R << " Ω; " << L << " H; " << U.real() << " V; " << I.real() <<" A)\n";
    }

    void printea(ostream &ost) override
    {
        ost << "L(" << U.real() << ";" << I.real() <<")\n";
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

    void setU(complex<double> U, double nu) override
    {
        complex<double> I=U/Zq(nu);
        setI(I, nu);
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        for (Element* e : v)
            e->setI(I, nu);
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
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

    void printea(ostream &ost) override
    {
        ost << "[\n";
        for (Element* e : v)
            e->printea(ost);
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

    void setU(complex<double> U, double nu) override
    {
        for (Element* e : v)
            e->setU(U, nu);
    }

    void setU(complex<double> U) override
    {
        setU(U, 0);
    }

    void setI(complex<double> I, double nu) override
    {
        complex<double> U=I*Zq(nu);
        setU(U, nu);
    }

    void setI(complex<double> I) override
    {
        setI(I, 0);
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
            Y+=(i0/e->Zq(nu));
        return i0/Y;
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

    void printea(ostream &ost) override
    {
        ost << "{\n";
        for (Element* e : v)
            e->printea(ost);
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
        if (c=='C')
        {
            double R, C;
            ist >> c;
            ist >> R;
            ist >> c;
            ist >> C;
            push(new Capacitor{R, C});
            ist >> c;
            read(ist);
        } else
            if (c=='L')
            {
                double R, L;
                ist >> c;
                ist >> R;
                ist >> c;
                ist >> L;
                push(new Inductor{R, L});
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
        if (c=='C')
        {
            double R, C;
            ist >> c;
            ist >> R;
            ist >> c;
            ist >> C;
            push(new Capacitor{R, C});
            ist >> c;
            read(ist);
        } else
            if (c=='L')
            {
                double R, L;
                ist >> c;
                ist >> R;
                ist >> c;
                ist >> L;
                push(new Inductor{R, L});
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

void enet_calc(double Ee, double nu, double phi0, double t, std::string in) {
    char c;
    Series s;
    fstream f;
    string out="nout_calc.txt";

    f.open(in, ios::in);
    f >> c;
    if (c=='[')
        s.read(f);
    f.close();

    complex<double> U=Ee*exp(i*(2*pi*nu*t+phi0));
    s.setU(U, nu);

    f.open(out, ios::out);
    s.printe(f);
    f.close();
}

void enet_graph(double Ee, double nu, double phi0, int k, std::string in) {
    char c;
    Series s;
    fstream f;
    string med="nmed_graph.txt";

    f.open(in, ios::in);
    f >> c;
    if (c=='[')
        s.read(f);
    f.close();

    f.open(med, ios::out);
    for (int j=0; j<100; ++j)
    {
        double t;
        if (nu==0)
            t=double(j)/100.0;
        else
            t=double(j)/(100.0*nu);
        complex<double> U=Ee*exp(i*(2*pi*nu*t+phi0));
        s.setU(U, nu);
        s.printea(f);
    }
    f.close();

    int n=0;
    double U[100], I[100];
    string str, out_U="nout_graph_U.txt", out_I="nout_graph_I.txt";

    f.open(in, ios::in);
    while (!f.eof())
    {
        getline(f, str);
        ++n;
    }
    f.close();

    f.open(med, ios::in);
    for (int i=0; i<100; ++i)
    {
        for (int j=0; j<k; ++j)
            getline(f, str);
        f >> c;
        if (c=='[' or c==']' or c=='{' or c=='}')
        {
            U[i]=0;
            I[i]=0;
        } else
        if (c=='R' or c=='C' or c=='L')
        {
            f >> c;
            f >> U[i];
            f >> c;
            f >> I[i];
            f >> c;
        }
        for (int j=0; j<n-k; ++j)
            getline(f, str);
    }
    f.close();

    f.open(out_U, ios::out);
    for (int i=0; i<100; ++i)
    {
        f << 2*pi*i/100 << ";" << U[i] << "\n";
    }
    f << "------------------------\n";
    f.close();

    f.open(out_I, ios::out);
    for (int i=0; i<100; ++i)
    {

        f << 2*pi*i/100 << ";" << I[i] << "\n";
    }
    f << "------------------------\n";
    f.close();
}
