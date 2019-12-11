/** 
  * Fichier:  commande.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Commande
  */

#include "commande.h"

Commande::Commande(Client client, vector <Produit> produits, bool statut) : m_client(client), m_produits(produits), m_statut(statut){
}

string Commande::getClient(){
	string nom=m_client.getNom();
	string prenom=m_client.getPrenom();
	return nom+prenom; 
}

void Commande::validerLivraison(){
	m_statut=true;
}