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
	Canalizacao(string nome, int bi, string tipo, bool livre);
};

#endif /* SRC_CANALIZACAO_H_ */
