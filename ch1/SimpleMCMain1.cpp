// MCSim the option pricing

// #include <SimpleMCMain1.h>
#include <Random1.h>
#include <iostream>
#include <cmath>

double SimpleMonteCarlo1(double Expiry, double Strike,
                        double Spot, double Vol, double r,
                        unsigned long NumberOfPaths)
    // This is a MC pricer for a Euro Call
{   
    double variance{Vol * Vol * Expiry};
    double rootVariance{std::sqrt(variance)};
    double itoCorrection{-0.5 * variance};

    double movedSpot{Spot * std::exp(r * Expiry + itoCorrection)};
    double thisSpot{0};
    double runningSum{0};

    for (unsigned long i{0}; i < NumberOfPaths; ++i)
    {
        thisSpot = movedSpot * std::exp(rootVariance * GetOneGaussianByBoxMuller());
        double thisPayoff{thisSpot - Strike};
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean{runningSum / static_cast<double>(NumberOfPaths)};
    mean *= std::exp(-r * Expiry);
    return mean;
}

int main_og()
// changed the function name ; if you want to run this change it back
{
    double Expiry{0};
    double Strike{0};
    double Spot{0};
    double Vol{0};
    double r{0};
    unsigned long NumberOfPaths{0};
    std::cout << "\nEnter Expiry\n";
    std::cin >> Expiry;

    std::cout << "\nEnter Strike\n";
    std::cin >> Strike;

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    double result{ SimpleMonteCarlo1(Expiry, 
                                    Strike, 
                                    Spot, 
                                    Vol, 
                                    r, 
                                    NumberOfPaths)};
    
    std::cout << "\nThe option price is " << result << "\n";

    double tmp{0};
    std::cout << "\nType anything to continue\n";
    std::cin >> tmp;

    return 0;
}

