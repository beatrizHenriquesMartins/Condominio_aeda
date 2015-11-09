/*
 * Canalizacao.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_CANALIZACAO_H_
#define SRC_CANALIZACAO_H_

#include "Empregado.h"

class Canalizacao: public Empregado {
public:
	/**
	 * @brief Função que cria um empregado canalizador.
	 * @param nome - nome do empregado.
	 * @param bi - número do bilhete de identidade.
	 * @param tipo - o tipo deve ser "canalizador", caso contrário é lançada uma exceção.
	 * @param livre - se for verdadeiro então o empregado está livre, caso contrário está ocupado.
	 */
	Canalizacao(string nome, int bi, string tipo, bool livre);
};

#endif /* SRC_CANALIZACAO_H_ */
