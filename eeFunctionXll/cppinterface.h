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

std::string eeCheckVersion();

double eeSteamTP(double p);

double eeSteamTPH(double p, double h);

double eeSteamTPS(double p, double s);

double eeSteamTHS(double h, double s);

double eeSteamPT(double t);

double eeSteamHPT(double p, double t);

double eeSteamHPS(double p, double s);

double eeSteamHPQ(double p, double drynessX);

double eeSteamVPT(double p, double t);

double eeSteamVPH(double p, double h);

double eeSteamVPS(double p, double s);

double eeSteamRhoPT(double p, double t);

double eeSteamRhoPH(double p, double h);

double eeSteamRhoPS(double p, double s);

double eeSteamSPT(double p, double t);

double eeSteamSPH(double p, double h);

double eeSteamCpPT(double p, double t);

double eeSteamCpPH(double p, double h);

double eeSteamCvPT(double p, double t);

double eeSteamCvPH(double p, double h);

double eeSteamCvPS(double p, double s);

double eeSteamVisPT(double p, double t);

double eeSteamVisPH(double p, double h);

double eeSteamVisPS(double p, double s);

double eeSteamQPH(double p, double h);

double eeSteamQPS(double p, double s);



#endif
