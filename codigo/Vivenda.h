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
	Vivenda(string morada, int areaHabitacao, int areaExterior, bool temPiscina);
	// mensalidadeHabitacao + 0.1 * areaExterior + 10 * temPiscina
	float mensalidade() const;
};

#endif /* SRC_VIVENDA_H_ */
