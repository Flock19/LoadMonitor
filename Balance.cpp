#include "Balance.h"
#include <iostream>

Balance::Balance()
{
}
Balance::Balance(double prec, double init, double fin) {
	this->precision = prec;
	this->chargeInit = init;
	this->chargeFin = this->chargeInit + fin;
	this->chargetmp = 0.0;
}
void Balance::setPrecision(int precision)
{
	this->precision = precision;
}
double Balance::getPrecision()
{
	return this->precision;
}
double Balance::chargeCourante()
{
	return (this->chargeFin)-(this->chargeInit);
}
double Balance::getChargeInit()
{
	return this->chargeInit;
}
double Balance::getChargeFin()
{
	return this->chargeFin;
}
void Balance::setChargeFin(double a)
{
	this->chargeFin = a;
}
void Balance::setChargeInit(double a)
{
	this->chargeInit = a;
}
void Balance::changePoids(double ajout) {
	this->chargetmp = this->chargeFin - this->chargeInit;
	std::cout << "Poids initial des produits : " << chargetmp << "\n";
	this->chargeFin = (this->chargeFin + ajout);
}