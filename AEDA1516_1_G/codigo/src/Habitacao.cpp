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

void Habitacao::adicionaServico(Empregado *servico) {
	servicos.push_back(servico);
}

void Habitacao::getInformacoes() const {
	cout << "Morada: " << getMorada() << endl;
	cout << "Área Habitacional: " << getAreaHabitacao() << endl;
}

string Habitacao::getMorada() const {
	return morada;
}

int Habitacao::getAreaHabitacao() const {
	return areaHabitacao;
}

vector<Empregado *> Habitacao::getServicos() const {
	return servicos;
}

void Habitacao::setMorada(string morada) {
    this->morada = morada;
}

void Habitacao::setAreaHabitacao(int areaHabitacao) {
    this->areaHabitacao = areaHabitacao;
}

void Habitacao::setServicos(vector<Empregado *> servicos) {
    this->servicos = servicos;
}

bool Habitacao::operator ==(const Habitacao & hab) {
	return this->morada == hab.morada;
}
