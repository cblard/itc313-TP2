/** 
  * Fichier:  produit.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Produit
  */

#include "produit.h"

Produit::Produit(string titre, string description, int stock, float prix)
: m_titre(titre), m_description(description), m_prix(prix), m_stock(stock) {
}

int Produit::getStock(){
	return m_stock;
}

float Produit::getPrix(){
	return m_prix; 
}
