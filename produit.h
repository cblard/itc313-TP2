/** 
  * Fichier:  produit.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Déclaration de la classe Produit
  */

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

class Produit{
public:
	Produit(string titre, string description, int stock, float prix);
	int getStock();
	float getPrix();
	string getTitre();
	string getDescription();
	string getDescriptionPanier();
	string getDescriptionComplete();
	void modifierQuantite(int quantite);
private:
	string m_titre;
	string m_description;
	float m_prix;
	int m_stock;
};

std::ostream &operator<<(std::ostream &out, Produit &produit);
bool operator==(Produit produit, Produit produit2);

#endif