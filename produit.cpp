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

string Produit::getDescription(){
	return m_description;
}

void Produit::modifierQuantite(int quantite){
	m_stock=quantite;
}

string Produit::getDescriptionComplete(){
	string out="";
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

bool operator==(Produit produit, Produit produit2){
	if(produit.getTitre()==produit2.getTitre() && produit.getDescription()==produit2.getDescription() && 
		produit.getStock()==produit2.getStock() && produit.getPrix()==produit2.getPrix()){
		return true;
	}
	else return false; 
}