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
     * @brief Função que escreve os dados das habitações atuais para o ficheiro de habitações.
     * @param nome_hab - Nome da habitação a atualizar.
     * @return Retorna 0 em caso de sucesso e -1 caso contrário.
    */
    int writeHabitacoes(string nome_hab);
    /**
     * @brief Função que escreve os dados dos clientes atuais para o ficheiro de clientes.
     * @return Retorna 0 em caso de sucesso e -1 caso contrário.
    */
    int writeClientes();
    /**
     * @brief Função que escreve os dados dos empregados atuais para o ficheiro de empregados.
     * @return Retorna 0 em caso de sucesso e -1 caso contrário.
    */
    int writeEmpregados();
    /**
     * @brief Função que escreve os dados dos serviços atuais para o ficheiro de serviços.
     * @return Retorna 0 em caso de sucesso e -1 caso contrário.
    */
    int writeServicos();
    /**
     * @brief Função que escreve os dados do condomínio atual para o ficheiro do condomínio.
     * @return Retorna 0 em caso de sucesso e -1 caso contrário.
    */
    int writeCondominio();
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
     * @brief Imprime no ecrã a lista de clientes de um condomínio.
     */
	void imprimeClientes();
    /**
     * @brief Imprime no ecrã os dados de um cliente do condomínio.
     */
	void imprimeDadosCliente();
	/**
	 * @brief Imprime no ecrã os dados do condominio
	 */
	void imprimeDadosCondominio();
    /**
     * @brief Imprime no ecrã a lista de habitações de um condomínio.
     */
	void imprimeHabitacoes();
    /**
     * @brief Função que adiciona um cliente ao condomínio.
     */
	void adicionaCliente();
    /**
     * @brief Função que remove um cliente do condomínio.
     */
    void removeCliente();
    /**
     * @brief Função que permite a um cliente pagar a sua mensalidade.
     */
    void pagaMensalidade();
    /**
     * @brief Função que permite adicionar uma habitação a um condomínio.
     */
	void adicionaHabitacao();
    /**
     * @brief Função que permite consultar os dados de uma habitação.
     */
    void consultarDadosHabitacao();
    /**
     * @brief Função que permite remover uma habitação de um condomínio.
     */
	void removeHabitacao();
	/**
     * @brief Função que permite a um condomínio requisitar um serviço (Limpeza, Canalização ou Pintura).
     */
    void requisitaServico();
    /**
     * @brief Função que permite a um empregado (identificado pelo seu BI) terminar um serviço.
     */
	void terminaServico();
    /**
     * @brief Função que permite visualizar o histórico de serviços prestados a um condomínio.
     */
	void historicoServicos();
    /**
     * @brief Função que permite visualizar o histórico de serviços prestados a uma dada habitação.
     */
	void historicoServicosHabitacao();
    /**
     * @brief Função que permite visualizar o menu principal de gestão de um condomínio.
     */
	void menuPrincipal();
    /**
     * @brief Função que permite visualizar o menu de um condomínio onde é possível adicionar / remover um cliente, listar os clientes existentes, etc.
     */
	void menuCondominio();
    /**
     * @brief Função que permite visualizar o menu de clientes onde é possível adicionar / remover uma habitação, pagar mensalidade, etc.
     */
	void menuCliente();
    /**
     * @brief Função que permite visualizar o menu de empregados onde é possível terminar um serviço ou listar o histórico de serviços.
     */
	void menuEmpregado();
	/**
	 * @brief Função que atualiza os dados de um cliente.
	 * @param bi_atualizar - número do bilhete de identidade do cliente a atualizar.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int menuAtualizaCliente(int bi_atualizar);
	/**
	 * @brief Função que atualiza os dados do condominio.
	 */
	void menuAtualizaCondominio();
	/**
	 * @brief Função que atualiza os dados de uma dada habitação.
	 * @param morada_atualizar - morada da habitação a atualizar.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int menuAtualizaHabitacao(string morada_atualizar);
};

#endif /* SRC_INTERFACE_H_ */
