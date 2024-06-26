#include<Vanilla3.h>
#include<SimpleMC6.h>
#include<cmath>
#include<Random1.h>
#include<Parameters.h>

double SimpleMonteCarlo4(const VanillaOption& TheOption, double Spot, 
                        const Parameters& Vol, const Parameters& r, 
                        unsigned long NumberOfPaths)
{
    double Expiry{TheOption.GetExpiry()};

    double variance{Vol.IntegralSquare(0,Expiry)};
    double rootVariance{std::sqrt(variance)};
    double itoCorrection{-0.5*variance};

    double movedSpot{Spot*std::exp(r.Integral(0,Expiry) + itoCorrection)};
    double thisSpot{0};
    double runningSum{0};

    for (unsigned long i{0}; i < NumberOfPaths; ++i)
    {
        double thisGaussian{GetOneGaussianByBoxMuller()};
        thisSpot = movedSpot*std::exp(rootVariance*thisGaussian);
        double thisPayOff{TheOption.OptionPayOff(thisSpot)};
        runningSum += thisPayOff;
    }

    double mean{runningSum / static_cast<double>(NumberOfPaths)};
    mean *= std::exp(-r.Integral(0,Expiry));
    return mean;
}
