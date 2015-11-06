/*
 * interface.h
 *
 *  Created on: 06/11/2015
 *      Author: teresachaves
 */

#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Condominio.h"
#include "Apartamento.h"
#include "Vivenda.h"
#include "Cliente.h"
#include "Empregado.h"

using namespace std;

class Interface {
	Condominio *condominio;
	vector<Habitacao *> habitacoes;
	vector<Cliente *> clientes;
	vector<Empregado *> empregados;
	vector<Empregado *> servicosPrestados;
public:
	Interface(string ficheiroHabitacoes, string ficheiroClientes, string ficheiroEmpregados, string ficheiroServicos, string ficheiroCondominio);
	int readHabitacoes(string nome);
	int procuraHabitacao(string morada);
	int readClientes(string nome);
	int readEmpregados(string nome);
	int readCondominio(string nome);
	int procuraEmpregado(int bi);
	int readServicos(string nome);
	void menuPrincipal();
	void menuCondominio();
	void menuCliente();
	void menuEmpregado();
};

#endif /* SRC_INTERFACE_H_ */
