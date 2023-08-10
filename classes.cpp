#include <iostream>
#include <cmath>
#include <vector>

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
};


int main() {
    double Ee=1.0, nu=0.0, phi0=0.0;
    Series s;
    Parallel p;

    s.push(new Resistor{1.0});
    s.push(new Resistor{3.0});
    s.push(new Resistor{7.0});

    p.push(new Resistor{1.0});
    p.push(new Resistor{3.0});
    p.push(new Resistor{7.0});
    s.push(&p);
    s.setU(Ee);
    cout << s.Rm() << " " << s.Um() << " " << s.Im() << endl;
    cout << (*(*s.v[3]).v[2]).Im() << endl;
 /*   cout << (*s.v[0]).Rm() << endl;
    cout << s.Rm() << endl;
    cout << p.Rm() << endl;
    cout << (*p.v[3]).Rm() << endl; */

    return 0;
}
