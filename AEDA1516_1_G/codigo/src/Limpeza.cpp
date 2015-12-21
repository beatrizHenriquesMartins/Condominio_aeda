/*
 * Limpeza.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Limpeza.h"

Limpeza::Limpeza(string nome, int bi, int numeroTelemovel, string email,
		string tipo, bool livre) :
		Empregado(nome, bi, numeroTelemovel, email, tipo, livre) {
	if (tipo != "Limpeza")
		cout << "Atenção! Foi criado um empregado de limpeza com o tipo "
				<< tipo << ", com o bi " << bi << "." << endl;
}
