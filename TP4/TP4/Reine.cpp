
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#include "Reine.h"
#include "Fou.h"
#include "Tour.h"
#include "Pion.h"

Reine::Reine() : Piece("defaultId", "blanc", 0, 0) {}

/// Initialise une nouvelle instance de la classe Fou
/// param [in] id			identifiant
/// param [in] couleur		La couleur
/// param [in] positionX	La position des abcisses
///	param [in] positionY	La position des ordonnées
Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
}

/// Initialise une nouvelle instance de la classe Reine
/// param [in] pion			Un pion
Reine::Reine(const Pion& pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {
}

/// Destructeur
Reine::~Reine() {}

/// Vérifier si le mouvement est valide
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Reine::estMouvementValide(int toX, int toY) {
	Fou fou;
	fou.modifierPositionX(obtenirPositionX());
	fou.modifierPositionY(obtenirPositionY());
	Tour tour;
	tour.modifierPositionX(obtenirPositionX());
	tour.modifierPositionY(obtenirPositionY());
	if (fou.estMouvementValide(toX, toY) || tour.estMouvementValide(toX, toY))
		return true;
	else
		return false;
}

/// Déplacer le pion à la position spécifiée
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonnées
bool Reine::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}

/// Affiche les informations de la pièce.
/// param [in] stream	Stream pour la sortie dans la console
ostream&  Reine::afficher(ostream& stream) const {
	stream << "Reine, Piece " << obtenirCouleur() << " d'id " << obtenirId() << " : " << endl;
	stream << "Position (" << obtenirPositionX() << ", " << obtenirPositionY() << ")" << endl;
	return stream;
}

/// Donne le type de la classe
string Reine::obtenirType() const {
	return typeid(this).name();
}