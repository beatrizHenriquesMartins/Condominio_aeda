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

string Habitacao::getMorada() const {
	return morada;
}

int Habitacao::getAreaHabitacao() const {
	return areaHabitacao;
}

bool Habitacao::operator ==(const Habitacao & hab) {
	return this->morada == hab.morada;
}

void Habitacao::adicionaServico(Empregado *servico) {
	servicos.push_back(servico);
}

vector<Empregado *> Habitacao::getServicos() const {
	return servicos;
}
