#pragma once

#ifndef COUP_H
#define COUP_H
class Coup
{
public:
	Coup(int choix, char symbole);
	~Coup();

	int getChoix();
	char getSymbole();

private:
	// numero de la case 
	int m_choix;
	// symbole à afficher
	char m_symbole;

};
#endif

