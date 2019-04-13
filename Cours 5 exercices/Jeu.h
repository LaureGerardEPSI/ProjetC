#pragma once

#ifndef JEU_H
#define JEU_H

#include "Coup.h"
#include "Joueur.h"

#include <iostream>
#include <vector>
using namespace std;


class Jeu
{
public:
	Jeu();
	~Jeu();

	void lancerJeu();
	void afficherPlateau();
	void modifierPlateau(Coup* coup);
	Joueur* getJoueur1();
	Joueur* getJoueur2();
	int validerPlateau();

private:
	Joueur* m_joueur1;
	Joueur* m_joueur2;
	// Valeurs des cases à afficher
	vector<char> m_valeurs;
};

#endif

