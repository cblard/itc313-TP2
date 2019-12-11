/** 
  * Fichier:  magasin.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Magasin
  */

#include "magasin.h"

Magasin::Magasin(){

}
	
Magasin::Magasin(vector <Produit> produits, vector <Client> clients, vector <Commande> commandes)
: m_produits(produits), m_clients(clients), m_commandes(commandes) {
	
}

void Magasin::ajouterProduit(Produit produit){
	m_produits.push_back(produit);
}