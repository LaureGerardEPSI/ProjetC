// Cours 5 exercices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std;

#include "Jeu.h"
#include "Joueur.h"

int main() {
	// création du jeu 
	Jeu* plateau = new Jeu();

	// création du premier joueur
	string nom;
	cout << "Joueur 1, entrer votre nom " << endl;
	cin >> nom;
	(plateau->getJoueur1())->setNom(nom);

	// création du second joueur
	cout << "Joueur 2, entrer votre nom " << endl;
	cin >> nom;
	(plateau->getJoueur2())->setNom(nom);


	// démarrage du jeu
	plateau->lancerJeu();

	//fin du jeu - attente de l'ordre utilisateur pour quitter l'application
	cout << "Pour quitter taper 0" << endl;
	while (getchar() != '0');

	// libération de la mémoire
	plateau->~Jeu();

	return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
