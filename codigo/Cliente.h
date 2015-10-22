/*
 * Cliente.h
 *
 *  Created on: 22/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <iostream>
#include <vector>
#include "Habitacao.h"

using namespace std;

class Cliente {
	string nome;
	int bi;
	vector<Habitacao *> habitacoes;
public:
	Cliente(string nome, int bi, vector<Habitacao *> habitacoes);
	vector<Habitacao *> getHabitacoes() const;
	void adicionaHabitacao(Habitacao * habitacao);
};

#endif /* SRC_CLIENTE_H_ */
