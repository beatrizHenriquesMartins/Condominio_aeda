/*
 * Apartamento.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Apartamento.h"

Apartamento::Apartamento(string morada, int areaHabitacao, string tipo, int tipologia,
		int piso) :
		Habitacao(morada, areaHabitacao, tipo) {
	this->tipologia = tipologia;
	this->piso = piso;
}

float Apartamento::mensalidade() const {
	return Habitacao::mensalidade() + piso + tipologia;
}

void Apartamento::getInformacoes() const {
	Habitacao::getInformacoes();
	cout << "Tipologia: " << getTipologia() << endl;
	cout << "Piso: " << getPiso() << endl;
}

int Apartamento::getTipologia() const {
	return tipologia;
}

int Apartamento::getPiso() const {
	return piso;
}

void Apartamento::setTipologia(int tipologia) {
	this->tipologia = tipologia;
}

void Apartamento::setPiso(int piso) {
	this->piso = piso;
}
