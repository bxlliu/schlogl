#include <PayOff1.h>
#include <algorithm>
#include <stdexcept>

PayOff::PayOff(double Strike_, OptionType TheOptionsType_):Strike(Strike_),
            TheOptionsType(TheOptionsType_)
{

}

double PayOff::operator ()(double spot) const
// the operator part allows us to use the PayOff instance like a function
{
    switch (TheOptionsType)
    {
        case call:
            return std::max(spot-Strike, 0.0);
        
        case put:
            return std::max(Strike-spot, 0.0);

        case digitalcall:
            return spot-Strike > 0 ? 1 : 0;

        default:
            throw std::invalid_argument("unknown option type found.");
    }
}
