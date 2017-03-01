
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#include "Tour.h"

Tour::Tour() :Piece("defaultId", "blanc", 0, 0){
}

/// Initialise une nouvelle instance de la classe Fou
/// param [in] id			identifiant
/// param [in] couleur		La couleur
/// param [in] positionX	La position des abcisses
///	param [in] positionY	La position des ordonnées
Tour::Tour(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY){
}

/// Initialise une nouvelle instance de la classe Fou
/// param [in] pion			Un pion
Tour::Tour(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()){
}

/// Destructeur
Tour::~Tour(){
}

/// Vérifier si le mouvement est valide
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Tour::estMouvementValide(int toX, int toY) {
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))		
		return true;
	else
		return false;
}

/// Déplacer le pion à la position spécifiée
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Tour::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}

/// Donne le type de la classe
string Tour::obtenirType() const {
	return typeid(this).name();
}