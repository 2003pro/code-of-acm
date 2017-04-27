#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double A[10];
bool judge(double x) {
    if (fabs(24.0 - x) < 1e-7)
        return true;
    return false;
}

bool hehe() {
    if (judge(A[0] + A[1] + A[2] + A[3])
        )return true;
    if (judge(A[0] + A[1] + A[2] - A[3])
        )return true;
    if (judge(A[0] + A[1] + A[2] * A[3])
        )return true;
    if (judge(A[0] + A[1] + A[2] / A[3])
        )return true;

    if (judge(A[0] + A[1] - A[2] + A[3])
        )return true;
    if (judge(A[0] + A[1] - A[2] - A[3])
        )return true;
    if (judge(A[0] + A[1] - A[2] * A[3])
        )return true;
    if (judge(A[0] + A[1] - A[2] / A[3])
        )return true;

    if (judge(A[0] + A[1] * A[2] + A[3])
        )return true;
    if (judge(A[0] + A[1] * A[2] - A[3])
        )return true;
    if (judge(A[0] + A[1] * A[2] * A[3])
        )return true;
    if (judge(A[0] + A[1] * A[2] / A[3])
        )return true;


    if (judge(A[0] + A[1] / A[2] + A[3])
        )return true;
    if (judge(A[0] + A[1] / A[2] - A[3])
        )return true;
    if (judge(A[0] + A[1] / A[2] * A[3])
        )return true;
    if (judge(A[0] + A[1] / A[2] / A[3])
        )return true;

    //16
    if (judge(A[0] - A[1] + A[2] + A[3])
        )return true;
    if (judge(A[0] - A[1] + A[2] - A[3])
        )return true;
    if (judge(A[0] - A[1] + A[2] * A[3])
        )return true;
    if (judge(A[0] - A[1] + A[2] / A[3])
        )return true;

    if (judge(A[0] - A[1] - A[2] + A[3])
        )return true;
    if (judge(A[0] - A[1] - A[2] - A[3])
        )return true;
    if (judge(A[0] - A[1] - A[2] * A[3])
        )return true;
    if (judge(A[0] - A[1] - A[2] / A[3])
        )return true;

    if (judge(A[0] - A[1] * A[2] + A[3])
        )return true;
    if (judge(A[0] - A[1] * A[2] - A[3])
        )return true;
    if (judge(A[0] - A[1] * A[2] * A[3])
        )return true;
    if (judge(A[0] - A[1] * A[2] / A[3])
        )return true;


    if (judge(A[0] - A[1] / A[2] + A[3])
        )return true;
    if (judge(A[0] - A[1] / A[2] - A[3])
        )return true;
    if (judge(A[0] - A[1] / A[2] * A[3])
        )return true;
    if (judge(A[0] - A[1] / A[2] / A[3])
        )return true;

//32
    if (judge(A[0] * A[1] + A[2] + A[3])
        )return true;
    if (judge(A[0] * A[1] + A[2] - A[3])
        )return true;
    if (judge(A[0] * A[1] + A[2] * A[3])
        )return true;
    if (judge(A[0] * A[1] + A[2] / A[3])
        )return true;

    if (judge(A[0] * A[1] - A[2] + A[3])
        )return true;
    if (judge(A[0] * A[1] - A[2] - A[3])
        )return true;
    if (judge(A[0] * A[1] - A[2] * A[3])
        )return true;
    if (judge(A[0] * A[1] - A[2] / A[3])
        )return true;

    if (judge(A[0] * A[1] * A[2] + A[3])
        )return true;
    if (judge(A[0] * A[1] * A[2] - A[3])
        )return true;
    if (judge(A[0] * A[1] * A[2] * A[3])
        )return true;
    if (judge(A[0] * A[1] * A[2] / A[3])
        )return true;


    if (judge(A[0] * A[1] / A[2] + A[3])
        )return true;
    if (judge(A[0] * A[1] / A[2] - A[3])
        )return true;
    if (judge(A[0] * A[1] / A[2] * A[3])
        )return true;
    if (judge(A[0] * A[1] / A[2] / A[3])
        )return true;
//48

    if (judge(A[0] / A[1] + A[2] + A[3])
        )return true;
    if (judge(A[0] / A[1] + A[2] - A[3])
        )return true;
    if (judge(A[0] / A[1] + A[2] * A[3])
        )return true;
    if (judge(A[0] / A[1] + A[2] / A[3])
        )return true;

    if (judge(A[0] / A[1] - A[2] + A[3])
        )return true;
    if (judge(A[0] / A[1] - A[2] - A[3])
        )return true;
    if (judge(A[0] / A[1] - A[2] * A[3])
        )return true;
    if (judge(A[0] / A[1] - A[2] / A[3])
        )return true;

    if (judge(A[0] / A[1] * A[2] + A[3])
        )return true;
    if (judge(A[0] / A[1] * A[2] - A[3])
        )return true;
    if (judge(A[0] / A[1] * A[2] * A[3])
        )return true;
    if (judge(A[0] / A[1] * A[2] / A[3])
        )return true;


    if (judge(A[0] / A[1] / A[2] + A[3])
        )return true;
    if (judge(A[0] / A[1] / A[2] - A[3])
        )return true;
    if (judge(A[0] / A[1] / A[2] * A[3])
        )return true;
    if (judge(A[0] / A[1] / A[2] / A[3])
        )return true;
    //64

    if (judge((A[0] + A[1]) + A[2] + A[3])
        )return true;
    if (judge((A[0] + A[1]) + A[2] - A[3])
        )return true;
    if (judge((A[0] + A[1]) + A[2] * A[3])
        )return true;
    if (judge((A[0] + A[1]) + A[2] / A[3])
        )return true;

    if (judge((A[0] + A[1]) - A[2] + A[3])
        )return true;
    if (judge((A[0] + A[1]) - A[2] - A[3])
        )return true;
    if (judge((A[0] + A[1]) - A[2] * A[3])
        )return true;
    if (judge((A[0] + A[1]) - A[2] / A[3])
        )return true;

    if (judge((A[0] + A[1]) * A[2] + A[3])
        )return true;
    if (judge((A[0] + A[1]) * A[2] - A[3])
        )return true;
    if (judge((A[0] + A[1]) * A[2] * A[3])
        )return true;
    if (judge((A[0] + A[1]) * A[2] / A[3])
        )return true;


    if (judge((A[0] + A[1]) / A[2] + A[3])
        )return true;
    if (judge((A[0] + A[1]) / A[2] - A[3])
        )return true;
    if (judge((A[0] + A[1]) / A[2] * A[3])
        )return true;
    if (judge((A[0] + A[1]) / A[2] / A[3])
        )return true;

    //16
    if (judge((A[0] - A[1]) + A[2] + A[3])
        )return true;
    if (judge((A[0] - A[1]) + A[2] - A[3])
        )return true;
    if (judge((A[0] - A[1]) + A[2] * A[3])
        )return true;
    if (judge((A[0] - A[1]) + A[2] / A[3])
        )return true;

    if (judge((A[0] - A[1]) - A[2] + A[3])
        )return true;
    if (judge((A[0] - A[1]) - A[2] - A[3])
        )return true;
    if (judge((A[0] - A[1]) - A[2] * A[3])
        )return true;
    if (judge((A[0] - A[1]) - A[2] / A[3])
        )return true;

    if (judge((A[0] - A[1]) * A[2] + A[3])
        )return true;
    if (judge((A[0] - A[1]) * A[2] - A[3])
        )return true;
    if (judge((A[0] - A[1]) * A[2] * A[3])
        )return true;
    if (judge((A[0] - A[1]) * A[2] / A[3])
        )return true;


    if (judge((A[0] - A[1]) / A[2] + A[3])
        )return true;
    if (judge((A[0] - A[1]) / A[2] - A[3])
        )return true;
    if (judge((A[0] - A[1]) / A[2] * A[3])
        )return true;
    if (judge((A[0] - A[1]) / A[2] / A[3])
        )return true;

//32
    if (judge((A[0] * A[1]) + A[2] + A[3])
        )return true;
    if (judge((A[0] * A[1]) + A[2] - A[3])
        )return true;
    if (judge((A[0] * A[1]) + A[2] * A[3])
        )return true;
    if (judge((A[0] * A[1]) + A[2] / A[3])
        )return true;

    if (judge((A[0] * A[1]) - A[2] + A[3])
        )return true;
    if (judge((A[0] * A[1]) - A[2] - A[3])
        )return true;
    if (judge((A[0] * A[1]) - A[2] * A[3])
        )return true;
    if (judge((A[0] * A[1]) - A[2] / A[3])
        )return true;

    if (judge((A[0] * A[1]) * A[2] + A[3])
        )return true;
    if (judge((A[0] * A[1]) * A[2] - A[3])
        )return true;
    if (judge((A[0] * A[1]) * A[2] * A[3])
        )return true;
    if (judge((A[0] * A[1]) * A[2] / A[3])
        )return true;


    if (judge((A[0] * A[1]) / A[2] + A[3])
        )return true;
    if (judge((A[0] * A[1]) / A[2] - A[3])
        )return true;
    if (judge((A[0] * A[1]) / A[2] * A[3])
        )return true;
    if (judge((A[0] * A[1]) / A[2] / A[3])
        )return true;
//48

    if (judge((A[0] / A[1]) + A[2] + A[3])
        )return true;
    if (judge((A[0] / A[1]) + A[2] - A[3])
        )return true;
    if (judge((A[0] / A[1]) + A[2] * A[3])
        )return true;
    if (judge((A[0] / A[1]) + A[2] / A[3])
        )return true;

    if (judge((A[0] / A[1]) - A[2] + A[3])
        )return true;
    if (judge((A[0] / A[1]) - A[2] - A[3])
        )return true;
    if (judge((A[0] / A[1]) - A[2] * A[3])
        )return true;
    if (judge((A[0] / A[1]) - A[2] / A[3])
        )return true;

    if (judge((A[0] / A[1]) * A[2] + A[3])
        )return true;
    if (judge((A[0] / A[1]) * A[2] - A[3])
        )return true;
    if (judge((A[0] / A[1]) * A[2] * A[3])
        )return true;
    if (judge((A[0] / A[1]) * A[2] / A[3])
        )return true;


    if (judge((A[0] / A[1]) / A[2] + A[3])
        )return true;
    if (judge((A[0] / A[1]) / A[2] - A[3])
        )return true;
    if (judge((A[0] / A[1]) / A[2] * A[3])
        )return true;
    if (judge((A[0] / A[1]) / A[2] / A[3])
        )return true;
    //64


    if (judge(A[0] + (A[1] + A[2]) + A[3])
        )return true;
    if (judge(A[0] + (A[1] + A[2]) - A[3])
        )return true;
    if (judge(A[0] + (A[1] + A[2]) * A[3])
        )return true;
    if (judge(A[0] + (A[1] + A[2]) / A[3])
        )return true;

    if (judge(A[0] + (A[1] - A[2]) + A[3])
        )return true;
    if (judge(A[0] + (A[1] - A[2]) - A[3])
        )return true;
    if (judge(A[0] + (A[1] - A[2]) * A[3])
        )return true;
    if (judge(A[0] + (A[1] - A[2]) / A[3])
        )return true;

    if (judge(A[0] + (A[1] * A[2]) + A[3])
        )return true;
    if (judge(A[0] + (A[1] * A[2]) - A[3])
        )return true;
    if (judge(A[0] + (A[1] * A[2]) * A[3])
        )return true;
    if (judge(A[0] + (A[1] * A[2]) / A[3])
        )return true;


    if (judge(A[0] + (A[1] / A[2]) + A[3])
        )return true;
    if (judge(A[0] + (A[1] / A[2]) - A[3])
        )return true;
    if (judge(A[0] + (A[1] / A[2]) * A[3])
        )return true;
    if (judge(A[0] + (A[1] / A[2]) / A[3])
        )return true;

    //16
    if (judge(A[0] - (A[1] + A[2]) + A[3])
        )return true;
    if (judge(A[0] - (A[1] + A[2]) - A[3])
        )return true;
    if (judge(A[0] - (A[1] + A[2]) * A[3])
        )return true;
    if (judge(A[0] - (A[1] + A[2]) / A[3])
        )return true;

    if (judge(A[0] - (A[1] - A[2]) + A[3])
        )return true;
    if (judge(A[0] - (A[1] - A[2]) - A[3])
        )return true;
    if (judge(A[0] - (A[1] - A[2]) * A[3])
        )return true;
    if (judge(A[0] - (A[1] - A[2]) / A[3])
        )return true;

    if (judge(A[0] - (A[1] * A[2]) + A[3])
        )return true;
    if (judge(A[0] - (A[1] * A[2]) - A[3])
        )return true;
    if (judge(A[0] - (A[1] * A[2]) * A[3])
        )return true;
    if (judge(A[0] - (A[1] * A[2]) / A[3])
        )return true;


    if (judge(A[0] - (A[1] / A[2]) + A[3])
        )return true;
    if (judge(A[0] - (A[1] / A[2]) - A[3])
        )return true;
    if (judge(A[0] - (A[1] / A[2]) * A[3])
        )return true;
    if (judge(A[0] - (A[1] / A[2]) / A[3])
        )return true;

//32
    if (judge(A[0] * (A[1] + A[2]) + A[3])
        )return true;
    if (judge(A[0] * (A[1] + A[2]) - A[3])
        )return true;
    if (judge(A[0] * (A[1] + A[2]) * A[3])
        )return true;
    if (judge(A[0] * (A[1] + A[2]) / A[3])
        )return true;

    if (judge(A[0] * (A[1] - A[2]) + A[3])
        )return true;
    if (judge(A[0] * (A[1] - A[2]) - A[3])
        )return true;
    if (judge(A[0] * (A[1] - A[2]) * A[3])
        )return true;
    if (judge(A[0] * (A[1] - A[2]) / A[3])
        )return true;

    if (judge(A[0] * (A[1] * A[2]) + A[3])
        )return true;
    if (judge(A[0] * (A[1] * A[2]) - A[3])
        )return true;
    if (judge(A[0] * (A[1] * A[2]) * A[3])
        )return true;
    if (judge(A[0] * (A[1] * A[2]) / A[3])
        )return true;


    if (judge(A[0] * (A[1] / A[2]) + A[3])
        )return true;
    if (judge(A[0] * (A[1] / A[2]) - A[3])
        )return true;
    if (judge(A[0] * (A[1] / A[2]) * A[3])
        )return true;
    if (judge(A[0] * (A[1] / A[2]) / A[3])
        )return true;
//48

    if (judge(A[0] / (A[1] + A[2]) + A[3])
        )return true;
    if (judge(A[0] / (A[1] + A[2]) - A[3])
        )return true;
    if (judge(A[0] / (A[1] + A[2]) * A[3])
        )return true;
    if (judge(A[0] / (A[1] + A[2]) / A[3])
        )return true;

    if (judge(A[0] / (A[1] - A[2]) + A[3])
        )return true;
    if (judge(A[0] / (A[1] - A[2]) - A[3])
        )return true;
    if (judge(A[0] / (A[1] - A[2]) * A[3])
        )return true;
    if (judge(A[0] / (A[1] - A[2]) / A[3])
        )return true;

    if (judge(A[0] / (A[1] * A[2]) + A[3])
        )return true;
    if (judge(A[0] / (A[1] * A[2]) - A[3])
        )return true;
    if (judge(A[0] / (A[1] * A[2]) * A[3])
        )return true;
    if (judge(A[0] / (A[1] * A[2]) / A[3])
        )return true;


    if (judge(A[0] / (A[1] / A[2]) + A[3])
        )return true;
    if (judge(A[0] / (A[1] / A[2]) - A[3])
        )return true;
    if (judge(A[0] / (A[1] / A[2]) * A[3])
        )return true;
    if (judge(A[0] / (A[1] / A[2]) / A[3])
        )return true;
    //64
    if (judge(A[0] + A[1] + (A[2] + A[3]))
        )return true;
    if (judge(A[0] + A[1] + (A[2] - A[3]))
        )return true;
    if (judge(A[0] + A[1] + (A[2] * A[3]))
        )return true;
    if (judge(A[0] + A[1] + (A[2] / A[3]))
        )return true;

    if (judge(A[0] + A[1] - (A[2] + A[3]))
        )return true;
    if (judge(A[0] + A[1] - (A[2] - A[3]))
        )return true;
    if (judge(A[0] + A[1] - (A[2] * A[3]))
        )return true;
    if (judge(A[0] + A[1] - (A[2] / A[3]))
        )return true;

    if (judge(A[0] + A[1] * (A[2] + A[3]))
        )return true;
    if (judge(A[0] + A[1] * (A[2] - A[3]))
        )return true;
    if (judge(A[0] + A[1] * (A[2] * A[3]))
        )return true;
    if (judge(A[0] + A[1] * (A[2] / A[3]))
        )return true;


    if (judge(A[0] + A[1] / (A[2] + A[3]))
        )return true;
    if (judge(A[0] + A[1] / (A[2] - A[3]))
        )return true;
    if (judge(A[0] + A[1] / (A[2] * A[3]))
        )return true;
    if (judge(A[0] + A[1] / (A[2] / A[3]))
        )return true;

    //16
    if (judge(A[0] - A[1] + (A[2] + A[3]))
        )return true;
    if (judge(A[0] - A[1] + (A[2] - A[3]))
        )return true;
    if (judge(A[0] - A[1] + (A[2] * A[3]))
        )return true;
    if (judge(A[0] - A[1] + (A[2] / A[3]))
        )return true;

    if (judge(A[0] - A[1] - (A[2] + A[3]))
        )return true;
    if (judge(A[0] - A[1] - (A[2] - A[3]))
        )return true;
    if (judge(A[0] - A[1] - (A[2] * A[3]))
        )return true;
    if (judge(A[0] - A[1] - (A[2] / A[3]))
        )return true;

    if (judge(A[0] - A[1] * (A[2] + A[3]))
        )return true;
    if (judge(A[0] - A[1] * (A[2] - A[3]))
        )return true;
    if (judge(A[0] - A[1] * (A[2] * A[3]))
        )return true;
    if (judge(A[0] - A[1] * (A[2] / A[3]))
        )return true;


    if (judge(A[0] - A[1] / (A[2] + A[3]))
        )return true;
    if (judge(A[0] - A[1] / (A[2] - A[3]))
        )return true;
    if (judge(A[0] - A[1] / (A[2] * A[3]))
        )return true;
    if (judge(A[0] - A[1] / (A[2] / A[3]))
        )return true;

//32
    if (judge(A[0] * A[1] + (A[2] + A[3]))
        )return true;
    if (judge(A[0] * A[1] + (A[2] - A[3]))
        )return true;
    if (judge(A[0] * A[1] + (A[2] * A[3]))
        )return true;
    if (judge(A[0] * A[1] + (A[2] / A[3]))
        )return true;

    if (judge(A[0] * A[1] - (A[2] + A[3]))
        )return true;
    if (judge(A[0] * A[1] - (A[2] - A[3]))
        )return true;
    if (judge(A[0] * A[1] - (A[2] * A[3]))
        )return true;
    if (judge(A[0] * A[1] - (A[2] / A[3]))
        )return true;

    if (judge(A[0] * A[1] * (A[2] + A[3]))
        )return true;
    if (judge(A[0] * A[1] * (A[2] - A[3]))
        )return true;
    if (judge(A[0] * A[1] * (A[2] * A[3]))
        )return true;
    if (judge(A[0] * A[1] * (A[2] / A[3]))
        )return true;


    if (judge(A[0] * A[1] / (A[2] + A[3]))
        )return true;
    if (judge(A[0] * A[1] / (A[2] - A[3]))
        )return true;
    if (judge(A[0] * A[1] / (A[2] * A[3]))
        )return true;
    if (judge(A[0] * A[1] / (A[2] / A[3]))
        )return true;
//48

    if (judge(A[0] / A[1] + (A[2] + A[3]))
        )return true;
    if (judge(A[0] / A[1] + (A[2] - A[3]))
        )return true;
    if (judge(A[0] / A[1] + (A[2] * A[3]))
        )return true;
    if (judge(A[0] / A[1] + (A[2] / A[3]))
        )return true;

    if (judge(A[0] / A[1] - (A[2] + A[3]))
        )return true;
    if (judge(A[0] / A[1] - (A[2] - A[3]))
        )return true;
    if (judge(A[0] / A[1] - (A[2] * A[3]))
        )return true;
    if (judge(A[0] / A[1] - (A[2] / A[3]))
        )return true;

    if (judge(A[0] / A[1] * (A[2] + A[3]))
        )return true;
    if (judge(A[0] / A[1] * (A[2] - A[3]))
        )return true;
    if (judge(A[0] / A[1] * (A[2] * A[3]))
        )return true;
    if (judge(A[0] / A[1] * (A[2] / A[3]))
        )return true;


    if (judge(A[0] / A[1] / (A[2] + A[3]))
        )return true;
    if (judge(A[0] / A[1] / (A[2] - A[3]))
        )return true;
    if (judge(A[0] / A[1] / (A[2] * A[3]))
        )return true;
    if (judge(A[0] / A[1] / (A[2] / A[3]))
        )return true;
    //64
if (judge((A[0] + A[1] + A[2]) + A[3])
        )return true;
    if (judge((A[0] + A[1] + A[2]) - A[3])
        )return true;
    if (judge((A[0] + A[1] + A[2]) * A[3])
        )return true;
    if (judge((A[0] + A[1] + A[2]) / A[3])
        )return true;

    if (judge((A[0] + A[1] - A[2]) + A[3])
        )return true;
    if (judge((A[0] + A[1] - A[2]) - A[3])
        )return true;
    if (judge((A[0] + A[1] - A[2]) * A[3])
        )return true;
    if (judge((A[0] + A[1] - A[2]) / A[3])
        )return true;

    if (judge((A[0] + A[1] * A[2]) + A[3])
        )return true;
    if (judge((A[0] + A[1] * A[2]) - A[3])
        )return true;
    if (judge((A[0] + A[1] * A[2]) * A[3])
        )return true;
    if (judge((A[0] + A[1] * A[2]) / A[3])
        )return true;


    if (judge((A[0] + A[1] / A[2]) + A[3])
        )return true;
    if (judge((A[0] + A[1] / A[2]) - A[3])
        )return true;
    if (judge((A[0] + A[1] / A[2]) * A[3])
        )return true;
    if (judge((A[0] + A[1] / A[2]) / A[3])
        )return true;

    //16
    if (judge((A[0] - A[1] + A[2]) + A[3])
        )return true;
    if (judge((A[0] - A[1] + A[2]) - A[3])
        )return true;
    if (judge((A[0] - A[1] + A[2]) * A[3])
        )return true;
    if (judge((A[0] - A[1] + A[2]) / A[3])
        )return true;

    if (judge((A[0] - A[1] - A[2]) + A[3])
        )return true;
    if (judge((A[0] - A[1] - A[2]) - A[3])
        )return true;
    if (judge((A[0] - A[1] - A[2]) * A[3])
        )return true;
    if (judge((A[0] - A[1] - A[2]) / A[3])
        )return true;

    if (judge((A[0] - A[1] * A[2]) + A[3])
        )return true;
    if (judge((A[0] - A[1] * A[2]) - A[3])
        )return true;
    if (judge((A[0] - A[1] * A[2]) * A[3])
        )return true;
    if (judge((A[0] - A[1] * A[2]) / A[3])
        )return true;


    if (judge((A[0] - A[1] / A[2]) + A[3])
        )return true;
    if (judge((A[0] - A[1] / A[2]) - A[3])
        )return true;
    if (judge((A[0] - A[1] / A[2]) * A[3])
        )return true;
    if (judge((A[0] - A[1] / A[2]) / A[3])
        )return true;

//32
    if (judge((A[0] * A[1] + A[2]) + A[3])
        )return true;
    if (judge((A[0] * A[1] + A[2]) - A[3])
        )return true;
    if (judge((A[0] * A[1] + A[2]) * A[3])
        )return true;
    if (judge((A[0] * A[1] + A[2]) / A[3])
        )return true;

    if (judge((A[0] * A[1] - A[2]) + A[3])
        )return true;
    if (judge((A[0] * A[1] - A[2]) - A[3])
        )return true;
    if (judge((A[0] * A[1] - A[2]) * A[3])
        )return true;
    if (judge((A[0] * A[1] - A[2]) / A[3])
        )return true;

    if (judge((A[0] * A[1] * A[2]) + A[3])
        )return true;
    if (judge((A[0] * A[1] * A[2]) - A[3])
        )return true;
    if (judge((A[0] * A[1] * A[2]) * A[3])
        )return true;
    if (judge((A[0] * A[1] * A[2]) / A[3])
        )return true;


    if (judge((A[0] * A[1] / A[2]) + A[3])
        )return true;
    if (judge((A[0] * A[1] / A[2]) - A[3])
        )return true;
    if (judge((A[0] * A[1] / A[2]) * A[3])
        )return true;
    if (judge((A[0] * A[1] / A[2]) / A[3])
        )return true;
//48

    if (judge((A[0] / A[1] + A[2]) + A[3])
        )return true;
    if (judge((A[0] / A[1] + A[2]) - A[3])
        )return true;
    if (judge((A[0] / A[1] + A[2]) * A[3])
        )return true;
    if (judge((A[0] / A[1] + A[2]) / A[3])
        )return true;

    if (judge((A[0] / A[1] - A[2]) + A[3])
        )return true;
    if (judge((A[0] / A[1] - A[2]) - A[3])
        )return true;
    if (judge((A[0] / A[1] - A[2]) * A[3])
        )return true;
    if (judge((A[0] / A[1] - A[2]) / A[3])
        )return true;

    if (judge((A[0] / A[1] * A[2]) + A[3])
        )return true;
    if (judge((A[0] / A[1] * A[2]) - A[3])
        )return true;
    if (judge((A[0] / A[1] * A[2]) * A[3])
        )return true;
    if (judge((A[0] / A[1] * A[2]) / A[3])
        )return true;


    if (judge((A[0] / A[1] / A[2]) + A[3])
        )return true;
    if (judge((A[0] / A[1] / A[2]) - A[3])
        )return true;
    if (judge((A[0] / A[1] / A[2]) * A[3])
        )return true;
    if (judge((A[0] / A[1] / A[2]) / A[3])
        )return true;
    //64


if (judge(A[0] + (A[1] + A[2] + A[3]))
        )return true;
    if (judge(A[0] + (A[1] + A[2] - A[3]))
        )return true;
    if (judge(A[0] + (A[1] + A[2] * A[3]))
        )return true;
    if (judge(A[0] + (A[1] + A[2] / A[3]))
        )return true;

    if (judge(A[0] + (A[1] - A[2] + A[3]))
        )return true;
    if (judge(A[0] + (A[1] - A[2] - A[3]))
        )return true;
    if (judge(A[0] + (A[1] - A[2] * A[3]))
        )return true;
    if (judge(A[0] + (A[1] - A[2] / A[3]))
        )return true;

    if (judge(A[0] + (A[1] * A[2] + A[3]))
        )return true;
    if (judge(A[0] + (A[1] * A[2] - A[3]))
        )return true;
    if (judge(A[0] + (A[1] * A[2] * A[3]))
        )return true;
    if (judge(A[0] + (A[1] * A[2] / A[3]))
        )return true;


    if (judge(A[0] + (A[1] / A[2] + A[3]))
        )return true;
    if (judge(A[0] + (A[1] / A[2] - A[3]))
        )return true;
    if (judge(A[0] + (A[1] / A[2] * A[3]))
        )return true;
    if (judge(A[0] + (A[1] / A[2] / A[3]))
        )return true;

    //16
    if (judge(A[0] - (A[1] + A[2] + A[3]))
        )return true;
    if (judge(A[0] - (A[1] + A[2] - A[3]))
        )return true;
    if (judge(A[0] - (A[1] + A[2] * A[3]))
        )return true;
    if (judge(A[0] - (A[1] + A[2] / A[3]))
        )return true;

    if (judge(A[0] - (A[1] - A[2] + A[3]))
        )return true;
    if (judge(A[0] - (A[1] - A[2] - A[3]))
        )return true;
    if (judge(A[0] - (A[1] - A[2] * A[3]))
        )return true;
    if (judge(A[0] - (A[1] - A[2] / A[3]))
        )return true;

    if (judge(A[0] - (A[1] * A[2] + A[3]))
        )return true;
    if (judge(A[0] - (A[1] * A[2] - A[3]))
        )return true;
    if (judge(A[0] - (A[1] * A[2] * A[3]))
        )return true;
    if (judge(A[0] - (A[1] * A[2] / A[3]))
        )return true;


    if (judge(A[0] - (A[1] / A[2] + A[3]))
        )return true;
    if (judge(A[0] - (A[1] / A[2] - A[3]))
        )return true;
    if (judge(A[0] - (A[1] / A[2] * A[3]))
        )return true;
    if (judge(A[0] - (A[1] / A[2] / A[3]))
        )return true;

//32
    if (judge(A[0] * (A[1] + A[2] + A[3]))
        )return true;
    if (judge(A[0] * (A[1] + A[2] - A[3]))
        )return true;
    if (judge(A[0] * (A[1] + A[2] * A[3]))
        )return true;
    if (judge(A[0] * (A[1] + A[2] / A[3]))
        )return true;

    if (judge(A[0] * (A[1] - A[2] + A[3]))
        )return true;
    if (judge(A[0] * (A[1] - A[2] - A[3]))
        )return true;
    if (judge(A[0] * (A[1] - A[2] * A[3]))
        )return true;
    if (judge(A[0] * (A[1] - A[2] / A[3]))
        )return true;

    if (judge(A[0] * (A[1] * A[2] + A[3]))
        )return true;
    if (judge(A[0] * (A[1] * A[2] - A[3]))
        )return true;
    if (judge(A[0] * (A[1] * A[2] * A[3]))
        )return true;
    if (judge(A[0] * (A[1] * A[2] / A[3]))
        )return true;


    if (judge(A[0] * (A[1] / A[2] + A[3]))
        )return true;
    if (judge(A[0] * (A[1] / A[2] - A[3]))
        )return true;
    if (judge(A[0] * (A[1] / A[2] * A[3]))
        )return true;
    if (judge(A[0] * (A[1] / A[2] / A[3]))
        )return true;
//48

    if (judge(A[0] / (A[1] + A[2] + A[3]))
        )return true;
    if (judge(A[0] / (A[1] + A[2] - A[3]))
        )return true;
    if (judge(A[0] / (A[1] + A[2] * A[3]))
        )return true;
    if (judge(A[0] / (A[1] + A[2] / A[3]))
        )return true;

    if (judge(A[0] / (A[1] - A[2] + A[3]))
        )return true;
    if (judge(A[0] / (A[1] - A[2] - A[3]))
        )return true;
    if (judge(A[0] / (A[1] - A[2] * A[3]))
        )return true;
    if (judge(A[0] / (A[1] - A[2] / A[3]))
        )return true;

    if (judge(A[0] / (A[1] * A[2] + A[3]))
        )return true;
    if (judge(A[0] / (A[1] * A[2] - A[3]))
        )return true;
    if (judge(A[0] / (A[1] * A[2] * A[3]))
        )return true;
    if (judge(A[0] / (A[1] * A[2] / A[3]))
        )return true;


    if (judge(A[0] / (A[1] / A[2] + A[3]))
        )return true;
    if (judge(A[0] / (A[1] / A[2] - A[3]))
        )return true;
    if (judge(A[0] / (A[1] / A[2] * A[3]))
        )return true;
    if (judge(A[0] / (A[1] / A[2] / A[3]))
        )return true;
    //64
if (judge((A[0] + A[1]) + (A[2] + A[3]))
        )return true;
    if (judge((A[0] + A[1]) + (A[2] - A[3]))
        )return true;
    if (judge((A[0] + A[1]) + (A[2] * A[3]))
        )return true;
    if (judge((A[0] + A[1]) + (A[2] / A[3]))
        )return true;

    if (judge((A[0] + A[1]) - (A[2] + A[3]))
        )return true;
    if (judge((A[0] + A[1]) - (A[2] - A[3]))
        )return true;
    if (judge((A[0] + A[1]) - (A[2] * A[3]))
        )return true;
    if (judge((A[0] + A[1]) - (A[2] / A[3]))
        )return true;

    if (judge((A[0] + A[1]) * (A[2] + A[3]))
        )return true;
    if (judge((A[0] + A[1]) * (A[2] - A[3]))
        )return true;
    if (judge((A[0] + A[1]) * (A[2] * A[3]))
        )return true;
    if (judge((A[0] + A[1]) * (A[2] / A[3]))
        )return true;


    if (judge((A[0] + A[1]) / (A[2] + A[3]))
        )return true;
    if (judge((A[0] + A[1]) / (A[2] - A[3]))
        )return true;
    if (judge((A[0] + A[1]) / (A[2] * A[3]))
        )return true;
    if (judge((A[0] + A[1]) / (A[2] / A[3]))
        )return true;

    //16
    if (judge((A[0] - A[1]) + (A[2] + A[3]))
        )return true;
    if (judge((A[0] - A[1]) + (A[2] - A[3]))
        )return true;
    if (judge((A[0] - A[1]) + (A[2] * A[3]))
        )return true;
    if (judge((A[0] - A[1]) + (A[2] / A[3]))
        )return true;

    if (judge((A[0] - A[1]) - (A[2] + A[3]))
        )return true;
    if (judge((A[0] - A[1]) - (A[2] - A[3]))
        )return true;
    if (judge((A[0] - A[1]) - (A[2] * A[3]))
        )return true;
    if (judge((A[0] - A[1]) - (A[2] / A[3]))
        )return true;

    if (judge((A[0] - A[1]) * (A[2] + A[3]))
        )return true;
    if (judge((A[0] - A[1]) * (A[2] - A[3]))
        )return true;
    if (judge((A[0] - A[1]) * (A[2] * A[3]))
        )return true;
    if (judge((A[0] - A[1]) * (A[2] / A[3]))
        )return true;


    if (judge((A[0] - A[1]) / (A[2] + A[3]))
        )return true;
    if (judge((A[0] - A[1]) / (A[2] - A[3]))
        )return true;
    if (judge((A[0] - A[1]) / (A[2] * A[3]))
        )return true;
    if (judge((A[0] - A[1]) / (A[2] / A[3]))
        )return true;

//32
    if (judge((A[0] * A[1]) + (A[2] + A[3]))
        )return true;
    if (judge((A[0] * A[1]) + (A[2] - A[3]))
        )return true;
    if (judge((A[0] * A[1]) + (A[2] * A[3]))
        )return true;
    if (judge((A[0] * A[1]) + (A[2] / A[3]))
        )return true;

    if (judge((A[0] * A[1]) - (A[2] + A[3]))
        )return true;
    if (judge((A[0] * A[1]) - (A[2] - A[3]))
        )return true;
    if (judge((A[0] * A[1]) - (A[2] * A[3]))
        )return true;
    if (judge((A[0] * A[1]) - (A[2] / A[3]))
        )return true;

    if (judge((A[0] * A[1]) * (A[2] + A[3]))
        )return true;
    if (judge((A[0] * A[1]) * (A[2] - A[3]))
        )return true;
    if (judge((A[0] * A[1]) * (A[2] * A[3]))
        )return true;
    if (judge((A[0] * A[1]) * (A[2] / A[3]))
        )return true;


    if (judge((A[0] * A[1]) / (A[2] + A[3]))
        )return true;
    if (judge((A[0] * A[1]) / (A[2] - A[3]))
        )return true;
    if (judge((A[0] * A[1]) / (A[2] * A[3]))
        )return true;
    if (judge((A[0] * A[1]) / (A[2] / A[3]))
        )return true;
//48

    if (judge((A[0] / A[1]) + (A[2] + A[3]))
        )return true;
    if (judge((A[0] / A[1]) + (A[2] - A[3]))
        )return true;
    if (judge((A[0] / A[1]) + (A[2] * A[3]))
        )return true;
    if (judge((A[0] / A[1]) + (A[2] / A[3]))
        )return true;

    if (judge((A[0] / A[1]) - (A[2] + A[3]))
        )return true;
    if (judge((A[0] / A[1]) - (A[2] - A[3]))
        )return true;
    if (judge((A[0] / A[1]) - (A[2] * A[3]))
        )return true;
    if (judge((A[0] / A[1]) - (A[2] / A[3]))
        )return true;

    if (judge((A[0] / A[1]) * (A[2] + A[3]))
        )return true;
    if (judge((A[0] / A[1]) * (A[2] - A[3]))
        )return true;
    if (judge((A[0] / A[1]) * (A[2] * A[3]))
        )return true;
    if (judge((A[0] / A[1]) * (A[2] / A[3]))
        )return true;


    if (judge((A[0] / A[1]) / (A[2] + A[3]))
        )return true;
    if (judge((A[0] / A[1]) / (A[2] - A[3]))
        )return true;
    if (judge((A[0] / A[1]) / (A[2] * A[3]))
        )return true;
    if (judge((A[0] / A[1]) / (A[2] / A[3]))
        )return true;
    //64


    return false;
}


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int flag = false;
        scanf("%lf%lf%lf%lf", &A[0], &A[1], &A[2], &A[3]);
        sort(A, A + 4);
        do {
//          printf("%lf %lf %lf %lf\n", A[0], A[1], A[2], A[3]);
            if (hehe()) {
                flag = true;
                break;
            }

        } while (next_permutation(A, A + 4));
        if (flag)
            puts("yes");
        else
            puts("no");

    }
    return 0;
}
