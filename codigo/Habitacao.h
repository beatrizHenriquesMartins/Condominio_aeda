/*
 * Habitacao.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_HABITACAO_H_
#define SRC_HABITACAO_H_

#include <iostream>

using namespace std;

class Habitacao {
	string morada;
	int areaHabitacao;
public:
	Habitacao(string morada, int areaHabitacao);
	virtual ~Habitacao() {

	}
	;
	virtual float mensalidade() const;
	string getMorada() const;
	bool operator==(const Habitacao & hab);
};

#endif /* SRC_HABITACAO_H_ */
