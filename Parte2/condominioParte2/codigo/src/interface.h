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
    /**
     * @brief Função que inicializa os dados dos condomínios.
     * @param ficheiroHabitacoes - Ficheiro que contém informação sobre as habitações.
     * @param ficheiroClientes - Ficheiro que contém informação sobre os clientes.
     * @param ficheiroEmpregados - Ficheiro que contém informação sobre os empregados.
     * @param ficheiroServicos - Ficheiro que contém informação sobre os serviços.
     * @param ficheiroCondominio - Ficheiro que contém informação sobre o condomínio.
    */
	Interface(string ficheiroHabitacoes, string ficheiroClientes,
			string ficheiroEmpregados, string ficheiroServicos,
			string ficheiroCondominio);
    /**
     * @brief Função que lê informação do ficheiro das habitações.
     * @param nome - Nome do ficheiro que contém informação sobre as habitações.
     * @return Retorna 0 se ler corretamente o ficheiro e -1 caso não consiga abrir o ficheiro.
    */
	int readHabitacoes(string nome);
   /**
     * @brief Função que lê informação do ficheiro dos clientes.
     * @param nome - Nome do ficheiro que contém informação sobre os clientes.
     * @return Retorna 0 se ler corretamente o ficheiro e -1 caso não consiga abrir o ficheiro.
    */
    int readClientes(string nome);
    /**
     * @brief Função que lê informação do ficheiro dos empregados.
     * @param nome - Nome do ficheiro que contém informação sobre os empregados.
     * @return Retorna 0 se ler corretamente o ficheiro e -1 caso não consiga abrir o ficheiro.
    */
	int readEmpregados(string nome);
    /**
     * @brief Função que lê informação do ficheiro dos serviços.
     * @param nome - Nome do ficheiro que contém informação sobre os serviços prestados.
     * @return Retorna 0 se ler corretamente o ficheiro e -1 caso não consiga abrir o ficheiro.
    */
    int readServicos(string nome);
    /**
     * @brief Função que lê informação do ficheiro do condomínio .
     * @param nome - Nome do ficheiro que contém informação sobre o condomínio.
     * @return Retorna 0 se ler corretamente o ficheiro e -1 caso não consiga abrir o ficheiro.
    */
    int readCondominio(string nome);
    /**
     * @brief Função que procura uma habitação pela morada.
     * @param morada - Morada da habitação a procurar.
     * @return Retorna o identificador no vetor de habitações caso encontre a habitação, ou -1 caso contrário.
    */
	int procuraHabitacao(string morada);
    /**
     * @brief Função que procura um cliente pelo bilhete de identidade.
     * @param bi - Bilhete de identidade do cliente a procurar.
     * @return Retorna o identificador no vetor de clientes caso encontre o cliente, ou -1 caso contrário.
    */
	int procuraCliente(int bi);
    /**
     * @brief Função que procura um empregado pelo bilhete de identidade.
     * @param bi - Bilhete de identidade do empregado a procurar.
     * @return Retorna o identificador no vetor de empregados caso encontre o empregado, ou -1 caso contrário.
    */
	int procuraEmpregado(int bi);
    /**
     * @brief Imprime
     */
	void imprimeClientes();
	void imprimeDadosCliente();
	void imprimeHabitacoes();
    
	void adicionaCliente();
    void removeCliente();
    void pagaMensalidade();
    
	void adicionaHabitacao();
    void consultarDadosHabitacao();
	void removeHabitacao();
	
    void requisitaServico();
	void terminaServico();
	void historicoServicos();
	void historicoServicosHabitacao();
    
	void menuPrincipal();
	void menuCondominio();
	void menuCliente();
	void menuEmpregado();
	
};

#endif /* SRC_INTERFACE_H_ */
