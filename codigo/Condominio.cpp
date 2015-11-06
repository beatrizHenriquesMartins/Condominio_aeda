/*
 * Condominio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Condominio.h"

Condominio::Condominio(string nome, int nif, vector<Cliente *> clientes, Servico *servico) {
	this->nome = nome;
	this->nif = nif;
	this->servico = servico;
	this->clientes = clientes;
}

int Condominio::existeCliente(Cliente *cliente) {
	for (unsigned int i = 0; i < clientes.size(); i++)
		if (*clientes[i] == *cliente)
			return i;// encontrou
	return -1; // não encontrou
}

int Condominio::adicionaCliente(Cliente *cliente) {
	if(existeCliente(cliente) == -1) {
		clientes.push_back(cliente);
		return 0;
	}
	else
		throw ClienteExistente(cliente->getBI());
}

int Condominio::removeCliente(Cliente *cliente) {
	int i;

	if((i = existeCliente(cliente)) != -1){
		clientes.erase(clientes.begin()+i);
		return 0;
	}
	else
		throw ClienteInexistente(cliente->getBI());
}

vector<Cliente *> Condominio::getClientes() const {
	return clientes;
}

float Condominio::pagarMensalidade(Habitacao *habitacao) const {
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

Empregado * Condominio::requisitaEmpregado(string tipo) {
	vector<Empregado *> empregados = servico->getEmpregados();

	for (unsigned int i = 0; i < empregados.size(); i++) {
		if (empregados[i]->getTipo() == tipo && empregados[i]->getLivre()) {
			empregados[i]->setLivre(false);
			servico->decServicosDisponiveis();
			return empregados[i];
		}
	}
	return NULL;
}

int Condominio::requisitaServico(string tipo, Habitacao *habitacao) {
	bool encontrou = false;
	if (tipo == "Limpeza") {
		// Não tem empregados de Limpeza disponíveis
		if (servico->numEmpLimpezaLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else {
			Empregado *servico = requisitaEmpregado(tipo);

			for (unsigned int i = 0; i < clientes.size(); i++) {

				for(unsigned int j = 0; j < clientes[i]->getHabitacoes().size(); j++) {
					if(clientes[i]->getHabitacoes()[j] == habitacao) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if(!encontrou)
				throw HabitacaoInexistente(habitacao->getMorada());
		}

	} else if (tipo == "Canalizacao") {
		// Não tem empregados de Canalizacao disponíveis
		if (servico->numEmpCanalizacaoLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else{
			Empregado *servico = requisitaEmpregado(tipo);

			for (unsigned int i = 0; i < clientes.size(); i++) {

				for(unsigned int j = 0; j < clientes[i]->getHabitacoes().size(); j++) {
					if(clientes[i]->getHabitacoes()[j] == habitacao) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if(!encontrou)
				throw HabitacaoInexistente(habitacao->getMorada());
		}

	} else if (tipo == "Pintura") {
		// Não tem empregados de Pintura disponíveis
		if (servico->numEmpPinturaLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else {
			Empregado *servico = requisitaEmpregado(tipo);

			for (unsigned int i = 0; i < clientes.size(); i++) {

				for(unsigned int j = 0; j < clientes[i]->getHabitacoes().size(); j++) {
					if(clientes[i]->getHabitacoes()[j] == habitacao) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if(!encontrou)
				throw HabitacaoInexistente(habitacao->getMorada());
		}

	} else
		throw ServicoInvalido(tipo);

	return 0;
}

int Condominio::fimDoServico(Empregado *empregado) {
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

int Condominio::consultaCliente(int cliente) const {
	for(unsigned int i = 0; i < clientes.size(); i++) {
		if(clientes[i]->getBI() == cliente) {
			cout << "BI: " << cliente << endl;
			cout << "Nome: " << clientes[i]->getNome() << endl;
			cout << "Habitacoes: ";
			for(unsigned int k = 0; k < clientes[i]->getHabitacoes().size(); k++) {
				Habitacao * h = clientes[i]->getHabitacoes()[k];
				cout << h->getMorada() << endl;
			}
			return 0;
		}
	}
	throw ClienteInexistente(cliente);
}

Servico * Condominio::getServico() const {
	return servico;
}
