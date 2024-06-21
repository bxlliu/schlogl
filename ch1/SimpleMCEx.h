#ifndef SIMPLEMCEX_H
#define SIMPLEMCEX_H

#include <iostream>

double VanillaMC(double Expiry, double Strike,
                        double Spot, double Vol, double r,
                        unsigned long NumberOfPaths, std::string optionType);
double VanillaCaller(std::string optionType);
double CalcPayoff(std::string optionType, double Spot, 
                    double Strike1, double Strike2);
double GenMC(std::string optionType, double Spot, double Vol, 
                        double r, double Expiry, unsigned long NumberOfPaths, 
                        double Strike1, double Strike2);
double GenCaller(std::string optionType);
int main();

#endif
