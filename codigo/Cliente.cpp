/*
 * Cliente.cpp
 *
 *  Created on: 22/10/2015
 *      Author: teresachaves
 */

#include "Cliente.h"

Cliente::Cliente(string nome, int bi, vector<Habitacao *> habitacoes) {
	this->nome = nome;
	this->bi = bi;
	this->habitacoes = habitacoes;
}

vector<Habitacao *> Cliente::getHabitacoes() const {
	return habitacoes;
}

void Cliente::adicionaHabitacao(Habitacao * habitacao) {
	habitacoes.push_back(habitacao);
}
