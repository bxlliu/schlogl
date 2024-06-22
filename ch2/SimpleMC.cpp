#include <SimpleMC.h>
#include <Random1.h>
#include <cmath>

double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double Expiry, double Spot, double Vol,
                        double r, unsigned long NumberOfPaths)
{
    double variance{Vol*Vol*Expiry};
    double rootVariance{std::sqrt(variance)};
    double itoCorrection{-0.5*variance};

    double movedSpot{Spot*std::exp(r*Expiry + itoCorrection)};
    double thisSpot{0};
    double runningSum{0};

    for (unsigned long i{0}; i < NumberOfPaths; ++i)
    {
        double thisGaussian{GetOneGaussianByBoxMuller()};
        thisSpot = movedSpot*std::exp(rootVariance * thisGaussian);
        double thisPayOff{thePayOff(thisSpot)};
        runningSum += thisPayOff;
    }
    double mean{runningSum / static_cast<double>(NumberOfPaths)};
    mean *= std::exp(-r*Expiry);
    return mean;
}
