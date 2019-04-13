#include "pch.h"
#include "Coup.h"



Coup::Coup(int choix, char symbole)
{
	m_choix = choix;
	m_symbole = symbole;
}

Coup::~Coup()
{
}

int Coup::getChoix()
{
	return m_choix;
}

char Coup::getSymbole()
{
	return m_symbole;
}
