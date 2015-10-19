/*
 * Condominio.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_CONDOMINIO_H_
#define SRC_CONDOMINIO_H_

#include <iostream>
#include <vector>
#include "Habitacao.h"
#include "Servico.h"

using namespace std;

class Condominio {
	string nome;
	int nif;
	vector<Habitacao *> habitacoes;
	Servico * servico;
public:
	Condominio(string nome, int nif, vector<Habitacao *> habitacoes, Servico * servico);
	void adicionaHabitacao(Habitacao * habitacao);
	float pagarMensalidade(Habitacao * habitacao) const; // retorna -1 caso a habitação não exista
	int requesitaServico(string tipo);
	int fimDoServico(Empregado * empregado);
};

#endif /* SRC_CONDOMINIO_H_ */
