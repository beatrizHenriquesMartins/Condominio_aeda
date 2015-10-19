/*
 * Condominio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#include "Condominio.h"

Condominio::Condominio(string nome, int nif, vector<Habitacao *> habitacoes,
		Servico * servico) {
	this->nome = nome;
	this->nif = nif;
	this->habitacoes = habitacoes;
	this->servico = servico;
}

void Condominio::adicionaHabitacao(Habitacao * habitacao) {
	habitacoes.push_back(habitacao);
}

float Condominio::pagarMensalidade(Habitacao * habitacao) const {
	vector<Habitacao *>::const_iterator itb = habitacoes.begin();
	vector<Habitacao *>::const_iterator ite = habitacoes.end();

	for (; itb != ite; itb++) {
		if ((*itb)->getMorada() == habitacao->getMorada())
			return (*itb)->mensalidade();
	}

	return -1;
}

int Condominio::requesitaServico(string tipo) {
	vector<Empregado *> empregados = servico->getEmpregados();

	if (tipo == "Limpeza") {
		// Não tem empregados de Limpeza disponíveis
		if (servico->numEmpLimpezaLivres() == 0)
			return -2;
		// Pode requisitar o empregado
		else {
			for (unsigned int i = 0; i < empregados.size(); i++) {
				if (empregados[i]->getTipo() == "Limpeza" && empregados[i]->getLivre()) {
					empregados[i]->setLivre(false);
					break;
				}
			}
		}

	} else if (tipo == "Canalizacao") {
		// Não tem empregados de Canalizacao disponíveis
		if (servico->numEmpCanalizacaoLivres() == 0)
			return -2;
		else
			for (unsigned int i = 0; i < empregados.size(); i++) {
				if (empregados[i]->getTipo() == "Canalizacao" && empregados[i]->getLivre()) {
					empregados[i]->setLivre(false);
					break;
				}
			}
	} else if (tipo == "Pintura") {
		// Não tem empregados de Pintura disponíveis
		if (servico->numEmpPinturaLivres() == 0)
			return -2;
		else
			for (unsigned int i = 0; i < empregados.size(); i++) {
				if (empregados[i]->getTipo() == "Pintura" && empregados[i]->getLivre()) {
					empregados[i]->setLivre(false);
					break;
				}
			}
	} else
		return -1;

	return 0;
}

int Condominio::fimDoServico(Empregado * empregado) {
	for(unsigned int i = 0; i < servico->getEmpregados().size(); i++) {
		// Empregado pertence a este Condominio e não estava livre
		if(servico->getEmpregados()[i]->getBI() == empregado->getBI() && !empregado->getLivre()) {
			servico->getEmpregados()[i]->setLivre(true);
			return 0;
		}
	}

	return -1;
}
