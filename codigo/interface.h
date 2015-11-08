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
#include <sstream>
#include "Condominio.h"
#include "Apartamento.h"
#include "Vivenda.h"
#include "Cliente.h"
#include "Empregado.h"
#include "excecoes.h"
#include "Habitacao.h"
#include "insertionSort.h"
#include "Limpeza.h"
#include "Pintura.h"
#include "Servico.h"
#include "Vivenda.h"

using namespace std;

class Interface {
	Condominio *condominio;
	vector<Habitacao *> habitacoes;
	vector<Cliente *> clientes;
	vector<Empregado *> empregados;
	vector<Empregado *> servicosPrestados;
public:
	Interface(string ficheiroHabitacoes, string ficheiroClientes,
			string ficheiroEmpregados, string ficheiroServicos,
			string ficheiroCondominio);
	int readHabitacoes(string nome);
	int procuraHabitacao(string morada);
	int readClientes(string nome);
	int readEmpregados(string nome);
	int readCondominio(string nome);
	int procuraEmpregado(int bi);
	int readServicos(string nome);
	void imprimeClientes();
	int procuraCliente(int bi);
	void imprimeDadosCliente();
	void imprimeHabitacoes();
	void adicionaCliente();
	void adicionaHabitacao();
	void removeCliente();
	void removeHabitacao();
	void pagaMensalidade();
	void consultarDadosHabitacao();
	void historicoServicos();
	void historicoServicosHabitacao();
	void terminaServico();
	void menuPrincipal();
	void menuCondominio();
	void menuCliente();
	void menuEmpregado();
	void requisitaServico();
};

#endif /* SRC_INTERFACE_H_ */
