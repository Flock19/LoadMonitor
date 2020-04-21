// LoadMonitor.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Balance.h"
#include "Produits.h"
#include <iostream>
#include <fstream>
#include "Bloc.h"
#include <time.h>       /* time */

double randomQuantites(Bloc b) {
    double poids = 0.0;
    for (int i = 0; i < rand() % 51; i++) {
        int pointeur = rand() % b.getProduits().getValeurs().size();
        std::cout <<b.getProduits().getNom()<<"[" << pointeur << "]" << " : " << b.getProduits().getValeurs()[pointeur] << endl;
        poids = poids + b.getProduits().getValeurs()[pointeur];
    }
    std::cout << "Le poids total : " << poids << endl;

    return poids;
}
double randomQuantites(vector<double> vect) {
    double poids = 0.0;
    for (int i = 0; i < rand() % 51; i++) {
        int pointeur = rand() % vect.size();
        std::cout << "Produit[" << pointeur << "]" << " : " << vect[pointeur] << endl;
        poids = poids + vect[pointeur];
    }
    std::cout << "Le poids total : " << poids << endl;

    return poids;
}
std::vector<std::string> split(const std::string& src, char delim) {
    using namespace std;
    vector<string> v;
    auto p = begin(src);
    for (auto q = find(p, end(src), delim); q != end(src); q = find(++p, end(src), delim)) {
        v.emplace_back(p, q);
        p = q;
    }
    if (p != end(src))
        v.emplace_back(p, end(src));
    return v;
}
void systeme() {
    try
    {
        std::ifstream monFlux("qte_produits.txt");  //Ouverture d'un fichier en lecture
        if (monFlux)
        {
            int count = 0;
            string line;
            std::vector<Bloc> blocs;
            while (getline(monFlux, line))
            {
                if (line.empty()) {
                    break;
                }
                std::string::size_type sz;     // alias of size_t
                cout <<line<<endl;
                double first = std::stod(split(line, ' ')[1], &sz);
                string nom = split(line, ' ')[0];
                Produits produit(nom);
                Balance balance(0.97, 20, first);
                Bloc bloc(balance, produit);
                blocs.push_back(bloc);
                count++;

            }
            monFlux.close();
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
int main()
{
    srand(time(NULL));
    std::cout << "Hello Boulangerie ! \n";
    Produits p1("P.Chocolat ");
    /*Produits p2("Croissant");
    Produits p3("Baguette");*/
    Balance bal1(0.96, 20, 1000);
    Bloc bloc(bal1,p1);
    //double b = randomQuantites(bloc);
    //bloc.show();
    bloc.bal.changePoids(-randomQuantites(bloc));
    bloc.showStock();
    
   /* bloc.bal.changePoids(-randomQuantites(bloc));
    bloc.showStock();*/
    //bloc.bal.changePoids(-randomQuantites(bloc));
    
    for (auto a : bloc.qte)
        cout << "Qte : " << a << endl;
    bloc.bal.changePoids(710);
    //systeme();


    /*bloc.show();
    bloc.bal.changePoids(randomQuantites(bloc));
    bloc.show();
    std::cout<<bloc.getBalance().chargeCourante() << endl;*/

    /*
    bal1.changePoids(randomQuantites(p1.getValeurs()));
    bal1.changePoids(randomQuantites(p1.getValeurs()));
    std::cout <<" Charge courante : "<< bal1.chargeCourante() << endl;
    std::cout <<"Nombre de "<<p1.getNom()<<" : "<< bal1.chargeCourante()<<"/"<<p1.valMoyenne()<< " : " << bal1.chargeCourante()/ p1.valMoyenne()<< endl;
    */

    

}

