/** 
  * Fichier:  commande.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Commande
  */

#include "commande.h"

// Constructeur
Commande::Commande(Client client, vector <Produit> produits) : m_client(client), m_produits(produits){
  m_statut=false; 
}

// Fonction pour donner les informations d'un client 
string Commande::getClient(){
	string nom=m_client.getNom();
	string prenom=m_client.getPrenom();
	return nom+" "+prenom; 
}

// Fonction pour valider la livraison d'une commande
void Commande::validerLivraison(){
	m_statut=true;
}

// Fonction d'affichage de la description d'une commande (Client concerné, description des produits et statut de la commande)
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

// Fonction de changement de statut de la livraison d'une commande
void Commande::changerStatut(bool statut){
  m_statut=statut;
}

// Envoi de la description d'une commande vers le flux de sortie avec l'opérateur <<
ostream &operator<<(std::ostream &out, Commande &commande){
  out<<commande.getDescription();
  return out;
}

// Comparaison de deux commandes 
bool operator==(Commande commande1, Commande commande2){
  if(commande1.getClient()==commande2.getClient() && commande1.getDescription()==commande2.getDescription()){
      return true;
  }
  else return false;
}