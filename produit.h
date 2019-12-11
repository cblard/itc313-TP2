/** 
  * Fichier:  produit.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Déclaration de la classe Produit
  */

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
using namespace std; 

class Produit{
public:
	Produit(string titre, string description, int stock, float prix);
	int getStock();
	float getPrix();
private:
	string m_titre;
	string m_description;
	int m_stock;
	float m_prix;
};

#endif