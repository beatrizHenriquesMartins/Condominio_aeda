/*
 * Apartamento.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Apartamento.h"

Apartamento::Apartamento(string morada, int areaHabitacao, int tipologia, int piso) : Habitacao(morada, areaHabitacao) {
	this->tipologia = tipologia;
	this->piso = piso;
}

float Apartamento::mensalidade() const {
	return Habitacao::mensalidade() + piso + tipologia;
}

int Apartamento::getTipologia() const {
	return tipologia;
}

int Apartamento::getPiso() const {
	return piso;
}
