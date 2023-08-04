#include <iostream>
#include <cmath>

using namespace std;

struct Element
{
    double R = 0.0;
    double U = 0.0;
    double I = 0.0;
    double ν = 0.0;
    double φ = 0.0;
};

struct CurrentSource : Element
{
    double ℰ = 0.0;
    CurrentSource (double ℰ, double R)
    {
        this->ℰ = ℰ;
        this->R = R;
        this->U = ℰ;
        this->ν = 0.0;
        this->φ = 0.0;
    }
    CurrentSource (double ℰ, double R, double ν, double φ)
        {
            this->ℰ = ℰ;
            this->R = R;
            this->U = ℰ;
            this->ν = ν;
            this->φ = φ;
        }
    double rad() const override
    {
        return abs(x);
    }
};

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

int main() {
    OneDimPoint a{-3};
    TwoDimPoint b{3, -4};
    ThreeDimPoint c{-3, 4, -12};
    OneDimPoint d;
    printL(a);
    printL(b);
    printL(c);
    printL(d);
    return 0;
}
