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
	// Melhorar! verificar se já existe esta habitação no vector de habitações
	habitacoes.push_back(habitacao);
}

int Cliente::getBI() const {
	return bi;
}

string Cliente::getNome() const {
	return nome;
}
