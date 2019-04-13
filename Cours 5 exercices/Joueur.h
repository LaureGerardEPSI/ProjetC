#pragma once

#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Coup.h"
class Coup;

class Joueur
{
public:
	Joueur(int numero);
	~Joueur();

	string getNom();
	void setNom(string nom);

	int getNumero();

	Coup* jouer();
	void afficherCoups();

private:
	string m_nom;

	int m_numero;
	char m_symbole;

	vector<Coup*> m_coups;
};

#endif


