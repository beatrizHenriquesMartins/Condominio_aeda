/*
 * EmpresaCondominios.cpp
 *
 *  Created on: 21/12/2015
 *      Author: teresachaves
 */

#include "EmpresaCondominios.h"

int EmpresaCondominios::adicionaCondominio(Condominio * condominio) {
	BSTItrIn<Condominio *> itb(condominios);

	//verifica se já existe na empresa
	while (!itb.isAtEnd()) {
		if (itb.retrieve() == condominio) {
			return -1;
		}
		itb.advance();
	}

	condominios.insert(condominio);
	return 0;
}

int EmpresaCondominios::removeCondominio(int id) {
	BSTItrIn<Condominio*> itb(condominios);

	while (!itb.isAtEnd()) {
		if (itb.retrieve()->getId() == id) {
			condominios.remove(itb.retrieve());
			return 0;
		}
		itb.advance();
	}

	return -1;
}

BST<Condominio*> EmpresaCondominios::getCondominios() const {
	return condominios;
}

void EmpresaCondominios::setCondominios(BST<Condominio*> condominios) {
	this->condominios = condominios;
}
