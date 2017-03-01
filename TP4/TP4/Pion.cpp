
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#include "Pion.h"



Pion::Pion():Piece("defaultId","blanc",0,0),estPositionInitiale_(true){
}

/// Initialise une nouvelle instance de la classe Fou
/// param [in] id			identifiant
/// param [in] couleur		La couleur
/// param [in] positionX	La position des abcisses
///	param [in] positionY	La position des ordonnées
Pion::Pion(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
	estPositionInitiale_ = true;
}

/// Destructeur
Pion::~Pion() {
}

/// Permet d'obtenir si c'est la position initiale
bool Pion::obtenirEstPositionInitiale() const{
	return estPositionInitiale_;
}

/// Permet d'indique si c'est la position initiale
/// param [in] estPositionInitiale	État de la posisiton initiale
void Pion::setEstPositionInitiale(bool estPositionInitiale) {
	estPositionInitiale_ = estPositionInitiale;
}

/// Vérifier si le mouvement est valide
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Pion::estMouvementValide(int toX, int toY) {
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if (obtenirCouleur() == "blanc") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY > obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if ((toY - obtenirPositionY()) <= 1 && (toX == obtenirPositionX()) 
				&& toY > obtenirPositionY()) {
				return true;
			}
		}
	}
	if (obtenirCouleur() == "noir") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if (((toY - obtenirPositionY()) <= 1) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
	}
	
	return false;
	
}

/// Déplacer le pion à la position spécifiée
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Pion::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		estPositionInitiale_ = false;	
		return true;
	}
	return false;
}

/// Donne le type de la classe
string Pion::obtenirType() const {
	return typeid(this).name();
}