/*
 * Apartamento.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_APARTAMENTO_H_
#define SRC_APARTAMENTO_H_

#include <iostream>
#include "Habitacao.h"

class Apartamento: public Habitacao {
	int tipologia;
	int piso;
public:
	/**
	 * @brief Função que cria um apartamento.
	 * @param morada - localização geográfica do apartamento.
	 * @param areaHabitacao - area habitacional.
	 * @param tipologia - tipo de apartamento, em que 1 equivale a T1, 2 a T2, etc. ...
	 * @param piso - andar do apartamento.
	 */
	Apartamento(string morada, int areaHabitacao, int tipologia, int piso);
	/**
	 * @brief Função que calcula o valor da base mensal de condomínio.
	 * @return Retorna o valor da base mensal de condomínio.
	 */
	float mensalidade() const;
	/**
	 * @brief Função para obter a tipologia.
	 * @return Retorna a tipologia.
	 */
	int getTipologia() const;
	/**
	 * @brief Função para obter o piso.
	 * @return Retorna o piso.
	 */
	int getPiso() const;
};

#endif /* SRC_APARTAMENTO_H_ */
