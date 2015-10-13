/*
 * Condominio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Condominio.h"

Condominio::Condominio(vector<Habitacao *> habitacoes) {
	this->habitacoes = habitacoes;
}

void Condominio::adicionaHabitacao(Habitacao * habitacao) {
	habitacoes.push_back(habitacao);
}

float Condominio::pagarMensalidade(Habitacao * habitacao) const {
	vector<Habitacao *>::const_iterator itb = habitacoes.begin();
	vector<Habitacao *>::const_iterator ite = habitacoes.end();

	for (; itb != ite; itb++) {
		if ((*itb)->getMorada() == habitacao->getMorada())
			return (*itb)->mensalidade();
	}

	return -1;
}
