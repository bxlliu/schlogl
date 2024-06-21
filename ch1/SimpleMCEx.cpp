// MCSim the option pricing

#include <SimpleMCEx.h>
#include <algorithm>
#include <Random1.h>
#include <iostream>
#include <cmath>
#include <stdexcept>

double CalcPayoff(std::string optionType, double Spot, 
                    double Strike1, double Strike2 = 0)
{
    double thisPayoff{0};
    if (optionType == "CALL")
    {
        thisPayoff = Spot - Strike1;
    }
    else if (optionType == "PUT")
    {
        thisPayoff = Strike1 - Spot;
    }
    else if (optionType == "DD")
    {
        double lowerStrike{std::min(Strike1, Strike2)};
        double upperStrike{std::max(Strike1, Strike2)};
        thisPayoff = (upperStrike - Spot > 0) 
                        && (Spot - lowerStrike > 0) ? 1 : 0;
    }
    else
    {
        throw std::invalid_argument("invalid option type");
    }
    thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
    return thisPayoff;
}

double GenMC(std::string optionType, double Spot, double Vol, 
                        double r, double Expiry, unsigned long NumberOfPaths, 
                        double Strike1, double Strike2 = 0)
{   
    if(!(optionType == "PUT" || optionType == "CALL" || optionType == "DD"))
    {
        throw std::invalid_argument("invalid option type");
    }
    double variance{Vol * Vol * Expiry};
    double rootVariance{std::sqrt(variance)};
    double itoCorrection{-0.5 * variance};

    double movedSpot{Spot * std::exp(r * Expiry + itoCorrection)};
    double thisSpot{0};
    double runningSum{0};

    for (unsigned long i{0}; i < NumberOfPaths; ++i)
    {
        thisSpot = movedSpot * std::exp(rootVariance * GetOneGaussianByBoxMuller());
        double thisPayoff{CalcPayoff(optionType, thisSpot, Strike1, Strike2)};
        runningSum += thisPayoff;
    }

    double mean{runningSum / static_cast<double>(NumberOfPaths)};
    mean *= std::exp(-r * Expiry);
    return mean;
}

double GenCaller(std::string optionType)
{
    double Expiry{0};
    double Strike1{0};
    double Strike2{0};
    double Spot{0};
    double Vol{0};
    double r{0};
    unsigned long NumberOfPaths{0};

    std::cout << "\nEnter Expiry\n";
    std::cin >> Expiry;

    std::cout << "\nEnter Strike\n";
    std::cin >> Strike1;

    if(optionType == "DD")
    {
        std::cout << "\nEnter Strike 2\n";
        std::cin >> Strike2;
    }

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    return GenMC(optionType, Spot, Vol, r, Expiry, 
                    NumberOfPaths, Strike1, Strike2);
}

int main()
{
    std::string optionType{"na"};

    std::cout << "\nOption Type\n";
    std::cin >> optionType;
    std::transform(optionType.begin(), optionType.end(),
                    optionType.begin(), ::toupper);
    double optPrice{0};

    if(optionType == "PUT" || optionType == "CALL" || optionType == "DD")
    {
        optPrice = GenCaller(optionType);
    }
    else
    {
        std::cerr << "invalid optionType";
        return 1;
    }

    std::cout << "\nThe " << optionType << " option price is " << optPrice << "\n";
    return 0;
}
