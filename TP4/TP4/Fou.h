
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#ifndef FOU_H
#define FOU_H

#include "Piece.h"
#include <string>
#include "Pion.h"
using namespace std;

class Fou : public Piece {

public:
	// Constructeurs
	Fou();
	Fou(const string& id, const string& couleur, int positionX, int positionY);
	Fou(const Pion& pion);
	// Destructeur
	virtual ~Fou();


	bool estMouvementValide(int toX, int toY) const;
	virtual bool deplacer(int toX, int toY);
	ostream&  afficher(ostream& stream) const;
	virtual string obtenirType() const;

	
};
#endif