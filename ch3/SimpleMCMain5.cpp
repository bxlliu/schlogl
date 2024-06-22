#include<SimpleMC2.h>
#include<iostream>
#include<memory>
#include<DoubleDigital.h>

int main()
{
    double Expiry{0};
    double UpperStrike{0};
    double LowerStrike{0};
    double Spot{0};
    double Vol{0};
    double r{0};
    unsigned long NumberOfPaths{0};
    std::cout << "\nEnter Expiry\n";
    std::cin >> Expiry;

    std::cout << "\nEnter Lower Strike\n";
    std::cin >> LowerStrike;

    std::cout << "\nEnter Upper Strike\n";
    std::cin >> UpperStrike;

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(LowerStrike, UpperStrike);

    double result{SimpleMonteCarlo2(thePayOff, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    std::cout << "\nthe price is " << result << "\n";
    double tmp;
    std::cin >> tmp;

    return 0;
}
