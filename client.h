/** 
  * Fichier:  client.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Déclaration de la classe Client
  */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
using namespace std; 

#include "produit.h"

class Client{
public:
	Client(string nom, string prenom);
	string getNom();
	string getPrenom();
	int getID();
	vector <Produit> getPanier();
	void ajouterAuPanier(Produit produit);
	void retirerDuPanier(Produit produit); 
	void viderPanier();
	void modifierQuantiteProduit(Produit produit, int quantite);
	string getDescription();
	string getInfos();
private: 
	string m_nom;
	string m_prenom;
	int m_id;
	vector <Produit> m_panier;
};

std::ostream &operator<<(std::ostream &out, Client &client);
bool operator==(Client client, Client client2);

#endif