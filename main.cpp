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
	// Création d'un magasin et de trois produits

	// Question 1
	Magasin EasyStore; 
	Produit produit("PS4", "Console Sony", 10, 299.99);
	Produit produit2("Switch", "Console Nintendo", 20, 259.99);
	Produit produit3("XBox", "Console Microsoft", 50, 219.99);

	// Question 2 : surcharge de l'opérateur <<
	produit.modifierQuantite(20);
	cout<<"\n\n================= QUESTION 2 =================\n\n";
	cout<<produit<<"\n";

	// Question 3 : Ajout de produits, et affichage pour les produits du magasin
	EasyStore.ajouterProduit(produit);
	EasyStore.ajouterProduit(produit2);
	EasyStore.majStock("Switch", 30);

	cout<<"\n\n\n\n================= QUESTION 3 =================\n\n";
	EasyStore.afficherProduits();

	// Question 4 : Ajout de clients
	Client client("Hallyday", "Johnny");
	Client client2("Cash", "Johnny");
	Client client3("Bravo", "Johnny");
	client.ajouterAuPanier(produit);
	client.viderPanier();
	client.ajouterAuPanier(produit);
	client.ajouterAuPanier(produit2);

	cout<<"\n\n\n\n================= QUESTION 4 =================\n\n";
	cout<<client;

	// Question 5 : Ajout de clients au magasin
	EasyStore.ajouterClient(client);
	EasyStore.ajouterClient(client2);
	EasyStore.ajouterClient(client3);
	
	cout<<"\n\n\n\n================= QUESTION 5 =================\n\n";
	cout<<"======== AFFICHAGE DE TOUS LES CLIENTS =======\n\n";
	EasyStore.afficherClients();
	cout<<"\n\n============ AFFICHAGE D'UN CLIENT ===========\n\n";
	EasyStore.afficherClient("Cash");

	// Création de tableaux de produits, clients et commandes pour création d'un magasin
	vector <Produit> listeProduits;
	vector <Client> listeClients;
	vector <Commande> listeCommandes;

	listeProduits.push_back(produit);
	listeProduits.push_back(produit2);

	listeClients.push_back(client);
	listeClients.push_back(client2);

	// Question 6 : Ajout d'une commande
	Commande commande(client, listeProduits);
	listeCommandes.push_back(commande);

	cout<<"\n\n\n\n================= QUESTION 6 =================\n\n";
	cout<<commande; 

	// Question 7 : Affichage des commandes d'un magasin

	cout<<"\n\n\n\n================= QUESTION 7 =================\n\n";

	listeProduits.push_back(produit3);
	Commande commande2(client2, listeProduits);
	listeCommandes.push_back(commande2);
	Magasin magasin2(listeProduits, listeClients, listeCommandes);
	magasin2.afficherCommandesClient(client2);
	cout<<"\n";

	return 0;
}