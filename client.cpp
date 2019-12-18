/** 
  * Fichier:  client.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Client
  */

#include "client.h"

// Constructeur de Client
Client::Client(string nom, string prenom): m_nom(nom), m_prenom(prenom){
	m_id=0;
}

// Getters 
string Client::getNom(){
	return m_nom;
}
	
string Client::getPrenom(){
	return m_prenom; 
}

int Client::getID(){
	return m_id;
}
	
vector <Produit> Client::getPanier(){
	return m_panier;
}

// Fonction d'ajout d'un produit au panier du client
void Client::ajouterAuPanier(Produit produit){
	m_panier.push_back(produit);
}

// Fonction de retrait d'un produit du panier du client 
void Client::retirerDuPanier(Produit produit){
	bool check=false; int i=0;
	while(check==false && i<m_panier.size()){
		if(m_panier.at(i)==produit){
			m_panier.erase(m_panier.begin()+i);
			check=true; 
		}
	}
}

// Fonction pour supprimer le panier d'un client 
void Client::viderPanier(){
	m_panier.clear();
}

// Fonction pour modifier la quantité d'un produit du panier du client
void Client::modifierQuantiteProduit(Produit produit, int quantite){
	int compteur=0;
	for(int i=0;i<m_panier.size();i++){
		if(produit==m_panier.at(i)){
			compteur++;
		}
	}
	if(quantite>compteur){
		for(int i=0;i<quantite-compteur;i++){
			m_panier.push_back(produit);
		}
	}
}

// Fonction pour obtenir la description du panier (tous les produits) du client 
string Client::getDescription(){
	string out="";
	out=m_nom+" "+m_prenom+" \nPANIER : \n";
	for(int i=0; i<m_panier.size();i++){
		out+="======================================Produit n°"+to_string(i+1)+"======================================\n";
		out+=m_panier.at(i).getDescriptionComplete();
	}
	return out;
}

// Fonction pour obtenir les infos du client 
string Client::getInfos(){
	string out=m_nom+" "+m_prenom;
	return out;
}

// Envoi du client et de son panier vers le flux de sortie avec l'opérateur <<
std::ostream &operator<<(std::ostream &out, Client &client)
{
	out<<"Nom du client : "<<client.getDescription()<<"\n";
	return out;
}

// Comparaison de deux clients 
bool operator==(Client client, Client client2){
	if(client.getNom()==client2.getNom() && client.getPrenom()==client2.getPrenom()){
		return true;
	}
	else return false; 
}