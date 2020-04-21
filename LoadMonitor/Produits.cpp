#include "Produits.h"
#include <iostream>
#include <fstream>



Produits::Produits()
{
}

Produits::Produits(std::string nom)
{
	this->nom = nom;
	try
	{
		std::ifstream monFlux("Poids.txt");  //Ouverture d'un fichier en lecture
		if (monFlux)
		{
			int count = 0;
			while (true)
			{
				string line;
				getline(monFlux, line);
				if (line == nom) {
					getline(monFlux, line);
					//std::string orbits("365.24 29.53");
					std::string::size_type sz;     // alias of size_t

					double first = std::stod(line, &sz);
					double second = std::stod(line.substr(sz));
					this->valeurs = creationListe(first, second);
					//cout << "first : " << first << " - " << "second : " << second << endl;
					monFlux.close();
				}
				if (monFlux.eof())
				{
					break;
				}
				//++count;
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}

	}
	catch (exception & e)
	{
		cout << e.what() << '\n';
	}
	
}

double Produits::valMoyenne()
{
	return accumulate(this->valeurs.begin(), this->valeurs.end(), 0.0) / (this->valeurs.size());
}

vector<double> Produits::creationListe(double &debut, double &fin)
{
	vector<double> liste;
	liste.push_back(debut);
	for (int i = debut; i <= fin; i++) {
		liste.push_back(i);
	}
	//for (auto b : liste) std::cout << b << endl;
	return liste;
}

vector<double> Produits::getValeurs()
{
	return valeurs;
}

std::string Produits::getNom()
{
	return this->nom;
}
