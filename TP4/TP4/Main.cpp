
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

/**************************************************
* Réponse aux questions:
* 1. Piece est une classe abstraite puisqu'on ne peut pas directement créer un objet de Piece. Elle est utilisée comme une base pour les sous-classes. 
* 2. Il permet de s'assurer que le bon destructeur est appelé. Sinon, le destructeur de la classe mère va avoir priorité. 
* 3. On aurait pu créer une extension de Roi et simplement changer les les méthodes qui sont différentes (ex: afficher).
**************************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
#include "Echiquier.h"
#include "Reine.h"

#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	//1-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2
	Pion* pions1[8];
	for (size_t i = 0; i < 8; i++)
	{
		string s1; s1 = (char)(65 + i);
		pions1[i] = new Pion(s1 + "2", "blanc", i, 1);
	}
	
	//2-Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7
	Pion* pions2[8];
	for (size_t i = 0; i < 8; i++)
	{
		string s1; s1 = (char)(65 + i);
		pions2[i] = new Pion(s1 + "7", "noir", i, 6);
	}
	
	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	Tour *tourBlanche1 = new Tour("A1", "blanc", 0, 0);
	Tour *tourBlanche2 = new Tour("H1", "blanc", 7, 0);
	
	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
	Tour *tourNoire1 = new Tour("A8", "noir", 0, 7);
	Tour *tourNoire2 = new Tour("H8", "noir", 7, 7);
	
	//5-  Creez les Fous blanc et noirs
	Fou *fouBlanc1 = new Fou("C1", "blanc", 2, 0);
	Fou *fouBlanc2 = new Fou("F1", "blanc", 5, 0);

	Fou *fouNoir1 = new Fou("C8", "noir", 2, 7);
	Fou *fouNoir2 = new Fou("F8", "noir", 5, 7);

	//6-  Creez les deux reines E1 et E8	
	Reine *reineBlanche = new Reine("E1", "blanc", 4, 0);
	Reine *reineNoire = new Reine("E1", "noir", 4, 7);

	//7-  Creez les deux rois D1 et D8
	Roi* roiBlanc = new Roi("D1", "blanc", 3, 0);
	Roi* roiNoir = new Roi("D8", "noir", 3, 7);
	
	// 8- Creez un echiquier 
	Echiquier unEchiquier;

	
	cout << "----------AJOUT DES PIECES----------" << endl;
	//9- Ajoutez toutes les pièces précidament définies à l'echiquier	
	for (size_t i = 0; i < 8; i++) {
		unEchiquier += pions1[i];
	}
	for (size_t i = 0; i < 8; i++)
	{
		unEchiquier += pions2[i];
	}

	unEchiquier += tourBlanche1;
	unEchiquier += tourBlanche2;
	unEchiquier += tourNoire1;
	unEchiquier += tourNoire2;
	unEchiquier += fouBlanc1;
	unEchiquier += fouBlanc2;
	unEchiquier += fouNoir1;
	unEchiquier += fouNoir2;
	unEchiquier += reineBlanche;
	unEchiquier += reineNoire;
	unEchiquier += roiBlanc;
	unEchiquier += roiNoir;
	
	cout << "----------TEST DES DEPLACEMENTS------------" << endl;
	//10-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion
	unEchiquier.deplacerPiece("A2", 0, 2);
	
	//11-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion
	unEchiquier.deplacerPiece("H7", 7, 4);
	
	//12-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion
	unEchiquier.deplacerPiece("A2", 0, 4);
	
	//13-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	unEchiquier.deplacerPiece("H8", 7, 6);
	
	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	unEchiquier.deplacerPiece("H2", 7, 6);
	
	//15-  Enlever la piece d'id A2 
	unEchiquier -= "A2";

	cout << "----------TEST DES PROMOTIONS------------" << endl;
	
	//16- Promouvoir la piece d'id F6.
	unEchiquier.promouvoir("F6");
	
	//17- Promouvoir la piece d'id B2.	
	unEchiquier.promouvoir("B2");

	//18- Affichage de l'Echiquier
	cout << unEchiquier;
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;

	//delete unEchiquier;

	for (size_t i = 0; i < 8; i++)
	{
		delete pions1[i];
	}

	for (size_t i = 0; i < 8; i++)
	{
		delete pions2[i];
	}

	delete tourBlanche1;
	delete tourBlanche2;
	delete tourNoire1;
	delete tourNoire2;
	delete fouBlanc1;
	delete fouBlanc2;
	delete fouNoir1;
	delete fouNoir2;
	delete reineBlanche;
	delete reineNoire;
	delete roiBlanc;
	delete roiNoir;

	return 0;
}

