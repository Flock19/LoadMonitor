#include "Bloc.h"
#include "Balance.h"
#include "Produits.h"
#include <iostream>

using namespace std;

Bloc::Bloc()
{
}
Bloc::Bloc(Balance& bal, Produits& prod)
{
	this->bal = bal;
	this->prod = prod;
	if ((bal.chargeCourante() / prod.valMoyenne()) - int(bal.chargeCourante() / prod.valMoyenne()) >= 0.5) {
		this->qte.push_back(int(bal.chargeCourante() / prod.valMoyenne()) + 1);
	}
	else {
		this->qte.push_back(int(bal.chargeCourante() / prod.valMoyenne()));

	}
}
Balance Bloc::getBalance()
{
	return this->bal;
}
Produits Bloc::getProduits()
{
	return this->prod;
}
void Bloc::setBalance(Balance bal)
{
	this->bal = bal;
}
void Bloc::setProduits(Produits prod)
{
	this->prod = prod;
}
int Bloc::showStock()
{
	if (bal.chargeCourante() == 0) {
		//this->qte = 0;
		cout << "Trop tard, le stock a été dévalisé !" << endl;
	}
	else {
		double moy = prod.valMoyenne() * 1;
		//cout << "Precision : " << bal.getPrecision() << endl;
		//cout << "Nombre de " << prod.getNom() << " : " << bal.chargeCourante() << "/" << moy << " : " << bal.chargeCourante() / moy << endl;
		if ((bal.chargeCourante() / moy) - int(bal.chargeCourante() / moy) >= 0.5) {
			//this->qte = int(bal.chargeCourante() / moy) + 1;
			cout << "Il reste : " << int(bal.chargeCourante() / moy) + 1 << " " << prod.getNom() << endl;
			cout << "Vous avez pris : " << calculeQtePrise() << " " << prod.getNom() << endl;
			this->qte.push_back(int(bal.chargeCourante() / moy)+1);
			return int(bal.chargeCourante() / moy) + 1;
		}
		else {
			//this->qte = int(bal.chargeCourante() / moy);
			cout << "Il reste : " << int(bal.chargeCourante() / moy) << " " << prod.getNom() << endl;
			cout << "Vous avez pris : " << calculeQtePrise() << " " << prod.getNom() << endl;
			this->qte.push_back(int(bal.chargeCourante() / moy));
			return int(bal.chargeCourante() / moy);
		}
	}
}
int Bloc::calculeQtePrise()
{
	double moy = prod.valMoyenne();
	/*cout << "La valeur prise : " <<((bal.chargetmp - bal.chargeCourante()) / moy) << endl;
	cout << "La difference est : " << ((bal.chargetmp - bal.chargeCourante()) / moy) - floor((bal.chargetmp - bal.chargeCourante()) / moy) << endl;*/

	if (((bal.chargetmp - bal.chargeCourante()) / moy) - floor((bal.chargetmp - bal.chargeCourante()) / moy) >= 0.5) {
		cout << "oook";
		return floor((bal.chargetmp - bal.chargeCourante()) / moy) + 1;
	}
	else {
		return floor((bal.chargetmp - bal.chargeCourante()) / moy);

	}
}

