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
	int areaHabitacional;
	int areaExterior;
	bool temPiscina;
	int baseMensal;
public:
	Vivenda(string morada, int areaHabitacional, int areaExterior, bool temPiscina, int baseMensal);
};

#endif /* SRC_VIVENDA_H_ */
