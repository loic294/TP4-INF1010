
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 f�vrier 2017
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
///	param [in] positionY	La position des ordonn�es
Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
}

/// Initialise une nouvelle instance de la classe Reine
/// param [in] pion			Un pion
Reine::Reine(const Pion& pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {
}

/// Destructeur
Reine::~Reine() {}

/// V�rifier si le mouvement est valide
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonn�es
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

/// D�placer le pion � la position sp�cifi�e
/// param [in] toX		Position de destination sur l'axe des abcisses
/// param [in] toY		Position de destination sur l'axe des ordonn�es
bool Reine::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}

/// Affiche les informations de la pi�ce.
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