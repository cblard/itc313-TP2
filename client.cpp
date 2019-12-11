/** 
  * Fichier:  client.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Client
  */

#include "client.h"

Client::Client(string nom, string prenom): m_nom(nom), m_prenom(prenom){
	m_id=0;
}

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

void Client::ajouterAuPanier(Produit produit){
	m_panier.push_back(produit);
}

void Client::retirerDuPanier(Produit produit){
	bool check=false; int i=0;
	while(check==false && i<m_panier.size()){
		if(m_panier.at(i)==produit){
			m_panier.erase(m_panier.begin()+i);
			check=true; 
		}
	}
}

void Client::viderPanier(){
	m_panier.clear();
}


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

string Client::getDescription(){
	string out="";
	out=m_nom+" "+m_prenom+" \nPANIER : \n";
	for(int i=0; i<m_panier.size();i++){
		out+="======================================Produit n°"+to_string(i+1)+"======================================\n";
		out+=m_panier.at(i).getDescriptionComplete();
	}
	return out;
}

string Client::getInfos(){
	string out=m_nom+" "+m_prenom;
	return out;
}

std::ostream &operator<<(std::ostream &out, Client &client)
{
	out<<"Nom du client : "<<client.getDescription()<<"\n";
	return out;
}

bool operator==(Client client, Client client2){
	if(client.getNom()==client2.getNom() && client.getPrenom()==client2.getPrenom()){
		return true;
	}
	else return false; 
}