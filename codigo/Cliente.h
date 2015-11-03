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

class Cliente {
	string nome;
	int bi;
	vector<Habitacao *> habitacoes;
public:
	/**
	 * @brief Função que cria um cliente.
	 * @param nome - nome do cliente.
	 * @param bi - número do bilhete de identidade.
	 * @param habitacoes - habitações das quais o cliente é proprietário.
	 */
	Cliente(string nome, int bi, vector<Habitacao *> habitacoes);
	/**
	 * @brief Função para obter as habitações do cliente.
	 * @return Retorna as habitações do cliente.
	 */
	vector<Habitacao *> getHabitacoes() const;
	/**
	 * @brief Torna o cliente proprietário de uma dada habitação.
	 * @param habitacao - habitação que se pretende adicionar.
	 */
	void adicionaHabitacao(Habitacao * habitacao);
};

#endif /* SRC_CLIENTE_H_ */
