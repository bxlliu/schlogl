#include<Vanilla2.h>
#include<SimpleMC4.h>
#include<iostream>
#include<DoubleDigital2.h>

int main()
{
    double Expiry{0};
    double Vol{0};
    double Strike{0};
    double r{0};
    double Spot{0};
    unsigned long NumberOfPaths{0};

    std::cout << "\nEnter expiry\n";
    std::cin >> Expiry;
    
    std::cout << "\nEnter strike\n";
    std::cin >> Strike;

    std::cout << "\nEnter spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

    double result{SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths)};

    std::cout << "\nthe call price is " << result << "\n";

    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo3(secondOption, Spot, Vol, r, NumberOfPaths);
    std::cout << "\nthe second call price is " << result << "\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);
    std::cout << "\nthe put price is " << result << "\n";

    double tmp;
    std::cin >> tmp;
    return 0;
}
