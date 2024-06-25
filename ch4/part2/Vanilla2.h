#ifndef VANILLA2_H
#define VANILLA2_H

#include<PayOff3.h>

class VanillaOption
{
public:
    VanillaOption(const PayOff& ThePayOff_, double Expiry_);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption& original);
    ~VanillaOption();

    double OptionPayOff(double Spot) const;
    double GetExpiry() const;

private:
    PayOff* ThePayOffPtr;
    double Expiry;
};

#endif
