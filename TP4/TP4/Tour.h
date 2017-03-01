
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Tour : public Piece {

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	bool estMouvementValide(int toX, int toY);
	virtual bool deplacer(int toX, int toY);
	virtual string obtenirType() const;
};
#endif