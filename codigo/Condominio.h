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
#include "excecoes.h"

class Condominio {
	string nome;
	int nif;
	vector<Cliente *> clientes;
	Servico *servico;
public:
	/**
	 * @brief Função que cria um condominio.
	 * @param nome - nome do condomínio.
	 * @param nif - número de identificação fiscal do condomínio.
	 * @param clientes - clientes do condomínio.
	 * @param serviço - empresa de serviços.
	 */
	Condominio(string nome, int nif, vector<Cliente *> clientes, Servico *servico);
	/**
	 * @brief Verifica se um dado cliente pertence ao condomínio.
	 * @param cliente - cliente que se pretende procurar.
	 * @return Retorna a posição do cliente que pertence ao condomínio ou -1 caso o cliente não exista.
	 */
	int existeCliente(Cliente *cliente);
	/**
	 * @brief Adiciona um cliente aos clientes do condomínio.
	 * @param cliente - cliente que se quer adicionar aos clientes do condomínio.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int adicionaCliente(Cliente *cliente);
	/**
	 * @brief Remove um dado cliente dos clientes do condomínio.
	 * @param cliente - cliente que se quer remover dos clientes do condomínio.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int removeCliente(Cliente *cliente);
	/**
	 * @brief Função para obter os clientes do condomínio.
	 * @return Retorna os clientes do condomínio.
	 */
	vector<Cliente *> getClientes() const;
	/**
	 * @brief Função para efetuar o pagamento da base mensal de condomínio de uma habitação.
	 * @param habitacao - habitação da qual se quer efetuar o pagamento da base mensal de condomínio.
	 * @return Retorna o valor a pagar da base mensal de condomínio daquela habitação e  -1 caso a habitação não exista.
	 */
	float pagarMensalidade(Habitacao *habitacao) const;
	/**
	 * @brief Requisita um empregado de um dado tipo.
	 * @tipo - tipo do empregado pretendido.
	 */
	void requisitaEmpregado(string tipo);
	/**
	 * @brief Requisita um serviço de um dado tipo.
	 * @param tipo - o tipo de serviço pode ser Limpeza, Canalizacao ou Pintura.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int requisitaServico(string tipo);
	/**
	 * @brief Coloca um empregado livre quando acaba de prestar um serviço.
	 * @param empregado - empregado que terminou o serviço.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int fimDoServico(Empregado *empregado);
};

#endif /* SRC_CONDOMINIO_H_ */
