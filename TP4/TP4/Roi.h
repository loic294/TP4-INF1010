
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#ifndef ROI_H
#define ROI_H


#include "Piece.h"
#include <string>

using namespace std;

class Roi : public Piece{

public :
	Roi();
	Roi(const string& id, const string& couleur, int positionX, int positionY);
	virtual ~Roi();	

	bool estMouvementValide(int toX, int toY);  
	virtual bool deplacer(int toX, int toY);
	virtual string obtenirType() const;

};
#endif