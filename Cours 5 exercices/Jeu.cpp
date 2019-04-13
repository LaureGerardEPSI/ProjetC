#include "pch.h"
#include "Jeu.h"




Jeu::Jeu()
{
	m_joueur1 = new Joueur(1);
	m_joueur2 = new Joueur(2);
	m_valeurs = { '0','1','2','3','4','5','6','7','8','9' };
}


Jeu::~Jeu()
{
	system("cls");// efface la console 
	m_joueur1->~Joueur();
	m_joueur2->~Joueur();
}

void Jeu::lancerJeu()
{
	this->afficherPlateau();

	int joueur = 1;
	int gagnant = 0;

	while (gagnant == 0) {
		//coup du joueur
		this->modifierPlateau((joueur % 2) ? m_joueur1->jouer() : m_joueur2->jouer());
		//affichage du nouveau jeu
		this->afficherPlateau();
		// validation du jeu
		gagnant = this->validerPlateau();
		// changement de joueur
		joueur = (joueur % 2) ? 2 : 1;
	}
	// definition du gagnant
	if (gagnant == -1)
		cout << "Aucun gagnant." << endl;
	else
		cout << "Bravo " << ((gagnant == 1) ? this->getJoueur1()->getNom() : this->getJoueur2()->getNom()) << endl;
}

void Jeu::afficherPlateau()
{
	system("cls"); // efface la console 
	cout << "Bienvenue dans votre jeu du Morpion" << endl;
	cout << m_joueur1->getNom() << " (X)  -  " << m_joueur2->getNom() << " (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << m_valeurs[1] << "  |  " << m_valeurs[2] << "  |  " << m_valeurs[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << m_valeurs[4] << "  |  " << m_valeurs[5] << "  |  " << m_valeurs[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << m_valeurs[7] << "  |  " << m_valeurs[8] << "  |  " << m_valeurs[9] << endl;
	cout << "     |     |     " << endl << endl;
}

void Jeu::modifierPlateau(Coup * coup)
{
	if (m_valeurs[coup->getChoix()] != 'X' && m_valeurs[coup->getChoix()] != 'O')
		m_valeurs[coup->getChoix()] = coup->getSymbole();
}

Joueur * Jeu::getJoueur1()
{
	return m_joueur1;
}

Joueur * Jeu::getJoueur2()
{
	return m_joueur2;
}

int Jeu::validerPlateau()
{
	int gagnant = 0;

	if (m_valeurs[1] == m_valeurs[2] && m_valeurs[2] == m_valeurs[3])
		gagnant = (m_valeurs[1] == 'X') ? 1 : 2;
	else if (m_valeurs[4] == m_valeurs[5] && m_valeurs[5] == m_valeurs[6])
		gagnant = (m_valeurs[4] == 'X') ? 1 : 2;
	else if (m_valeurs[7] == m_valeurs[8] && m_valeurs[8] == m_valeurs[9])
		gagnant = (m_valeurs[7] == 'X') ? 1 : 2;
	else if (m_valeurs[1] == m_valeurs[4] && m_valeurs[4] == m_valeurs[7])
		gagnant = (m_valeurs[1] == 'X') ? 1 : 2;
	else if (m_valeurs[2] == m_valeurs[5] && m_valeurs[5] == m_valeurs[8])
		gagnant = (m_valeurs[2] == 'X') ? 1 : 2;
	else if (m_valeurs[3] == m_valeurs[6] && m_valeurs[6] == m_valeurs[9])
		gagnant = (m_valeurs[3] == 'X') ? 1 : 2;
	else if (m_valeurs[1] == m_valeurs[5] && m_valeurs[5] == m_valeurs[9])
		gagnant = (m_valeurs[1] == 'X') ? 1 : 2;
	else if (m_valeurs[3] == m_valeurs[5] && m_valeurs[5] == m_valeurs[7])
		gagnant = m_valeurs[3];
	else if (m_valeurs[1] != '1' && m_valeurs[2] != '2' && m_valeurs[3] != '3' && m_valeurs[4] != '4' && m_valeurs[5] != '5' && m_valeurs[6] != '6' && m_valeurs[7] != '7' && m_valeurs[8] != '8' && m_valeurs[9] != '9')
		gagnant = -1;

	return gagnant;
}