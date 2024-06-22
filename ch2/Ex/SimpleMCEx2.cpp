#include<SimpleMC.h>
#include<iostream>

int main()
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

    std::cout << "\nEnter First Strike\n";
    std::cin >> Strike1;

    std::cout << "\nEnter Second Strike\n";
    std::cin >> Strike2;

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Vol\n";
    std::cin >> Vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of Paths\n";
    std::cin >> NumberOfPaths;

    PayOff callPayOff(Strike1, Strike2, PayOff::call);
    PayOff putPayOff(Strike1, Strike2, PayOff::put);
    PayOff digitalCallPayOff(Strike1, Strike2, PayOff::digitalcall);
    PayOff digitalPutPayOff(Strike1, Strike2, PayOff::digitalput);
    PayOff doubleDigitalPayOff(Strike1, Strike2, PayOff::doubledigital);

    double resultCall{SimpleMonteCarlo2(callPayOff, Expiry,
                                        Spot, Vol, r, NumberOfPaths)};
    
    double resultPut{SimpleMonteCarlo2(putPayOff, Expiry,
                                        Spot, Vol, r, NumberOfPaths)};

    double resultDigitalCall{SimpleMonteCarlo2(digitalCallPayOff, Expiry,
                                        Spot, Vol, r, NumberOfPaths)};

    double resultDigitalPut{SimpleMonteCarlo2(digitalPutPayOff, Expiry,
                                        Spot, Vol, r, NumberOfPaths)};

    double resultDoubleDigital{SimpleMonteCarlo2(doubleDigitalPayOff, Expiry,
                                        Spot, Vol, r, NumberOfPaths)};

    std::cout << "The option prices are "   << resultCall 
                                            << " for the call, "
                                            << resultPut
                                            << " for the put, "
                                            << resultDigitalCall
                                            << " for the digital call, "
                                            << resultDigitalPut
                                            << " for the digital put, "
                                            << resultDoubleDigital
                                            << " for the double digital \n";
    double tmp;
    std::cin >> tmp;

    return 0;
}
