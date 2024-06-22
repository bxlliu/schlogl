#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include <PayOff1_ex.h>

double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double Expiry, double Spot, double Vol,
                        double r, unsigned long NumberOfPaths);

#endif
