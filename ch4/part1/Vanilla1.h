#ifndef VANILLA1_H
#define VANILLA1_H

#include<PayOff2.h>

class VanillaOption
{
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    PayOff& ThePayOff;
    double Expiry;
};

#endif
