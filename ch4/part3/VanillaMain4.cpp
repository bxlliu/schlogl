#include<Vanilla3.h>
#include<SimpleMC6.h>
#include<iostream>
#include<Parameters.h>
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

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);

    double result{SimpleMonteCarlo4(theOption, Spot, VolParam, rParam, 
                                    NumberOfPaths)};

    std::cout << "\nthe call price is " << result << "\n";

    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo4(secondOption, Spot, VolParam, rParam, 
                                    NumberOfPaths);
    std::cout << "\nthe second call price is " << result << "\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo4(theOption, Spot, VolParam, rParam, 
                                    NumberOfPaths);
    std::cout << "\nthe put price is " << result << "\n";

    std::cout << "\n" << VolParam.Integral(0.5, 3.5) << "\n";

    double tmp;
    std::cin >> tmp;
    return 0;
}
