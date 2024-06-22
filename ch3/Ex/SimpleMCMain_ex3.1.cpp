#include<SimpleMC2.h>
#include<iostream>
#include<memory>
#include<PowerOption.h>

int main1()
{
    double Expiry{0};
    double Strike{0};
    double Power{0};
    double Spot{0};
    double Vol{0};
    double r{0};
    unsigned long NumberOfPaths{0};
    std::cout << "\nEnter Expiry\n";
    std::cin >> Expiry;

    std::cout << "\nEnter Strike\n";
    std::cin >> Strike;

    std::cout << "\nEnter Power\n";
    std::cin >> Power;

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    PayOffPowerCall thePayOffCall(Strike, Power);
    PayOffPowerPut thePayOffPut(Strike, Power);

    double resultCall{SimpleMonteCarlo2(thePayOffCall, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    double resultPut{SimpleMonteCarlo2(thePayOffPut, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    std::cout << "\nthe call price is " << resultCall << "\n";
    std::cout << "the put price is " << resultPut << "\n";
    double tmp;
    std::cin >> tmp;

    return 0;
}
