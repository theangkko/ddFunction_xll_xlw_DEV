#pragma warning(disable: 4996)


#include "cppinterface.h"
#include "IF97.h"
#define IAPWS_UNITS

using namespace IF97;

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


std::string ddCheckVersion() 
{
	std::string version = "version : 2023-10-30";
	return version;
}

//------------------------------------------------------
//	rhomass_Tp(double T, double p)		//mass density[kg / m ^ 3] as a function of T[K] and p[Pa]
//	vmass_Tp(double T, double p)		//specific volume[m ^ 3 / kg] as a function of T[K] and p[Pa]
//	hmass_Tp(double T, double p)		//mass enthalpy[J / kg] as a function of T[K] and p[Pa]
//	smass_Tp(double T, double p)		//mass entropy[J / kg / K] as a function of T[K] and p[Pa]
//	umass_Tp(double T, double p)		//mass internal energy[J / kg] as a function of T[K] and p[Pa]
//	cpmass_Tp(double T, double p)		//mass constant - pressure specific heat[J / kg / K] as a function of T[K] and p[Pa]
//	cvmass_Tp(double T, double p)		//mass constant - volume specific heat[J / kg / K] as a function of T[K] and p[Pa]
//	drhodp_Tp(double T, double p)		//[d(rho) / d(p)] T[kg / m©ø/ Pa] as a function of T[K] and p[Pa]
//	speed_sound_Tp(double T, double p)	//speed of sound[m / s] as a function of T[K] and p[Pa]


// pressure		: Pa			, bara to Pa		* 1e5
// temperature	: K				, C to K			+ 273.15
// Enthalpy		: J/kg			, J/kg to kJ/kg		/1000
// Entropy		: J / kg / K	, J/kg/K to kJ/kgK	/1000


// Number of function : 26ea


// Description = "Get Sat. Temp_'C with P _IF97")
// parameter (Name = "pressure", Description = "bara") 
double ddSteamTP(double p)
{
	double tmp = Tsat97(p * 1e5);
	return tmp - 273.15;
}

// Description = "Get Temp_'C with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamTPH(double p, double h)
{
	double tmp = T_phmass(p * 1e5, h * 1000);
	return tmp - 273.15;
}

// Description = "Get Temp_'C with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamTPS(double p, double s)
{
	double tmp = T_psmass(p * 1e5, s);
	return tmp - 273.15;
}

// Description = "Get Temp_'C with HS _IF97")
// parameter (Name = "enthalpy", Description = "kJ/kg") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamTHS(double h, double s)
{
	double tmp = T_hsmass(h * 1000, s);
	return tmp - 273.15;
}

// Description = "Get Sat.Pressure_bara with T _IF97")
// parameter (Name = "temperature", Description = "'C") 
double ddSteamPT(double t)
{
	double tmp = psat97(t + 273.15);
	return tmp / 1e6;
}

// Description = "Get Enhalpy_kJ/kg with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C")
double ddSteamHPT(double p, double t)
{
	double tmp = hmass_Tp(t + 273.15, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Enhalpy_kJ/kg with T _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamHPS(double p, double s)
{
	//double tmp = h_ps(p, s);

	double t = T_psmass(p * 1e5, s);
	double tmp = hmass_Tp(t, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Enhalpy_kJ/kg with PQ _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "Dryness fraction", Description = " 0.0~1.0") 
double ddSteamHPQ(double p, double drynessX)
{
	double tmp = hmass_pQ(p * 1e5, drynessX);
	return tmp / 1000;
}

// Description = "Get Volume_m3/kg with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamVPT(double p, double t)
{
	double tmp = 1 / rhomass_Tp(t + 273.15, p * 1e5);
	return tmp;
}

// Description = "Get Volume_m3/kg with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamVPH(double p, double h)
{
	double tmp = 1 / rhomass_phmass(p * 1e5, h * 1000);
	return tmp;
}

// Description = "Get Volume_m3/kg with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamVPS(double p, double s)
{
	double tmp = 1 / rhomass_psmass(p * 1e5, s);
	return tmp;
}


// Description = "Get Density_kg/m3 with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamRhoPT(double p, double t)
{
	double tmp = rhomass_Tp(t + 273.15, p * 1e5);
	return tmp;
}

// Description = "Get Density_kg/m3 with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamRhoPH(double p, double h)
{
	double tmp = rhomass_phmass(p * 1e5, h * 1000);
	return tmp;
}

// Description = "Get Density_kg/m3 with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamRhoPS(double p, double s)
{
	double tmp = rhomass_psmass(p * 1e5, s);
	return tmp;
}

// Description = "Get Entropy_kJ/kg-K with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamSPT(double p, double t)
{
	double tmp = smass_Tp(t + 273.15, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Entropy_kJ/kg-K with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamSPH(double p, double h)
{
	double t = T_phmass(p * 1e5, h * 1000);
	double tmp = smass_Tp(t, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Cp_kJ/kg-C with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamCpPT(double p, double t)
{
	double tmp = cpmass_Tp(t + 273.15, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Cp_kJ/kg-C with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamCpPH(double p, double h)
{
	double t = T_phmass(p * 1e5, h * 1000);
	double tmp = cpmass_Tp(t, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Cv_kJ/kg-C with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamCvPT(double p, double t)
{
	double tmp = cvmass_Tp(t + 273.15, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Cv_kJ/kg-C with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamCvPH(double p, double h)
{
	double t = T_phmass(p * 1e5, h * 1000);
	double tmp = cvmass_Tp(t, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Cv_kJ/kg-C with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamCvPS(double p, double s)
{
	double t = T_psmass(p * 1e5, s);
	double tmp = cvmass_Tp(t, p * 1e5);
	return tmp / 1000;
}

// Description = "Get Dyn.Viscosity_Pa-s with PT _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "temperature", Description = "'C") 
double ddSteamVisPT(double p, double t)
{
	double tmp = visc_Tp(t + 273.15, p * 1e5);
	return tmp;
}

// Description = "Get Dyn.Viscosity_Pa-s with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamVisPH(double p, double h)
{
	double rho = rhomass_phmass(p * 1e5, h * 1000);
	double t = T_phmass(p * 1e5, h * 1000);

	double tmp = visc_TRho(t, rho);
	return tmp;
}

// Description = "Get Dyn.Viscosity_Pa-s with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamVisPS(double p, double s)
{
	double rho = rhomass_psmass(p * 1e5, s);
	double t = T_psmass(p * 1e5, s);
	double tmp = visc_TRho(t, rho);
	return tmp;
}

// Description = "Get Vapor Fraction with PH _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "enthalpy", Description = "kJ/kg") 
double ddSteamQPH(double p, double h)
{
	double tmp = Q_phmass(p * 1e5, h * 1000);
	return tmp;
}
// Description = "Get Vapor Fraction with PS _IF97")
// parameter (Name = "pressure", Description = "bara") 
// parameter (Name = "entropy", Description = "kJ/kg-K") 
double ddSteamQPS(double p, double s)
{
	double tmp = Q_psmass(p * 1e5, s);
	return tmp;
}
