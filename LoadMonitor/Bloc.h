#pragma once
#include "Balance.h"
#include "Produits.h"

using namespace std;

class Bloc
{
private:
	Produits prod;
public:
	Balance bal;
	vector<int> qte;
public:
	Bloc();
	Bloc(Balance & bal, Produits & prod);
	Balance getBalance();
	Produits getProduits();
	void setBalance(Balance bal);
	void setProduits(Produits prod);
	//Cette fonction calcule la qté de produit restant sur une balance précise
	int showStock();
	//Cette fonction calcule la qté de produit prise par le client en se reférant au poids
	int calculeQtePrise();
};

