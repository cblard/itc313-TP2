/** 
  * Fichier:  commande.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Commande
  */

#include "commande.h"

Commande::Commande(Client client, vector <Produit> produits) : m_client(client), m_produits(produits){
  m_statut=false; 
}

string Commande::getClient(){
	string nom=m_client.getNom();
	string prenom=m_client.getPrenom();
	return nom+prenom; 
}

void Commande::validerLivraison(){
	m_statut=true;
}

string Commande::getDescription(){
  string out="Client : "+m_client.getInfos();
  out+="\nPanier : \n";
  for (int i=0; i<m_produits.size(); i++){
    out+=m_produits.at(i).getDescriptionComplete();
  }
  if (m_statut==false) out+="\nSTATUT : Commande en cours.";
  else out+="STATUT : Commande envoyée.";
  return out; 
}

ostream &operator<<(std::ostream &out, Commande &commande){
  out<<commande.getDescription();
  return out;
}

