/*
 * EmpresaCondominios.cpp
 *
 *  Created on: 21/12/2015
 *      Author: teresachaves
 */

#include "EmpresaCondominios.h"

Condominio notFoundC() {
	string designacao = "";
	int nif = 0;
	int numTelf = 0;
	string mail = "";
	vector<Cliente *> c;
	vector<Empregado *> e;
	Servico * s = new Servico(e, 0, 0, 0);
	string location = "";

	return Condominio (designacao, nif, numTelf, mail, c, s, location);
}

EmpresaCondominios::EmpresaCondominios() :
		conds(notFoundC()) {

}

int EmpresaCondominios::adicionaCondominio(Condominio condominio) {
	// Verifica se o condomínio já existe na empresa

	if(!(conds.find(condominio) == notFoundC()))
		return -1;

	conds.insert(condominio);

	return 0;
}

int EmpresaCondominios::removeCondominio(int id) {
	BSTItrIn<Condominio> itb(conds);

	// Verifica se o condomínio existe na empresa
	for (; !itb.isAtEnd(); itb.advance()) {
		if (itb.retrieve().getId() == id) {
			conds.remove(itb.retrieve());
			return 0;
		}
	}

	return -1;
}

BST<Condominio> EmpresaCondominios::getCondominios() const {
	return conds;
}

void EmpresaCondominios::setCondominios(BST<Condominio> condominios) {
	this->conds = condominios;
}

Condominio EmpresaCondominios::find(string nome) {
	BSTItrIn<Condominio> itb(conds);

	for (; !itb.isAtEnd(); itb.advance()) {
		if (itb.retrieve().getDesignacao() == nome) {
			return itb.retrieve();
		}
	}

	return notFoundC();
}
