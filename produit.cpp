/** 
  * Fichier:  produit.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Produit
  */

#include "produit.h"
#include <iomanip>

Produit::Produit(string titre, string description, int stock, float prix)
: m_titre(titre), m_description(description), m_prix(prix), m_stock(stock) {
}

int Produit::getStock(){
	return m_stock;
}

float Produit::getPrix(){
	return m_prix; 
}

string Produit::getTitre(){
	return m_titre;
}
void Produit::modifierQuantite(int quantite){
	m_stock=quantite;
}
string Produit::getDescription(){
	string out;
	out="_______________________________________________________________________________________\nProduit : "+
	m_titre+"\nDescription : "+
	m_description+"\n"+"Prix : "+
	to_string(m_prix)+"€\nStock disponible : "+
	to_string(m_stock)+
	"\n_______________________________________________________________________________________\n";
	return out;
}

std::ostream &operator<<(std::ostream &out, Produit &produit)
{
	out<<produit.getDescription();
	return out;
}
