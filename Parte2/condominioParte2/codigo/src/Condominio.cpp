/*
 * Condominio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Condominio.h"

int Condominio::lastId = 1;

Condominio::Condominio(string nome, int nif, int numeroTelefone, string email,
		vector<Cliente *> clientes, Servico *servico, string designacao,
		string localizacao) {
	this->id = lastId++; // primeiro id é 1
	cout << id << endl;
	this->nome = nome;
	this->nif = nif;
	this->numeroTelefone = numeroTelefone;
	this->email = email;
	this->servico = servico;
	this->clientes = clientes;
	this->designacao = designacao;
	this->localizacao = localizacao;
}

int Condominio::existeCliente(Cliente *cliente) {
	for (unsigned int i = 0; i < clientes.size(); i++)
		if (*clientes[i] == *cliente)
			return i; // encontrou
	return -1; // não encontrou
}

int Condominio::adicionaCliente(Cliente *cliente) {
	if (existeCliente(cliente) == -1) {
		clientes.push_back(cliente);
		return 0;
	} else
		throw ClienteExistente(cliente->getBI());
}

int Condominio::removeCliente(Cliente *cliente) {
	int i;

	if ((i = existeCliente(cliente)) != -1) {
		clientes.erase(clientes.begin() + i);
		return 0;
	} else
		throw ClienteInexistente(cliente->getBI());
}

float Condominio::pagarMensalidade(Habitacao *habitacao) const {
	vector<Cliente *>::const_iterator itb_cliente = clientes.begin();
	vector<Cliente *>::const_iterator ite_cliente = clientes.end();

	for (; itb_cliente != ite_cliente; itb_cliente++) {
		vector<Habitacao *>::const_iterator itb_hab =
				(*itb_cliente)->getHabitacoes().begin();
		vector<Habitacao *>::const_iterator ite_hab =
				(*itb_cliente)->getHabitacoes().end();

		itb_hab = find(itb_hab, ite_hab, habitacao);
		if (itb_hab != ite_hab)
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

				for (unsigned int j = 0;
						j < clientes[i]->getHabitacoes().size(); j++) {
					vector<Habitacao *> habs = clientes[i]->getHabitacoes();
					Habitacao *hab = habs[j];
					if (hab->getMorada() == habitacao->getMorada()) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if (!encontrou)
				throw HabitacaoInexistente(habitacao->getMorada());
		}

	} else if (tipo == "Canalizacao") {
		// Não tem empregados de Canalizacao disponíveis
		if (servico->numEmpCanalizacaoLivres() == 0)
			throw EmpregadosIndisponiveis(tipo);

		// Pode requisitar o empregado
		else {
			Empregado *servico = requisitaEmpregado(tipo);

			for (unsigned int i = 0; i < clientes.size(); i++) {

				for (unsigned int j = 0;
						j < clientes[i]->getHabitacoes().size(); j++) {
					vector<Habitacao *> habs = clientes[i]->getHabitacoes();
					Habitacao *hab = habs[j];
					if (hab->getMorada() == habitacao->getMorada()) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if (!encontrou)
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

				for (unsigned int j = 0;
						j < clientes[i]->getHabitacoes().size(); j++) {
					vector<Habitacao *> habs = clientes[i]->getHabitacoes();
					Habitacao *hab = habs[j];
					if (hab->getMorada() == habitacao->getMorada()) {
						encontrou = true;
						Habitacao * h = clientes[i]->getHabitacoes()[j];
						h->adicionaServico(servico);
					}
				}
			}

			if (!encontrou)
				throw HabitacaoInexistente(habitacao->getMorada());
		}

	} else
		throw ServicoInvalido(tipo);

	return 0;
}

int Condominio::fimDoServico(Empregado *empregado) {
	bool existe = false;
	int ocupado = false;
	for (unsigned int i = 0; i < servico->getEmpregados().size(); i++) {
		// Empregado pertence a este Condominio e não estava livre
		if (*servico->getEmpregados()[i] == *empregado) {
			existe = true;
			if (!empregado->getLivre()) {
				ocupado = true;
				servico->getEmpregados()[i]->setLivre(true);
				servico->incServicosDisponiveis();
				return 0;
			}
		}
	}

	if (!existe)
		throw EmpregadoInexistente(empregado->getBI());

	if (!ocupado)
		throw EmpregadoLivre(empregado->getBI());

	return 0;
}

int Condominio::consultaCliente(int cliente) const {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getBI() == cliente) {
			cout << "BI: " << cliente << endl;
			cout << "Nome: " << clientes[i]->getNome() << endl;
			cout << "Habitacoes: ";
			for (unsigned int k = 0; k < clientes[i]->getHabitacoes().size();
					k++) {
				Habitacao * h = clientes[i]->getHabitacoes()[k];
				cout << h->getMorada() << endl;
			}
			return 0;
		}
	}
	throw ClienteInexistente(cliente);
}

int Condominio::getId() const {
	return id;
}

string Condominio::getNome() const {
	return nome;
}

int Condominio::getNIF() const {
	return nif;
}

int Condominio::getNumeroTelefone() const {
	return numeroTelefone;
}

string Condominio::getEmail() const {
	return email;
}

vector<Cliente *> Condominio::getClientes() const {
	return clientes;
}

Servico * Condominio::getServico() const {
	return servico;
}

void Condominio::setNome(string nome) {
	this->nome = nome;
}

void Condominio::setNIF(int nif) {
	this->nif = nif;
}

void Condominio::setNumeroTelefone(int numeroTelefone) {
	this->numeroTelefone = numeroTelefone;
}

void Condominio::setEmail(string email) {
	this->email = email;
}

bool Condominio::operator ==(const Condominio & cond) const {
	return this->id == cond.getId();
}

int Condominio::getNTotalHabs() const {
	return nTotalHabs;
}

void Condominio::setNTotalHabs(int nTotalHabs) {
	this->nTotalHabs = nTotalHabs;
}

int Condominio::getNTotalVivendas() const {
	return nTotalVivendas;
}

void Condominio::setNTotalVivendas(int nTotalVivendas) {
	this->nTotalVivendas = nTotalVivendas;
}

void Condominio::nTotalHabitacoesCond() const {
	int total = 0;

	for (int i = 0; i < clientes.size(); i++) {
		int nHabs = 0;
		nHabs = clientes[i]->getHabitacoes().size();
		total = total + nHabs;
	}

	this->nTotalHabs = total;
}

void Condominio::nTotalVivendasCond() const {
	int total = 0;

	for (int i = 0; i < clientes.size(); i++) {
		for (int j = 0; j < clientes[i]->getHabitacoes().size(); j++) {
			if (clientes[i]->getHabitacoes()[j]->getTipoHab() == "vivenda"
					|| clientes[i]->getHabitacoes()[j]->getTipoHab() == "Vivenda") {
				total++;
			}
		}
	}

	this->nTotalVivendas = total;
}

bool Condominio::operator <(const Condominio&cond) const {
	if (this->getNTotalHabs() < cond.getNTotalHabs()) {
		return true;
	} else if (this->getNTotalHabs() == cond.getNTotalHabs()) {
		if (this->getNTotalVivendas() < cond.getNTotalVivendas()) {
			return true;
		}
	}
}
