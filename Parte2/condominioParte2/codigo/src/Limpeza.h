/*
 * Limpeza.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_LIMPEZA_H_
#define SRC_LIMPEZA_H_

#include "Empregado.h"

class Limpeza: public Empregado {
public:
	/**
	 * @brief Função que cria um empregado de limpeza.
	 * @param nome - nome do empregado.
	 * @param bi - número do bilhete de identidade.
	 * @param tipo - o tipo deve ser "limpeza", caso contrário é lançada uma exceção.
	 * @param livre - se for verdadeiro então o empregado está livre, caso contrário está ocupado.
	 */
	Limpeza(string nome, int bi, string tipo, bool livre, int numeroTelemovel,
			string email);
};

#endif /* SRC_LIMPEZA_H_ */
