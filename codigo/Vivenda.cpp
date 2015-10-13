/*
 * Vivenda.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Vivenda.h"

Vivenda::Vivenda(string morada, int areaHabitacional, int areaExterior, bool temPiscina, int baseMensal): Habitacao(morada) {
	this->areaHabitacional = areaHabitacional;
	this->areaExterior = areaExterior;
	this->temPiscina = temPiscina;
	this->baseMensal = baseMensal;
}
