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
	Produit produit3("XBox", "Console Microsoft", 50, 219.99);
	produit.modifierQuantite(20);

	// Tests d'ajout de produits, et d'affichage pour les produits du magasin
	magasin.ajouterProduit(produit);
	magasin.ajouterProduit(produit2);
	magasin.majStock("Switch", 30);
	//magasin.afficherProduits();

	// Ajout de clients
	Client client("Hallyday", "Johnny");
	Client client2("Cash", "Johnny");
	client.ajouterAuPanier(produit);
	client.viderPanier();
	client.ajouterAuPanier(produit);
	client.ajouterAuPanier(produit2);
	cout<<client;

	// Ajout de clients au magasin
	magasin.ajouterClient(client);
	magasin.ajouterClient(client2);
	magasin.afficherClients();
	magasin.afficherClient("Cash");

	magasin.ajouterAuPanier(produit3, client);

	// Création de tableaux de produits, clients et commandes pour création d'un magasin
	vector <Produit> listeProduits;
	vector <Client> listeClients;
	vector <Commande> listeCommandes;

	listeProduits.push_back(produit);
	listeProduits.push_back(produit2);

	listeClients.push_back(client);
	listeClients.push_back(client2);

	// Ajout d'une commande
	Commande commande(client, listeProduits);
	listeCommandes.push_back(commande);

	cout<<commande; 

	// Affichage des commandes d'un magasin

	cout<<"\n______________AFFICHAGE COMMANDES________________\n";

	Magasin magasin2(listeProduits, listeClients, listeCommandes);
	magasin2.afficherCommandes();
	magasin2.afficherCommandesClient(client);
	cout<<"\n";

	return 0;
}