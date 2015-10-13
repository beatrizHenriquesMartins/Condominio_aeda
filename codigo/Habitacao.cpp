/*
 * Habitacao.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Habitacao.h"

Habitacao::Habitacao(string morada, int areaHabitacao) {
	this->morada = morada;
	this->areaHabitacao = areaHabitacao;
}

float Habitacao::mensalidade() const {
	return 50 + 0.2 * areaHabitacao;
}