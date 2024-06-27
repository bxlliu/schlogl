#ifndef PIECEWISEPARAMETERS_H
#define PIECEWISEPARAMETERS_H

#include<vector>

class PiecewiseParameters
{
public:
    PiecewiseParameters() = default;
    PiecewiseParameters(const PiecewiseParameters& original);
    PiecewiseParameters& operator=(const PiecewiseParameters& original);
    PiecewiseParameters* clone() const;

    void addValue(double time, double value);
    double getValue(double time) const;

    virtual ~PiecewiseParameters() = default;

private:
    PiecewiseParameters* PiecewiseParameter_ptr;
    std::vector<double> timeVec;
    std::vector<double> valueVec;
};

#endif
