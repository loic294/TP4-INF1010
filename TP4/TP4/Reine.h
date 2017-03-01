#pragma once

/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#ifndef REINE_H
#define REINE_H


#include "Piece.h"
#include "Pion.h"
#include <string>

using namespace std;

class Reine : public Piece {

public:
	Reine();
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	Reine(const Pion& pion);
	virtual ~Reine();

	bool estMouvementValide(int toX, int toY);
	virtual bool deplacer(int toX, int toY);
	virtual ostream&  afficher(ostream& stream) const;
	virtual string obtenirType() const;

};
#endif