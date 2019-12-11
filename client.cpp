/** 
  * Fichier:  client.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Client
  */

#include "client.h"

Client::Client(string nom, string prenom): m_nom(nom), m_prenom(prenom){
	m_id=0;
}

void Client::addProduit(Produit produit){
	m_panier.push_back(produit);
}

string Client::getNom(){
	return m_nom;
}
	
string Client::getPrenom(){
	return m_prenom; 
}

int Client::getID(){
	return m_id;
}
	
vector <Produit> Client::getPanier(){
	return m_panier;
}
