/*
 * Condominio.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_CONDOMINIO_H_
#define SRC_CONDOMINIO_H_

#include <iostream>
#include <vector>
#include "Habitacao.h"

using namespace std;

class Condominio {
	vector<Habitacao *> habitacoes;
public:
	Condominio(vector<Habitacao *> habitacoes);
};

#endif /* SRC_CONDOMINIO_H_ */
