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

// Constructeurs de Magasin
Magasin::Magasin(){

}
	
Magasin::Magasin(vector <Produit> produits, vector <Client> clients, vector <Commande> commandes)
: m_produits(produits), m_clients(clients), m_commandes(commandes) {
	
}

// Fonction d'ajout d'un produit au magasin
void Magasin::ajouterProduit(Produit produit){
	m_produits.push_back(produit);
}

// Fonction d'affichage de tous les produits du magasin
void Magasin::afficherProduits(){
	cout<<"         LISTE DES PRODUITS                \n";
	for(int i=0; i<m_produits.size(); i++){
		cout<<m_produits.at(i).getDescriptionComplete();
	}
}

// Fonction d'affichage d'un produit en particulier
void Magasin::afficherProduit(string nom){
	cout<<"         PRODUIT DEMANDÉ             \n";
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			cout<<m_produits.at(i).getDescriptionComplete();
		}
	}
}

// Fonction de mise à jour du stock d'un produit
void Magasin::majStock(string nom, int quantite){
	for(int i=0; i<m_produits.size(); i++){
		if(nom==m_produits.at(i).getTitre()){
			m_produits.at(i).modifierQuantite(quantite);
		}
	}
}

// Fonction d'ajout d'un client au magasin 
void Magasin::ajouterClient(Client client){
	m_clients.push_back(client);
}

// Fonction d'affichage de tous les clients du magasin 
void Magasin::afficherClients(){
	cout<<"\n================= LISTE DES CLIENTS ================\n";
	for(int i=0; i<m_clients.size(); i++){
		cout<<"Client n° "<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
	}
}

// Fonction de recherche d'un client par son nom 
void Magasin::afficherClient(string nom){
	cout<<"\nVous avez recherché : "<<nom<<"\n";
	cout<<"\n================= CLIENTS TROUVÉS =================\n";
	for(int i=0; i<m_clients.size(); i++){
		if(m_clients.at(i).getNom()==nom){
			cout<<"Client n°"<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
		}
	}
}

// Fonction de recherche d'un client par son ID
void Magasin::afficherClient(int id){
	cout<<"\nVous avez recherché l'ID suivante : "<<id<<"\n";
	cout<<"\n================= CLIENTS TROUVÉS =================\n";
	for(int i=0; i<m_clients.size(); i++){
		if(m_clients.at(i).getID()==id){
			cout<<"Client n°"<<i+1<<" : "<<m_clients.at(i).getInfos()<<"\n";
		}
	}
}

// Fonction d'ajout d'un produit au panier d'un client 
void Magasin::ajouterAuPanier(Produit produit, Client client){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).ajouterAuPanier(produit);
			cout<<"\nClient et panifier modifiés : \n";
			cout<<m_clients.at(i);
		}
	}
}

// Fonction de suppression d'un article du panier d'un client
void Magasin::retirerDuPanier(Produit produit, Client client){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).retirerDuPanier(produit);
		}
	}
}

// Fonction de modification de la quantité d'un produit du panier d'un client 
void Magasin::modifierQuantitePanier(Produit produit, Client client, int quantite){
	for(int i=0; i<m_clients.size(); i++){
		if(client==m_clients.at(i)){
			m_clients.at(i).modifierQuantiteProduit(produit, quantite);
		}
	}
}

// Fonction de validation d'une livraison 
void Magasin::validerCommande(Commande commande){
	for(int i=0; i<m_commandes.size(); i++){
		if(m_commandes.at(i)==commande){
			m_commandes.at(i).validerLivraison();
		}
	}
}

// Fonction du changement de statut de la livraison pour une commande
void Magasin::changerStatut(Commande commande, bool statut){
	for(int i=0; i<m_commandes.size(); i++){
		if(m_commandes.at(i)==commande){
			m_commandes.at(i).changerStatut(statut);
		}
	}
}

// Fonction d'affichage de toutes les commandes du magasin 
void Magasin::afficherCommandes(){
	for(int i=0; i<m_commandes.size(); i++){
		cout<<m_commandes.at(i);
	}
}

// Fonction d'affichage de toutes les commandes d'un client 
void Magasin::afficherCommandesClient(Client client){
	for(int i=0; i<m_commandes.size(); i++){
		if(m_commandes.at(i).getClient()==client.getInfos()){
			cout<<m_commandes.at(i);
		}
	}
}