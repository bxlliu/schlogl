#ifndef VANILLA3_H
#define VANILLA3_H

#include<PayOff3.h>
#include<PayOffBridge.h>

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);

    double OptionPayOff(double Spot) const;
    double GetExpiry() const;

private:
    PayOffBridge ThePayOff;
    double Expiry;
};

#endif
