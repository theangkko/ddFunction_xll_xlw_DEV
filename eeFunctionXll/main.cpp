
#pragma warning (disable : 4996)
#include "cppinterface.h"
#include "IF97.h"

using namespace IF97;

short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

MyMatrix // Transpose a matrix
MyTranspose(MyMatrix input // input matrix
)
{
    MyMatrix result(input.columns(), input.rows());
    for (size_t i = 0; i < input.rows(); ++i)
    {
        for (size_t j = 0; j < input.columns(); ++j)
        {
            result[j][i] = input[i][j];
        }
    }
    return result;
}

int
MyAdd(int x, int y)
{
    return x + y;
}

double eeSTMPTH(double p, double t)
{
    return hmass_Tp(t, p)/1000;
}