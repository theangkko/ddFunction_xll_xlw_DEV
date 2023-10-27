
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


///

double eeSTMPHT(double p, double h)
{
    double pp = p * 100000;
    return T_phmass(pp, h) - 273.15;
}

//double T1 = 300, T2 = 300, T3 = 500, p1 = 3, p2 = 80, p3 = 3;
//printf("%5s %11.8e %11.8e %11.8e\n", "v", 1 / rhomass_Tp(T1, p1),
//
//    double eeSTMPTH(double p, double t)
//{
//    return hmass_Tp(t, p) / 1000;
//}
//printf("%5s %11.8e %11.8e %11.8e\n", "h", hmass_Tp(T1, p1),
//
//    double eeSTMPTH(double p, double t)
//{
//    return hmass_Tp(t, p) / 1000;
//}
//printf("%5s %11.8e %11.8e %11.8e\n", "u", umass_Tp(T1, p1),
//
//    double eeSTMPTH(double p, double t)
//{
//    return hmass_Tp(t, p) / 1000;
//}
//printf("%5s %11.8e %11.8e %11.8e\n", "s", smass_Tp(T1, p1),
//
//    double eeSTMPTH(double p, double t)
//{
//    return hmass_Tp(t, p) / 1000;
//}
//printf("%5s %11.8e %11.8e %11.8e\n", "cp", cpmass_Tp(T1, p1),
//
//    double eeSTMPTH(double p, double t)
//{
//    return hmass_Tp(t, p) / 1000;
//}
//printf("%5s %11.8e %11.8e %11.8e\n", "w", speed_sound_Tp(T1, p1)
//
//
//
//    printf("**************** Reverse Functions T(p,h) & T(p,s) ********************\n\n");
//
//
//printf(" p/MPa  h/(kJ/kg)        T/K       | p/MPa s/(kJ/kg-K)       T/K       \n");
//p1 = 5; h1 = 3500;
//T_phmass(p3, h3);
//
//
//h1 = 0.001;
//s1 = 0;
//printf("     h/(kJ/kg)     s/(kJ/kg-K)       P/MPa       \n");
//p_hsmass(h1, s1);
//
//
//
//printf("     h/(kJ/kg)     s/(kJ/kg-K)        T/K        \n");
//h1 = 1800; s1 = 5.3;
//T_hsmass(h1, s1);
//
