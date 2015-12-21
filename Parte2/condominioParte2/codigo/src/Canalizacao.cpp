/*
 * Canalizacao.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Canalizacao.h"

Canalizacao::Canalizacao(string nome, int bi, int numeroTelemovel, string email,
		string tipo, bool livre) :
		Empregado(nome, bi, numeroTelemovel, email, tipo, livre) {
	if (tipo != "Canalizacao")
		cout << "Atenção! Foi criado um canalizador com o tipo " << tipo
				<< ", com o bi " << bi << "." << endl;
}
