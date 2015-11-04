/*
 * Habitacao.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_HABITACAO_H_
#define SRC_HABITACAO_H_

#include <iostream>
#include <vector>
#include "Empregado.h"

using namespace std;

class Habitacao {
	string morada;
	int areaHabitacao;
	vector<Empregado *> servicos; // Histórico de serviços da habitação
public:
	/**
	 * @brief Função que cria uma habitação.
	 * @param morada - localização geográfica da habitação.
	 * @param areaHabitacao - area habitacional.
	 */
	Habitacao(string morada, int areaHabitacao);
	virtual ~Habitacao() {

	}
	;
	/**
	 * @brief Função que calcula o valor da base mensal de condomínio.
	 * @return Retorna o valor da base mensal de condomínio.
	 */
	virtual float mensalidade() const;
	/**
	 * @brief Função para obter a morada da habitação.
	 * @return Retorna a morada da habitação.
	 */
	string getMorada() const;
	/**
	 * @brief Função para obter a area habitacional.
	 * @return Retorna a area habitacional.
	 */
	int getAreaHabitacao() const;
	/**
	 * @brief Operador para verificar se duas habitações são a mesma.
	 * @param hab - habitação externa com a qual vai ser comparada a habitação.
	 * @return Retorna verdade caso as habitações sejam a mesma e falso caso contrário.
	 */
	bool operator==(const Habitacao & hab);
	/**
	 * @brief Adiciona um serviço ao histórico de serviços.
	 * @param servico - servico que foi requisitado.
	 */
	void adicionaServico(Empregado *servico);
};

#endif /* SRC_HABITACAO_H_ */
