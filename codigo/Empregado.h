/*
 * Empregado.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_EMPREGADO_H_
#define SRC_EMPREGADO_H_

#include <string>

using namespace std;

class Empregado {
	string nome;
	int bi;
	string tipo;
	bool livre; //true - livre; false - ocupado;
public:
	Empregado(string nome, int bi, string tipo, bool livre);
	string getNome() const;
	int getBI() const;
	string getTipo() const;
	bool getLivre() const;
	void setLivre(bool livre);
};

#endif /* SRC_EMPREGADO_H_ */
