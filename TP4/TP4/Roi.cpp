
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#include "Roi.h"

Roi::Roi(): Piece("defaultId", "blanc", 0, 0) {}

/// Initialise une nouvelle instance de la classe Fou
/// param [in] id			identifiant
/// param [in] couleur		La couleur
/// param [in] positionX	La position des abcisses
///	param [in] positionY	La position des ordonnées
Roi::Roi(const string& id, const string& couleur, int positionX, int positionY) : Piece( id,  couleur, positionX, positionY) {
}

/// Destructeur
Roi::~Roi() {}

/// Vérifier si le mouvement est valide
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Roi::estMouvementValide(int toX, int toY)  {
	if (!Piece::estMouvementValide(toX, toY))
		return false;	
	if (abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 0 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 0)
		return true;
	else
		return false;
}

/// Déplacer le pion à la position spécifiée
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Roi::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);		
		return true;
	}
	return false;
}

/// Donne le type de la classe
string Roi::obtenirType() const {
	return typeid(this).name();
}