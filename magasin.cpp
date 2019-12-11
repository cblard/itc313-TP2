/** 
  * Fichier:  magasin.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Définition de la classe Magasin
  */

#include "magasin.h"
#include <iostream>
using namespace std;

Magasin::Magasin(){

}
	
Magasin::Magasin(vector <Produit> produits, vector <Client> clients, vector <Commande> commandes)
: m_produits(produits), m_clients(clients), m_commandes(commandes) {
	
}

void Magasin::ajouterProduit(Produit produit){
	m_produits.push_back(produit);
}

void Magasin::afficherProduits(){
	cout<<"         LISTE DES PRODUITS                \n";
	for(int i=0; i<m_produits.size(); i++){
		cout<<m_produits.at(i).getDescriptionComplete();
	}
}

void Magasin::afficherProduit(string nom){
	cout<<"         PRODUIT DEMANDÉ             \n";
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			cout<<m_produits.at(i).getDescriptionComplete();
		}
	}
}

void Magasin::majStock(string nom, int quantite){
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			m_produits.at(i).modifierQuantite(quantite);
		}
	}
}

void Magasin::ajouterClient(Client client){
	m_clients.push_back(client);
}

void Magasin::afficherClients(){
	cout<<"\n================= LISTE DES CLIENTS ================\n";
	for(int i=0; i<m_clients.size(); i++){
		cout<<"Client n° "<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
	}
}

void Magasin::afficherClient(string nom){
	cout<<"\nVous avez recherché : "<<nom<<"\n";
	cout<<"\n================= CLIENTS TROUVÉS =================\n";
	for(int i=0; i<m_clients.size(); i++){
		if(m_clients.at(i).getNom()==nom){
			cout<<"Client n°"<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
		}
	}
}

void Magasin::afficherClient(int id){
	cout<<"\nVous avez recherché l'ID suivante : "<<id<<"\n";
	cout<<"\n================= CLIENTS TROUVÉS =================\n";
	for(int i=0; i<m_clients.size(); i++){
		if(m_clients.at(i).getID()==id){
			cout<<"Client n°"<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
		}
	}
}

void Magasin::ajouterAuPanier(Produit produit, Client client){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).ajouterAuPanier(produit);
			cout<<"\nClient et panifier modifiés : \n";
			cout<<m_clients.at(i);
		}
	}
}

void Magasin::retirerDuPanier(Produit produit, Client client){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).retirerDuPanier(produit);
		}
	}
}

void Magasin::modifierQuantitePanier(Produit produit, Client client, int quantite){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).modifierQuantiteProduit(produit, quantite);
		}
	}
}