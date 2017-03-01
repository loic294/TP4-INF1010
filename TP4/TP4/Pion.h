
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#pragma once

#ifndef PION_H
#define PION_H


#include "Piece.h"
#include <string>

using namespace std;

class Pion : public Piece {

public:
	// Constructeurs
	Pion();
	Pion(const string& id, const string & couleur, int positionX, int positionY);

	// Destructeur
	virtual ~Pion();
	
	bool obtenirEstPositionInitiale() const;
	void setEstPositionInitiale(bool estPositionInitiale);

	bool estMouvementValide(int toX, int toY);
	virtual bool deplacer(int toX, int toY);
	virtual string obtenirType() const;

private:
	bool estPositionInitiale_;

};
#endif
