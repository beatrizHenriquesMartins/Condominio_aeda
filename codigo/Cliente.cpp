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

// Sequential Search alterado

bool Cliente::existeHabitacao(Habitacao *habitacao) {
	for (unsigned int i = 0; i < habitacoes.size(); i++)
		if (*habitacoes[i] == *habitacao)
			return true;// encontrou
	return false; // não encontrou
}

void Cliente::adicionaHabitacao(Habitacao * habitacao) {
	if(!existeHabitacao(habitacao))
		habitacoes.push_back(habitacao);
	else
		throw HabitacaoExistente(habitacao->getMorada());
}

int Cliente::getBI() const {
	return bi;
}

string Cliente::getNome() const {
	return nome;
}

bool Cliente::operator ==(const Cliente & cliente) {
	return (this->bi == cliente.getBI());
}
