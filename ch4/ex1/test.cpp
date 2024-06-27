
#include<iostream>
#include<ctime>

int main1()
{
    std::clock_t t{std::clock()};


    for (int i{0}; i < 10000; ++i)
    {
        double* tmpDbl = new double[]{1,2,3};
        if(i == 9999){
            std::cout << tmpDbl << "\n";
        }
    }
    t = std::clock() - t;

    std::cout << t << "\n";
    //std::cout << tmpDbl;
    return 0;

}

// Note: auto_ptr has been removed as of C++17
