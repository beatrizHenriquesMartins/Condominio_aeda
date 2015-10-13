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
	int piso;
public:
	Apartamento(string morada, int areaHabitacao, string tipologia, int piso);
	float mensalidade() const;
};

#endif /* SRC_APARTAMENTO_H_ */
