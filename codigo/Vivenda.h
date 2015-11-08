/*
 * Vivenda.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_VIVENDA_H_
#define SRC_VIVENDA_H_

#include <iostream>
#include "Habitacao.h"

using namespace std;

class Vivenda: public Habitacao {
	int areaExterior;
	bool temPiscina;
public:
	/**
	 * @brief Função que cria uma vivenda.
	 * @param morada - localização geográfica da vivenda.
	 * @param areaHabitacao - area habitacional.
	 * @param areaExterior - area exterior.
	 * @param temPiscina - caso a vivenda tenha piscina então é verdadeiro, caso contrário é falso.
	 */
	Vivenda(string morada, int areaHabitacao, int areaExterior, bool temPiscina);
	/**
	 * @brief Função que calcula o valor da base mensal de condomínio.
	 * @return Retorna o valor da base mensal de condomínio.
	 */
	float mensalidade() const;
	/**
	 * @brief Função para obter a área exterior.
	 * @return Retorna a área exterior.
	 */
	int getAreaExterior() const;
	/**
	 * @brief Função para verificar se a vivenda tem piscina.
	 * @return Retorna verdade se a vivenda tem piscina e falso caso contrário.
	 */
	bool getTemPiscina() const;
};

#endif /* SRC_VIVENDA_H_ */
