/*
 * Pintura.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_PINTURA_H_
#define SRC_PINTURA_H_

#include "Empregado.h"

class Pintura: public Empregado {
public:
	/**
	 * @brief Função que cria um empregado de pintura.
	 * @param nome - nome do empregado.
	 * @param bi - número do bilhete de identidade.
	 * @param numeroTelemovel - número de telemóvel do empregado.
	 * @param email - email do empregado.
	 * @param tipo - o tipo deve ser "pintura", caso contrário é lançada uma exceção.
	 * @param livre - se for verdadeiro então o empregado está livre, caso contrário está ocupado.
	 */
	Pintura(string nome, int bi, int numeroTelemovel, string email, string tipo,
			bool livre);
};

#endif /* SRC_PINTURA_H_ */
