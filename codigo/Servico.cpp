/*
 * Servico.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Servico.h"

Servico::Servico(vector<Empregado *> empregados, int maxEmpLimpeza, int maxEmpCanalizacao, int maxEmpPintura) {
	this->empregados = empregados;

	this->servicosDisponiveis = getServicosDisponiveis();

	this->maxEmpLimpeza = maxEmpLimpeza;
	this->maxEmpCanalizacao = maxEmpCanalizacao;
	this->maxEmpPintura = maxEmpPintura;
}

int Servico::numEmpLimpeza() const {
	int num = 0;

	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Limpeza")
			num++;

	return num;
}

int Servico::numEmpCanalizacao() const {
	int num = 0;
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Canalizacao")
			num++;

	return num;
}

int Servico::numEmpPintura() const {
	int num = 0;
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Pintura")
			num++;

	return num;
}

int Servico::numEmpLimpezaLivres() const {
	int num = 0;
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Limpeza" && empregados[i]->getLivre())
			num++;

	return num;
}

int Servico::numEmpCanalizacaoLivres() const {
	int num = 0;
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Canalizacao" && empregados[i]->getLivre())
			num++;

	return num;
}

int Servico::numEmpPinturaLivres() const {
	int num = 0;
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregados[i]->getTipo() == "Pintura" && empregados[i]->getLivre())
			num++;

	return num;
}

int Servico::adicionaEmpregado(Empregado * empregado) {

	// Verifica se empregado já existe
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (empregado->getBI() == empregados[i]->getBI())
			throw EmpregadoExistente(empregado->getBI());

	// Verifica se limite de empregados desse tipo foi atingido
	if (empregado->getTipo() == "Limpeza") {

		if (numEmpLimpeza() >= maxEmpLimpeza)
			throw LimiteMaximoEmpregados(empregado->getTipo());

	} else if (empregado->getTipo() == "Canalizacao") {

		if (numEmpCanalizacao() >= maxEmpCanalizacao)
			throw LimiteMaximoEmpregados(empregado->getTipo());

	} else if (empregado->getTipo() == "Pintura") {

		if (numEmpPintura() >= maxEmpPintura)
			throw LimiteMaximoEmpregados(empregado->getTipo());

	} else
		// Não é um tipo de serviço válido
		throw ServicoInvalido(empregado->getTipo());

	// Adiciona empregado
	empregados.push_back(empregado);
	servicosDisponiveis++;
	return 0;
}

int Servico::getServicosDisponiveis() const {
	int n = 0;

	for(unsigned int i = 0; i < empregados.size(); i++) {
		if(empregados[i]->getLivre())
			n++;
	}

	return n;
}

vector<Empregado *> Servico::getEmpregados() const {
	return empregados;
}

int Servico::decServicosDisponiveis() {
	// TODO: Se o número de empregados no vector empregados for zero lançar excepção!
	if(servicosDisponiveis!=0) {
		servicosDisponiveis--;
		return 0;
	}
	else
		return -1;
}

int Servico::incServicosDisponiveis() {
	// TODO: Se o número de empregados no vector empregados for zero lançar excepção!
	servicosDisponiveis++;
	return 0;
}
