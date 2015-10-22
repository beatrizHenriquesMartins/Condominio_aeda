/*
 * Condominio.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_CONDOMINIO_H_
#define SRC_CONDOMINIO_H_

#include <iostream>
#include <vector>
#include "Habitacao.h"
#include "Servico.h"
#include "Cliente.h"

using namespace std;

class Condominio {
	string nome;
	int nif;
	vector<Cliente *> clientes;
	Servico * servico;
public:
	Condominio(string nome, int nif, vector<Cliente *> clientes, Servico * servico);
	void adicionaCliente(Cliente * cliente);
	vector<Cliente *> getClientes() const;
	float pagarMensalidade(Habitacao * habitacao) const; // retorna -1 caso a habitação não exista
	int requesitaServico(string tipo);
	int fimDoServico(Empregado * empregado);
};

#endif /* SRC_CONDOMINIO_H_ */
