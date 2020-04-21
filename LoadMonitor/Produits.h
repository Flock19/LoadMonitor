#pragma once
#include <string>
#include<vector>
#include<numeric>

using namespace std;

class Produits
{
private:
	std::string nom;
	std::vector<double> valeurs;
public:
	Produits();
	Produits(std::string);
	double valMoyenne();
	vector<double> creationListe(double& debut, double& fin);
	vector<double> getValeurs();
	std::string getNom();
};

