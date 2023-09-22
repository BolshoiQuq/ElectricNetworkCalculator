
#ifndef TEXTCALC_H
#define TEXTCALC_H

#include <iostream>




class textcalc
{
public:
    textcalc();
};

void enet_calc(double Ee, double nu, double phi0, double t, std::string in);
std::string enet_graph(double Ee, double nu, double phi0, int k, std::string in);

#endif // TEXTCALC_H
