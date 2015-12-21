/*
 * Cliente.cpp
 *
 *  Created on: 22/10/2015
 *      Author: teresachaves
 */

#include "Cliente.h"

Cliente::Cliente(string nome, int bi, int numeroTelemovel, string email,
		vector<Habitacao *> habitacoes) {
	this->nome = nome;
	this->bi = bi;
	this->numeroTelemovel = numeroTelemovel;
	this->email = email;
	this->habitacoes = habitacoes;
}

// Sequential Search alterado

int Cliente::existeHabitacao(Habitacao *habitacao) {
	for (unsigned int i = 0; i < habitacoes.size(); i++)
		if (*habitacoes[i] == *habitacao)
			return i; // encontrou
	return -1; // não encontrou
}

int Cliente::adicionaHabitacao(Habitacao *habitacao) {
	if (existeHabitacao(habitacao) == -1) {
		habitacoes.push_back(habitacao);
		return 0;
	} else
		throw HabitacaoExistente(habitacao->getMorada());
}

int Cliente::removeHabitacao(Habitacao *habitacao) {
	int i;

	if ((i = existeHabitacao(habitacao)) != -1) {
		habitacoes.erase(habitacoes.begin() + i);
		return 0;
	} else
		throw HabitacaoInexistente(habitacao->getMorada());
}

vector<Habitacao *> Cliente::getHabitacoes() const {
	return habitacoes;
}

int Cliente::getBI() const {
	return bi;
}

string Cliente::getNome() const {
	return nome;
}

int Cliente::getNumeroTelemovel() const {
	return numeroTelemovel;
}

string Cliente::getEmail() const {
	return email;
}

void Cliente::setNome(string nome) {
	this->nome = nome;
}

void Cliente::setBI(int bi) {
	this->bi = bi;
}

void Cliente::setNumeroTelemovel(int numeroTelemovel) {
	this->numeroTelemovel = numeroTelemovel;
}

void Cliente::setEmail(string email) {
	this->email = email;
}

bool Cliente::operator ==(const Cliente & cliente) {
	return (this->bi == cliente.getBI());
}

bool Cliente::operator <(const Cliente &cliente) {
	return (this->getNome() < cliente.getNome());
}
