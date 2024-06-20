#ifndef SIMPLEMCMAIN1_H
#define SIMPLEMCMAIN1_H

double SimpleMonteCarlo1(double Expiry, double Strike,
                        double Spot, double Vol, double r,
                        unsigned long NumberOfPaths);

int main();

#endif