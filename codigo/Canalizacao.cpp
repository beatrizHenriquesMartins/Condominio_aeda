/*
 * Canalizacao.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Canalizacao.h"

Canalizacao::Canalizacao(string nome, int bi, string tipo, bool livre) : Empregado(nome, bi, tipo, livre) {
	if(tipo!="Canalizacao")
		cerr << "Atenção! Foi criado um canalizador com o tipo " << tipo << ", com o bi " << bi << "." << endl;
}
