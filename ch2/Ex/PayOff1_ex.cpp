#include <PayOff1_ex.h>
#include <algorithm>
#include <stdexcept>

PayOff::PayOff(double Strike1_, double Strike2_, OptionType TheOptionsType_):
            Strike1(Strike1_), Strike2(Strike2_), TheOptionsType(TheOptionsType_)
{

}

double PayOff::operator ()(double spot) const
// the operator part allows us to use the PayOff instance like a function
{
    double lowerStrike{std::min(Strike1, Strike2)};
    double upperStrike{std::max(Strike1, Strike2)};
    switch (TheOptionsType)
    {
        case call:
            return std::max(spot-Strike1, 0.0);
        
        case put:
            return std::max(Strike1-spot, 0.0);

        case digitalcall:
            return spot-Strike1 > 0 ? 1 : 0;

        case digitalput:
            return Strike1-spot > 0 ? 1 : 0;

        case doubledigital:
            return ((upperStrike - spot > 0) 
                            && (spot - lowerStrike > 0)) ? 1 : 0;

        default:
            throw std::invalid_argument("unknown option type found.");
    }
}
