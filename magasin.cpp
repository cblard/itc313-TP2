/** 
  * Fichier:  magasin.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Magasin
  */

#include "magasin.h"
#include <iostream>
using namespace std;

Magasin::Magasin(){

}
	
Magasin::Magasin(vector <Produit> produits, vector <Client> clients, vector <Commande> commandes)
: m_produits(produits), m_clients(clients), m_commandes(commandes) {
	
}

void Magasin::ajouterProduit(Produit produit){
	m_produits.push_back(produit);
}

void Magasin::afficherProduits(){
	cout<<"         LISTE DES PRODUITS                \n";
	for(int i=0; i<m_produits.size(); i++){
		cout<<m_produits.at(i).getDescription();
	}
}

void Magasin::afficherProduit(string nom){
	cout<<"         PRODUIT DEMANDÉ             \n";
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			cout<<m_produits.at(i).getDescription();
		}
	}
}

void Magasin::majStock(string nom, int quantite){
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			m_produits.at(i).modifierQuantite(quantite);
		}
	}
}