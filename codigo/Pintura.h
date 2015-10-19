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
	Pintura(string nome, int bi, string tipo, bool livre);
};

#endif /* SRC_PINTURA_H_ */
