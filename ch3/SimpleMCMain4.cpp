#include<SimpleMC2.h>
#include<iostream>
#include<memory>

int main3()
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

    unsigned long optionType{0};

    std::cout << "\nenter 0 for a call, other wise it's a put ";
    std::cin >> optionType;

    // PayOff* thePayOffPtr; // uses a pointer
    std::unique_ptr<PayOff> thePayOffPtr; // uses a smart pointer instead

    if (optionType == 0)
    {
        thePayOffPtr = std::make_unique<PayOffCall>(Strike);
    } else {
        thePayOffPtr = std::make_unique<PayOffPut>(Strike);
    }

    double result{SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r,
                                        NumberOfPaths)};

    std::cout << "\nthe price is " << result << "\n";
    double tmp;
    std::cin >> tmp;

    return 0;
}
