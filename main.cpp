/** 
  * Fichier:  main.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Fichier main utilisé pour le TP2
  */

#include <iostream>
#include "magasin.h"

int main(){
	// Création d'un magasin et de deux produits
	Magasin magasin; 
	Produit produit("PS4", "Console Sony", 10, 299.99);
	Produit produit2("Switch", "Console Nintendo", 20, 259.99);
	produit.modifierQuantite(20);

	// Tests d'ajout de produits, et d'affichage pour les produits du magasin
	magasin.ajouterProduit(produit);
	magasin.ajouterProduit(produit2);
	magasin.majStock("Switch", 30);
	//magasin.afficherProduits();

	// Ajout de clients
	Client client("Hallyday", "Johnny");
	client.ajouterAuPanier(produit);
	client.viderPanier();
	client.ajouterAuPanier(produit);
	client.ajouterAuPanier(produit2);
	cout<<client;



	return 0;
}