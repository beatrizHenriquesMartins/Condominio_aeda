/*
 * Pintura.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Pintura.h"

Pintura::Pintura(string nome, int bi, int numeroTelemovel, string email,
		string tipo, bool livre) :
		Empregado(nome, bi, numeroTelemovel, email, tipo, livre) {
	if (tipo != "Pintura")
		cout << "Atenção! Foi criado um pintor com o tipo " << tipo
				<< ", com o bi " << bi << "." << endl;
}
