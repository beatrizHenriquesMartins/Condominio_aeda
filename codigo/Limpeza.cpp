/*
 * Limpeza.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Limpeza.h"

Limpeza::Limpeza(string nome, int bi, string tipo, bool livre) : Empregado(nome, bi, tipo, livre) {
	if(tipo!="Limpeza")
		cerr << "Atenção! Foi criado um empregado de limpeza com o tipo " << tipo << ", com o bi " << bi << "." << endl;
}
