#ifndef PAYOFF1_EX_H
#define PAYOFF1_EX_H

class PayOff
{
public:
    enum OptionType{call, put, digitalcall, digitalput, doubledigital};
    PayOff(double Strike1_, double Strike2_, OptionType TheOptionsType_);
    double operator()(double Spot) const;

private:
    double Strike1;
    double Strike2;
    OptionType TheOptionsType;
};

#endif
