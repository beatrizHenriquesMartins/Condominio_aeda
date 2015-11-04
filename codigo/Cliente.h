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
	 * @brief Verifica se uma dada habitação existe nas habitações do cliente.
	 * @param habitacao - habitação que se pretende procurar.
	 * @return Retorna verdade se a habitação pertence às habitações do cliente e falso caso contrário.
	 */
	bool existeHabitacao(Habitacao *habitacao);
	/**
	 * @brief Torna o cliente proprietário de uma dada habitação.
	 * @param habitacao - habitação que se pretende adicionar.
	 */
	void adicionaHabitacao(Habitacao * habitacao);
	/**
	 *@brief Função para obter o número do bilhete de identidade do cliente.
	 *@return Retorna o número do bilhete de identidade do cliente.
	 */
	int getBI() const;
	/**
	 *@brief Função para obter o nome do cliente.
	 *@return Retorna o nome do cliente.
	 */
	string getNome() const;
	/**
	 * @brief Operador para verificar se dois clientes são o mesmo.
	 * @param cliente - cliente externo com a qual vai ser comparado o cliente.
	 * @return Retorna verdade caso os clientes sejam o mesmo e falso caso contrário.
	 */
	bool operator==(const Cliente &cliente);
};

#endif /* SRC_CLIENTE_H_ */
