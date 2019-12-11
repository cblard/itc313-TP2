/** 
  * Fichier:  main.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Décembre 2019 
  * Cours:    TP2 C++ 
  * Résumé:   Fichier main utilisé pour le TP2
  */

#include <iostream>
#include "magasin.h"

int main(){
	Magasin magasin(); 
	Produit produit("PS4", "Console Sony", 10, 299.99);
	cout<<produit;
	return 0;
}