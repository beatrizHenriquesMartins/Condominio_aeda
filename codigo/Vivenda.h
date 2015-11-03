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
};

#endif /* SRC_VIVENDA_H_ */
