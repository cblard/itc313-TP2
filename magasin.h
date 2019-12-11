/** 
  * Fichier:  magasin.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Déclaration de la classe Magasin
  */

#ifndef MAGASIN_H
#define MAGASIN_H

#include "produit.h"
#include "client.h"
#include "commande.h"

class Magasin{
public:
	Magasin();
	Magasin(vector <Produit> produits, vector <Client> clients, vector <Commande> commandes);
	void ajouterProduit(Produit produit);
	void afficherProduits();
	void afficherProduit(string nom);
	void majStock(string nom, int quantite);
	void ajouterClient(Client client);
	void afficherClients();
	void afficherClient(string nom);
	void afficherClient(int id);
	void ajouterAuPanier(Produit produit, Client client);
	void retirerDuPanier(Produit produit, Client client);
	void modifierQuantitePanier(Produit produit, Client client, int quantite);
private:
	vector <Produit> m_produits;
	vector <Client> m_clients;
	vector <Commande> m_commandes;
};
#endif