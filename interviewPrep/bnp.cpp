#include <iostream>
#include <vector>
#include <algorithm>

#include "bnp.h"

using namespace std;

namespace bnp
{
    void bnp()
    {
        vector<double> xv, yv;

        xv.push_back(1.0);
        xv.push_back(3.0);
        xv.push_back(5.0);

        yv.push_back(1.0);
        yv.push_back(3.0);
        yv.push_back(1.0);

        double testx[] = { 0.0, 2.0, 4.0, 6.0 };
        double testy[] = { 0.0, 2.0, 2.0, 0.0 };

        for (int i=0; i<4; ++i)
        {
            double y=linear(xv, yv, testx[i]);
            cout << "x: " << testx[i] <<
                " y: " << y <<
                " (Expected y: " << testy[i] <<
                ")" << endl;
        }
    }

    double linear(const vector<double>& x_vec, const vector<double>& y_vec, double x)
    {
        // Assumptions
        // 1. x_vec and y_vec have the same length l >= 2
        // 2. x_vec is ordered, and all points are unique

        // (A) find m and b such that y = m*x + b
        //
        // cit := first element in x_vec that is >= x

        vector<double>::const_iterator l, r;
        vector<double>::const_iterator cit=lower_bound(x_vec.begin(), x_vec.end(), x);
        if (cit==x_vec.end())
        {
            // x is further right than the rightmost point
            r=cit-1;
            l=r-1;
        }
        else if (*cit==x)
        {
            return y_vec[cit-x_vec.begin()];
        }
        else if (cit==x_vec.begin())
        {
            // x is further left than the leftmost point
            l=cit;
            r=l+1;
        }
        else
        {
            r=cit;
            l=r-1;
        }

        double x1=*r, x0=*l;
        const int idx=l-x_vec.begin();
        double y1=y_vec[idx+1], y0=y_vec[idx];

        // m = (y1-y0)/(x1-x0)
        // y = m*x + y0-m*x0
        //
        double m=(y1-y0)/(x1-x0);
        double b=y0-m*x0;

        // (B) return y
        return m*x+b;
    }

    char* itoa(int num, char* str, int base)
    {
        // ...
        return 0;
    }

    int dateDiff(const std::string& from, const std::string& to, bool weekend)
    {
        // ...
        return 0;
    }
}
