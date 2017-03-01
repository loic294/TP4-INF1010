
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 février 2017
* Auteur: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
**************************************************/

#include "Echiquier.h"
#include <stdlib.h>  
#include <time.h>
#include "vector"
#include <string>
#include "Reine.h"



/// Constructeur par défaut
Echiquier::Echiquier() {};

/// Destructeur
Echiquier::~Echiquier() {};

/// Deplacer la piece.
/// param [in] id		L'identifiant
/// param [in] toX/		À X
/// param [in] toY		À Y
/// return Ehiquier
bool Echiquier::deplacerPiece(const string& id, int toX, int toY) {
	bool trouve = false;
	bool estValide = false;

	for (size_t i = 0; i < vecteurPiecesBlanches_.size() && !trouve; i++)
	{
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			estValide = vecteurPiecesBlanches_[i]->deplacer(toX, toY);
			trouve = true;
		}
			
	}

	for (size_t i = 0; i < vecteurPiecesNoires_.size() && !trouve; i++)
	{
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			estValide = vecteurPiecesNoires_[i]->deplacer(toX, toY);
			trouve = true;
		}
			
	}

	if(estValide) 
		cout << "Deplacement de la piece reussie" << endl;
	else 
		cout << "Mouvement non valide" << endl;

	return estValide;
};

/// Ajouter une tour.
/// param [in] piece		Piece à ajouter
/// return Echiquier
Echiquier& Echiquier::operator+=(Piece* piece) {

	if (piece->obtenirCouleur() == "blanc") {
		vecteurPiecesBlanches_.push_back(piece);
	}
	else {
		vecteurPiecesNoires_.push_back(piece);
	}

	return *this;

};

/// Enlever la piece.
/// param [in] id		id de la piece à enlever
/// return Echiquier
Echiquier& Echiquier::operator-=(const string& id) {

	bool trouve = false;
	for (size_t i = 0; i < vecteurPiecesBlanches_.size() - 1; i++)
	{
		if (vecteurPiecesBlanches_[i]->obtenirId() == id)
			trouve = true;
		if (trouve)
			vecteurPiecesBlanches_[i] = vecteurPiecesBlanches_[i+1];
		if(i == vecteurPiecesBlanches_.size() - 2 && trouve)
			vecteurPiecesBlanches_.pop_back();
	}

	trouve = false;
	for (size_t i = 0; i < vecteurPiecesNoires_.size() - 1; i++)
	{
		if (vecteurPiecesNoires_[i]->obtenirId() == id)
			trouve = true;
		if (trouve)
			vecteurPiecesNoires_[i] = vecteurPiecesNoires_[i + 1];
		if(i== vecteurPiecesNoires_.size() - 2 && trouve)
			vecteurPiecesNoires_.pop_back();
	}

	return *this;

};

/// Trouve l'indexe d'une pièce
/// param [in] id		id de la piece à trouver
/// return l'index
int Echiquier::obtenirIndexPiece(const string id, string& couleur) {

	for (size_t i = 0; i < vecteurPiecesBlanches_.size(); i++){
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			couleur = "blanc";
			return i;
		}
	}
				
	for (size_t i = 0; i < vecteurPiecesNoires_.size(); i++)
	{
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			couleur = "noir";
			return i;
		}
	}

	return 0;
}

/// Change de type une pièce au hasard
/// param [in] id		id de la piece à promouvoir
/// return bool
bool Echiquier::promouvoir(const string& id) {

	srand(time(NULL));

	string couleur = "aucune";
	int index = obtenirIndexPiece(id, couleur);

	if (vecteurPiecesBlanches_[index]->obtenirType() == "class Pion const *") {

		Pion pion = Pion(vecteurPiecesBlanches_[index]->obtenirId(), vecteurPiecesBlanches_[index]->obtenirCouleur(),
			vecteurPiecesBlanches_[index]->obtenirPositionX(), vecteurPiecesBlanches_[index]->obtenirPositionY());

		if (couleur == "blanc")
			vecteurPiecesBlanches_[index] = new Reine(pion);
		else
			vecteurPiecesNoires_[index] = new Reine(pion);

		if (couleur != "aucune") {
			int val = rand() % 3;
			if (val == 0)
				if (couleur == "blanc")
					vecteurPiecesBlanches_[index] = new Reine(pion);
				else
					vecteurPiecesNoires_[index] = new Reine(pion);
			else if (val == 1)
				if (couleur == "blanc")
					vecteurPiecesBlanches_[index] = new Tour(pion);
				else
					vecteurPiecesNoires_[index] = new Tour(pion);
			else if (val == 2)
				if (couleur == "blanc")
					vecteurPiecesBlanches_[index] = new Fou(pion);
				else
					vecteurPiecesNoires_[index] = new Fou(pion);

			cout << "Promotion reussie" << endl;
			return true;
		}

	}

	
	cout << "Promotion impossible" << endl;
	return false;
	
};

/// Revoie la liste des pièces.
/// param [in] couleur		couleur de la piece.
/// return Echiquier
vector<Piece*> Echiquier::obtenirPieces(const string couleur) const {
	if (couleur == "blanc")
		return vecteurPiecesBlanches_;
	else
		return vecteurPiecesNoires_;
}

/// Affiche la liste de pieces
/// param [in/out] out		 stream de texte 
/// param [in/out] echiquier		Échiquier
/// return Echiquier
std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier) {
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;
	out << "Il y a " << echiquier.obtenirPieces("blanc").size() << " Pieces blanches" << endl;

	for (size_t i = 0; i < echiquier.obtenirPieces("blanc").size(); i++)
	{
		out << *echiquier.obtenirPieces("blanc")[i];
	}

	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl;
	out << "Il y a " << echiquier.obtenirPieces("noir").size() << " Pieces noires" << endl;

	for (size_t i = 0; i < echiquier.obtenirPieces("noir").size(); i++)
	{
		out << *echiquier.obtenirPieces("noir")[i];
	}

	return out;

}
