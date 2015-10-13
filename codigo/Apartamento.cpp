/*
 * Apartamento.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Apartamento.h"

Apartamento::Apartamento(string morada, string tipologia, int areaHAbitacional, int piso, int baseMensal): Habitacao(morada) {
	this->tipologia = tipologia;
	this->areaHabitacional = areaHAbitacional;
	this->piso = piso;
	this->baseMensal = baseMensal;
}
