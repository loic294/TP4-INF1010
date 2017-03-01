
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>

using namespace std;

 class Piece {


public :
	// constructeurs
	Piece() {}
	Piece(const string& id, const string& couleur, int positionX, int positionY):id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY){}

	// destructeur
	virtual ~Piece() {};

	// acesseur et modificateur
	string obtenirId() const {
		return id_; 
	}

	void modifierId(const string& id) {
		id_ = id;
	}

	string obtenirCouleur() const { 
		return couleur_;
	}

	void modifierCouleur(const string& couleur) {
		couleur_ = couleur; 
	}

	int obtenirPositionX() const {
		return positionX_; 
	}
	void modifierPositionX(int x) {
		positionX_ = x; 
	}

	int obtenirPositionY() const {
		return positionY_; 
	}

	void modifierPositionY(int y) {
		positionY_ = y;
	}

	
	bool estMouvementValide(int toX, int toY) const{
		if (((positionX_ != toX) || (positionY_ != toY)) && ((toX >= 0) && (toX <= 7)) && ((toY >= 0) && (toY <= 7)))
			return true;
		else
			std::cout << "Deplacement de la piece non autorise" << endl;

		return false;
	} 

     
	virtual bool deplacer(int toX, int toY) { return false; };

	
	virtual string obtenirType() const 	{ 
		return typeid(this).name();
	}

	friend std::ostream& operator<<(std::ostream& out, const Piece& piece)
	{
		return piece.afficher(out);
	}

	                                            
	virtual ostream&  afficher(ostream& stream) const { 
		stream << "Piece " << couleur_ << " d'id " << id_ << " : " << endl;
		stream << "Position (" << positionX_ << ", " << positionY_ << ")" << endl;
		return stream;
	}

private:

	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif