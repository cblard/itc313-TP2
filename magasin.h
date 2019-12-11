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
private:
	vector <Produit> m_produits;
	vector <Client> m_clients;
	vector <Commande> m_commandes;
};
#endif