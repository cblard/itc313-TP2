/** 
  * Fichier:  commande.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Déclaration de la classe Commande
  */

#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include <string>
using namespace std;

class Commande{
public:
	Commande(Client client, vector <Produit> produits);
	string getClient();
	void validerLivraison();
	string getDescription();
	void changerStatut(bool statut);
private:
	Client m_client;
	vector <Produit> m_produits;
	bool m_statut;
};

ostream &operator<<(std::ostream &out, Commande &commande);
bool operator==(Commande commande1, Commande commande2);

#endif