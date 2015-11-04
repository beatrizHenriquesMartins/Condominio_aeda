/*
 * Condominio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Condominio.h"

Condominio::Condominio(string nome, int nif, vector<Cliente *> clientes, Servico * servico) {
	this->nome = nome;
	this->nif = nif;
	this->servico = servico;
}

bool Condominio::existeCliente(Cliente * cliente) {
	for (unsigned int i = 0; i < clientes.size(); i++)
		if (*clientes[i] == *cliente)
			return true;// encontrou
	return false; // não encontrou
}

int Condominio::adicionaCliente(Cliente * cliente) {
	if(!existeCliente(cliente)) {
		clientes.push_back(cliente);
		return 0;
	}
	else
		throw ClienteExistente(cliente->getBI());
}

vector<Cliente *> Condominio::getClientes() const {
	return clientes;
}

float Condominio::pagarMensalidade(Habitacao * habitacao) const {
	vector<Cliente *>::const_iterator itb_cliente = clientes.begin();
	vector<Cliente *>::const_iterator ite_cliente = clientes.end();

	for (; itb_cliente != ite_cliente; itb_cliente++) {
		vector<Habitacao *>::const_iterator itb_hab = (*itb_cliente)->getHabitacoes().begin();
		vector<Habitacao *>::const_iterator ite_hab = (*itb_cliente)->getHabitacoes().end();

		itb_hab = find(itb_hab, ite_hab, habitacao);
		if(itb_hab!=ite_hab)
			return (*itb_hab)->mensalidade();
	}

	throw HabitacaoInexistente(habitacao->getMorada());
}

void Condominio::requisitaEmpregado(string tipo) {
	vector<Empregado *> empregados = servico->getEmpregados();

	for (unsigned int i = 0; i < empregados.size(); i++) {
		if (empregados[i]->getTipo() == tipo && empregados[i]->getLivre()) {
			empregados[i]->setLivre(false);
			servico->decServicosDisponiveis();
			break;
		}
	}
}

int Condominio::requisitaServico(string tipo) {
	if (tipo == "Limpeza") {
		// Não tem empregados de Limpeza disponíveis
		if (servico->numEmpLimpezaLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else
			requisitaEmpregado(tipo);

	} else if (tipo == "Canalizacao") {
		// Não tem empregados de Canalizacao disponíveis
		if (servico->numEmpCanalizacaoLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else
			requisitaEmpregado(tipo);

	} else if (tipo == "Pintura") {
		// Não tem empregados de Pintura disponíveis
		if (servico->numEmpPinturaLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else
			requisitaEmpregado(tipo);

	} else
		throw ServicoInvalido(tipo);

	return 0;
}

int Condominio::fimDoServico(Empregado * empregado) {
	bool existe = false;
	int ocupado = false;
	for(unsigned int i = 0; i < servico->getEmpregados().size(); i++) {
		// Empregado pertence a este Condominio e não estava livre
		if(*servico->getEmpregados()[i] == *empregado) {
			existe = true;
			if(!empregado->getLivre()) {
				ocupado = true;
				servico->getEmpregados()[i]->setLivre(true);
				servico->incServicosDisponiveis();
				return 0;
			}
		}
	}

	if(!existe)
		throw EmpregadoInexistente(empregado->getBI());

	if(!ocupado)
		throw EmpregadoLivre(empregado->getBI());
}
