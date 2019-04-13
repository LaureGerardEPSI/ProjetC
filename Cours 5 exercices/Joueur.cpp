#include "pch.h"
#include "Joueur.h"


Joueur::Joueur(int numero)
{
	m_numero = numero;
	m_nom = "";
	m_symbole = (m_numero == 1) ? 'X' : 'O';
}

Joueur::~Joueur()
{
	// libération en mémoire de chaque coup du joueur
	for (int i = 0; i < m_coups.size(); i++) {
		m_coups[i]->~Coup();
	}
}

string Joueur::getNom()
{
	return m_nom;
}

void Joueur::setNom(string nom)
{
	m_nom = nom;
}

int Joueur::getNumero()
{
	return m_numero;
}

Coup * Joueur::jouer()
{
	int choix = 0;
	while (choix < 1 || choix>9) {
		cout << m_nom << ", entrer votre choix (chiffre compris entre 1 et 9):  ";
		cin >> choix;
	}
	m_coups.push_back(new Coup(choix, m_symbole));
	return m_coups.back();
}

void Joueur::afficherCoups()
{
	for (int i = 0; i < m_coups.size(); i++) {
		cout << "Coup " << i + 1 << ": " << m_coups[0]->getChoix() << endl;
	}
}
