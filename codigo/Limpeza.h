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
	Limpeza(string nome, int bi, string tipo, bool livre);
};

#endif /* SRC_LIMPEZA_H_ */
