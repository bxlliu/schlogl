#include<SimpleMC2.h>
#include<iostream>
#include<memory>
#include<DoubleDigital.h>
#include<PayOff2.h>
#include<PowerOption.h>
#include<exception>

int main()
{
    double Expiry{0};
    double UpperStrike{0};
    double LowerStrike{0};
    double Power{0};
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

    unsigned long optionType{0};

    std::cout << "\nenter 0 for a call, 1 for put, 2 for double digital, ";
    std::cout << "3 for power call, 4 for power put\n";
    std::cin >> optionType;

    // PayOff* thePayOffPtr; // uses a pointer
    std::unique_ptr<PayOff> thePayOffPtr; // uses a smart pointer instead

    switch(optionType)
    {
        case 0:
            thePayOffPtr = std::make_unique<PayOffCall>(UpperStrike);
            break;

        case 1:
            thePayOffPtr = std::make_unique<PayOffPut>(UpperStrike);
            break;
        
        case 2:
            thePayOffPtr = std::make_unique<PayOffDoubleDigital>
                                            (LowerStrike, UpperStrike);
            break;

        case 3:
            thePayOffPtr = std::make_unique<PayOffPowerCall>
                                            (UpperStrike, Power);
            break;

        case 4:
            thePayOffPtr = std::make_unique<PayOffPowerPut>
                                            (UpperStrike, Power);
            break;

        default:
            std::cout << "invalid payoff";
            return 1;
    }

    double result{SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    std::cout << "\nthe price is " << result << "\n";
    double tmp;
    std::cin >> tmp;

    return 0;
}
