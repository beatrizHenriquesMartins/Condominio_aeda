/*
 * EmpresaCondominios.cpp
 *
 *  Created on: 21/12/2015
 *      Author: teresachaves
 */

#include "EmpresaCondominios.h"

EmpresaCondominios::EmpresaCondominios(vector<Condominio *> condominios) {
	this->condominios = condominios;
}

int EmpresaCondominios::adicionaCondominio(Condominio *condominio) {
	vector<Condominio *>::iterator itb = condominios.begin();

	// Verifica se o condomínio já existe na empresa
	for(; itb!= condominios.end(); itb++) {
		if((*itb) == condominio)
			return -1;
	}

	condominios.push_back(condominio);
	return 0;
}

int EmpresaCondominios::removeCondominio(int id) {
	vector<Condominio *>::iterator itb = condominios.begin();

	// Verifica se o condomínio existe na empresa
	for(; itb!= condominios.end(); itb++) {
		if((*itb)->getId() == id) {
			condominios.erase(itb);
			return 0;
		}
	}

	return -1;
}

vector<Condominio *> EmpresaCondominios::getCondominios() const {
	return condominios;
}

void EmpresaCondominios::setCondominios(vector<Condominio *> condominios) {
	this->condominios = condominios;
}
