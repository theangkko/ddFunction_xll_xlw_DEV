//
//
//                                                                    Test.h
//

#ifndef TEST_H
#define TEST_H

#include <xlw/MyContainers.h>
#include <xlw/CellMatrix.h>
#include <xlw/DoubleOrNothing.h>
#include <xlw/ArgList.h>  
    
using namespace xlw;

//<xlw:libraryname=MyTestLibrary


short // echoes a short
EchoShort(short x // number to be echoed
       );

MyMatrix // Transpose a matrix
MyTranspose(MyMatrix input // input matrix
);


int MyAdd(int x, int y);

double eeSTMPTH(double p, double t);

#endif
