/*
 * Servico.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Servico.h"

Servico::Servico(vector<Empregado *> empregados, int maxEmpLimpeza,
		int maxEmpCanalizacao, int maxEmpPintura) {
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
		if (empregados[i]->getTipo() == "Canalizacao"
				&& empregados[i]->getLivre())
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

// Sequential Search alterado
int Servico::procuraEmpregado(Empregado *empregado) {
	for (unsigned int i = 0; i < empregados.size(); i++)
		if (*empregados[i] == *empregado)
			return i;
	return -1;
}

int Servico::adicionaEmpregado(Empregado *empregado) {

	// Verifica se empregado já existe
	if (procuraEmpregado(empregado) != -1)
		throw EmpregadoExistente(empregado->getBI());

	// Verifica se o limite de empregados desse tipo foi atingido
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
	incServicosDisponiveis();
	return 0;
}

int Servico::removeEmpregado(Empregado *empregado) {
	int id;

	// Verificar se o vetor de empregados está vazio
	if (empregados.size() == 0)
		throw EmpresaSemEmpregados();

	// Verificar se o empregado existe
	if ((id = procuraEmpregado(empregado)) != -1) {
		if (!empregados[id]->getLivre())
			throw EmpregadoOcupado(empregado->getBI());

		else {
			decServicosDisponiveis();
			empregados.erase(empregados.begin() + id);
			return 0;
		}
	}

	// Empregado não existe
	throw EmpregadoInexistente(empregado->getBI());
}

int Servico::getServicosDisponiveis() const {
	int n = 0;

	for (unsigned int i = 0; i < empregados.size(); i++) {
		if (empregados[i]->getLivre())
			n++;
	}

	return n;
}

vector<Empregado *> Servico::getEmpregados() const {
	return empregados;
}

int Servico::decServicosDisponiveis() {
	// Não é possível decrementar quando o tamanho é zero porque não existe serviços disponíveis negativos
	if (empregados.size() == 0)
		throw EmpresaSemEmpregados();

	if (servicosDisponiveis != 0) {
		servicosDisponiveis--;
		return 0;
	} else
		return -1;
}

int Servico::incServicosDisponiveis() {
	// Não é possível incrementar quando o tamanho é zero porque ainda não existem empregados na empresa.
	// O que garante que só incrementa os serviços disponíveis depois de adicionar um empregado à empresa de serviços.
	if (empregados.size() == 0)
		throw EmpresaSemEmpregados();

	servicosDisponiveis++;
	return 0;
}

int Servico::getNumMaxLimpeza() const {
	return maxEmpLimpeza;
}

int Servico::getNumMaxCanalizacao() const {
	return maxEmpCanalizacao;
}

int Servico::getNumMaxPintura() const {
	return maxEmpPintura;
}

int Servico::setNumMaxLimpeza(int maxEmpLimpeza) {

	if (numEmpLimpeza() > maxEmpLimpeza)
		return -1;
	else
		this->maxEmpLimpeza = maxEmpLimpeza;

	return 0;
}

int Servico::setNumMaxCanalizacao(int maxEmpCanalizacao) {

	if (numEmpCanalizacao() > maxEmpCanalizacao)
		return -1;
	else
		this->maxEmpCanalizacao = maxEmpCanalizacao;

	return 0;
}

int Servico::setNumMaxPintura(int maxEmpPintura) {

	if (numEmpPintura() > maxEmpPintura)
		return -1;
	else
		this->maxEmpPintura = maxEmpPintura;

	return 0;
}
