#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int t=0;

struct Element
{
    virtual double Res()
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

    Resistor (double R)
    {
        this->R = R;
    }

    double Res() override
    {
        return R;
    }
};
/*
struct CurrentSource : Resistor
{
    double R = 0.0;
    double U = 0.0;
    double I = 0.0;
    double nu = 0.0;
    double phi = 0.0;
    double Ee = 0.0;
    CurrentSource (double Ee, double R)
    {
        this->Ee = Ee;
        this->R = R;
        this->U = Ee;
        this->nu = 0.0;
        this->phi = 0.0;
    }
    CurrentSource (double Ee, double R, double nu, double phi)
        {
            this->Ee = Ee;
            this->R = R;
            this->U = Ee;
            this->nu = nu;
            this->phi = phi;
        }
    double phase()
    {
        return 2*pi*nu*t+phi;
    }

    double u()
    {
        return U*sin(2*pi*nu*t+phi);
    }

    double Res()
    {
        return R;
    }
};

*/
struct Series : Element
{
    vector<Element> v;

    Series ()
    {
        v.resize(0);
    }

    void push(Element e)
    {
        v.push_back(e);
    }

    double Res() override
    {
        double R=0.0;
        for (Element e : v)
            R+=e.Res();
        return R;
    }
};

/*
class TwoDimPoint : public Point
{
public:
    double x;
    double y;
    TwoDimPoint (double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    TwoDimPoint ()
    {
        this->x = 0;
        this->y = 0;
    }
    double rad() const override
    {
        return sqrt(x*x+y*y);
    }
};

class ThreeDimPoint : public Point
{
public:
    double x;
    double y;
    double z;
    ThreeDimPoint (double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ThreeDimPoint ()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    double rad() const override
    {
        return sqrt(x*x+y*y+z*z);
    }
};

void printL (const Point& l)
{
    cout << l.rad() << endl;
}
*/
int main() {
   /* OneDimPoint a{-3};
    TwoDimPoint b{3, -4};
    ThreeDimPoint c{-3, 4, -12};
    OneDimPoint d;*/
    Series s;

    Resistor r1{1.0};
    Resistor r2{3.0};
    s.push(r1);
    s.push(r2);
    s.push(Resistor{7.0});
    cout << s.v[0].Res() << endl;
    cout << s.v[1].Res() << endl;
    cout << s.v[2].Res() << endl;
    cout << r1.R << endl;
    cout << r2.R << endl;
 /*   printL(a);
    printL(b);
    printL(c);
    printL(d);*/
    return 0;
}
