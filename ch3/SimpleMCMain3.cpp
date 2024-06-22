#include<SimpleMC2.h>
#include<iostream>

int main2()
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

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    double resultCall{SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    double resultPut{SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    std::cout << "the prices are "  << resultCall << " for the call, "
                                    << resultPut << " for the put"
                                    << "\n";

    double tmp;
    std::cin >> tmp;

    return 0;
}
