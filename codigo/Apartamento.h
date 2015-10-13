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

using namespace std;

class Apartamento: public Habitacao {
	string tipologia;
	int areaHabitacional;
	int piso;
	int baseMensal;
public:
	Apartamento(string morada, string tipologia, int areaHabitacional, int piso, int baseMensal);
};

#endif /* SRC_APARTAMENTO_H_ */
