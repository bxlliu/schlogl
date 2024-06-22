#ifndef POWEROPTION_H
#define POWEROPTION_H

#include<PayOff2.h>

class PayOffPowerCall : public PayOff
{
public:
    PayOffPowerCall(double Strike_, double Power_);
    virtual double operator() (double Spot) const;
    virtual ~PayOffPowerCall(){}

private:
    double Strike;
    double Power;
};

class PayOffPowerPut : public PayOff
{
public:
    PayOffPowerPut(double Strike_, double Power_);
    virtual double operator() (double Spot) const;
    virtual ~PayOffPowerPut(){}

private:
    double Strike;
    double Power;
};

#endif
