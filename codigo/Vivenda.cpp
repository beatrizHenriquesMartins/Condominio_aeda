/*
 * Vivenda.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Vivenda.h"

Vivenda::Vivenda(string morada, int areaHabitacao, int areaExterior, bool temPiscina) : Habitacao(morada, areaHabitacao) {
	this->areaExterior = areaExterior;
	this->temPiscina = temPiscina;
}

float Vivenda::mensalidade() const {
	return Habitacao::mensalidade() + 0.1 * areaExterior + 10 * temPiscina;
}

int Vivenda::getAreaExterior() const {
	return areaExterior;
}

bool Vivenda::getTemPiscina() const {
	return temPiscina;
}

void Vivenda::getInformacoes() const {
	Habitacao::getInformacoes();
	cout << "Área Exterior: " << getAreaExterior() << endl;
	if(temPiscina)
		cout << "Piscina: Sim" << endl;
	else
		cout << "Piscina: Não" << endl;
}
