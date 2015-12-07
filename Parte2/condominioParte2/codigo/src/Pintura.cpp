/*
 * Pintura.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Pintura.h"

Pintura::Pintura(string nome, int bi, string tipo, bool livre,
		int numeroTelemovel, string email) :
		Empregado(nome, bi, tipo, livre, numeroTelemovel, email) {
	if (tipo != "Pintura")
		cout << "Atenção! Foi criado um pintor com o tipo " << tipo
				<< ", com o bi " << bi << "." << endl;
}
