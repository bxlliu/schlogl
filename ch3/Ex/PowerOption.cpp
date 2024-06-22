#include<PowerOption.h>
#include<cmath>
#include<algorithm>

PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_) : 
                                    Strike(Strike_), Power(Power_){}

double PayOffPowerCall::operator() (double Spot) const
{
    return std::max(std::pow(Spot, Power) - Strike, 0.0);
}

PayOffPowerPut::PayOffPowerPut(double Strike_, double Power_) : 
                                Strike(Strike_), Power(Power_){}

double PayOffPowerPut::operator() (double Spot) const
{
    return std::max(Strike - std::pow(Spot, Power), 0.0);
}

