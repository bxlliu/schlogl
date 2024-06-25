#include<Vanilla1.h>
#include<SimpleMC3.h>
#include<iostream>
#include<DoubleDigital.h>

int main1()
{
    double Expiry{0};
    double Vol{0};
    double Low{0};
    double Up{0};
    double r{0};
    double Spot{0};
    unsigned long NumberOfPaths{0};

    std::cout << "\nEnter expiry\n";
    std::cin >> Expiry;
    
    std::cout << "\nEnter low barrier\n";
    std::cin >> Low;

    std::cout << "\nEnter upper barrier\n";
    std::cin >> Up;

    std::cout << "\nEnter spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low,Up);
    VanillaOption theOption(thePayOff, Expiry);

    double result{SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths)};

    std::cout << "\nthe price is " << result << "\n";
    double tmp;
    std::cin >> tmp;
    return 0;
}
