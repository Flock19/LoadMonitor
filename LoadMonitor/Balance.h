#pragma once
class Balance
{
private:
	double precision;
	double chargeInit;
	double chargeFin;
public:
	double chargetmp; 
	Balance();
	Balance(double prec, double init, double fin);
	void setPrecision(int precision);
	double getPrecision();
	double chargeCourante();
	double getChargeInit();
	double getChargeFin();
	void setChargeFin(double a);
	void setChargeInit(double a);

	void changePoids(double ajout);

};

