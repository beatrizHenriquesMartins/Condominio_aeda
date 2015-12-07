/*
 * Cliente.cpp
 *
 *  Created on: 22/10/2015
 *      Author: teresachaves
 */

#include "Cliente.h"

Cliente::Cliente(string nome, int bi, vector<Habitacao *> habitacoes,
		int numeroTelemovel, string email) {
	this->nome = nome;
	this->bi = bi;
	this->habitacoes = habitacoes;
	this->numeroTelemovel = numeroTelemovel;
	this->email = email;
}

vector<Habitacao *> Cliente::getHabitacoes() const {
	return habitacoes;
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

int Cliente::getBI() const {
	return bi;
}

string Cliente::getNome() const {
	return nome;
}

bool Cliente::operator ==(const Cliente & cliente) {
	return (this->bi == cliente.getBI());
}

//
void Cliente::setNome(string nome) {
	this->nome = nome;
}

void Cliente::setBI(int bi) {
	this->bi = bi;
}

int Cliente::getNumeroTelemovel() const {
	return numeroTelemovel;
}

void Cliente::setNumeroTelemovel(int numeroTelemovel) {
	this->numeroTelemovel = numeroTelemovel;
}

string Cliente::getEMail() const {
	return email;
}

void Cliente::setEmail(string email) {
	this->email = email;
}

bool Cliente::operator <(const Cliente &cliente) {
	return (this->getNome() < cliente.getNome());
}
