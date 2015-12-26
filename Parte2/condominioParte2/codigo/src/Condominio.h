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
	int id;
	string designacao;
	int nif;
	int numeroTelefone;
	string email;
	vector<Cliente *> clientes;
	Servico *servico;
	string localizacao;
public:
	static int lastId;
	/**
	 * @brief Função que cria um condominio.
	 * @param designacao - nome do condomínio.
	 * @param nif - número de identificação fiscal do condomínio.
	 * @param numeroTelefone - número de telefone do condomínio.
	 * @param email - email do condomínio.
	 * @param clientes - clientes do condomínio.
	 * @param serviço - empresa de serviços.
	 */
	Condominio(string designacao, int nif, int numeroTelefone, string email,
			vector<Cliente *> clientes, Servico *servico,
			string localizacao);
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
	 * @brief Função para efetuar o pagamento da base mensal de condomínio de uma habitação.
	 * @param habitacao - habitação da qual se quer efetuar o pagamento da base mensal de condomínio.
	 * @return Retorna o valor a pagar da base mensal de condomínio daquela habitação e  -1 caso a habitação não exista.
	 */
	float pagarMensalidade(Habitacao *habitacao) const;
	/**
	 * @brief Requisita um empregado de um dado tipo.
	 * @tipo - tipo do empregado pretendido.
	 * @return Retorna o Empregado que vai fazer o serviço.
	 */
	Empregado * requisitaEmpregado(string tipo);
	/**
	 * @brief Requisita um serviço de um dado tipo.
	 * @param tipo - o tipo de serviço pode ser Limpeza, Canalizacao ou Pintura.
	 * @param habitacao - habitação para a qual é requisitado o serviço.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int requisitaServico(string tipo, Habitacao *habitacao);
	/**
	 * @brief Coloca um empregado livre quando acaba de prestar um serviço.
	 * @param empregado - empregado que terminou o serviço.
	 * @return Retorna 0 em caso de sucesso e -1 caso contrário.
	 */
	int fimDoServico(Empregado *empregado);
	/**
	 * @brief Consulta dados de um dado cliente.
	 * @param cliente - bi do cliente que vai ser procurado.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int consultaCliente(int cliente) const;
	/**
	 * @brief Função que retorna o identificador do condomínio.
	 * @return Retorna o identificador do condomínio.
	 */
	int getId() const;
	/**
	 * @brief Função para obter a designacao do condominio.
	 * @return Retorna a designacao do condominio.
	 */
	string getDesignacao() const;
	/**
	 * @brief Função para obter o NIF do condominio.
	 * @return Retorna o NIF do condominio.
	 */
	int getNIF() const;
	/**
	 * @brief Função para obter o número de telefone do condominio.
	 * @return Retorna o número de telefone do condominio.
	 */
	int getNumeroTelefone() const;
	/**
	 * @brief Função para obter o email do condominio.
	 * @return Retorna o email do condominio.
	 */
	string getEmail() const;
	/**
	 * @brief Função para obter a localização do condomínio.
	 * @return Retorna a localização do condomínio.
	 */
	string getLocalizacao() const;
	/**
	 * @brief Função para obter os clientes do condomínio.
	 * @return Retorna os clientes do condomínio.
	 */
	vector<Cliente *> getClientes() const;
	/**
	 * @brief Função para obter a empresa de serviços.
	 * @return Retorna a empresa de serviços.
	 */
	Servico * getServico() const;
	/**
	 * @brief Função para obter o número de habitações do condomínio.
	 * @return Retorna o número de habitações do condomínio.
	 */
	int getNumHabs() const;
	/**
	 * @brief Função para obter o número de vivendas do condomínio.
	 * @return Retorna o número de vivendas do condomínio.
	 */
	int getNumVivendas() const;
	/**
	 *@brief Função para atualizar a designacao do condomínio.
	 *@param designacao - Nova designacao do condomínio.
	 */
	void setDesignacao(string designacao);
	/**
	 *@brief Função para atualizar o NIF do condomínio.
	 *@param nif - Novo NIF do condomínio.
	 */
	void setNIF(int nif);
	/**
	 *@brief Função para atualizar o número de telefone do condomínio.
	 *@param numeroTelefone - Novo número de telefone do condomínio.
	 */
	void setNumeroTelefone(int numeroTelefone);
	/**
	 *@brief Função para atualizar o email do condomínio.
	 *@param email - Novo email do condomínio.
	 */
	void setEmail(string email);
	/**
	 * @brief Função para atualizar a localização do condomínio.
	 * @param localizacao - Nova localização do condomínio.
	 */
	void setLocalizacao(string localizacao);
	/**
	 * @brief Operador para verificar se dois condomínios são o mesmo.
	 * @param cond - condomínio externa com o qual vai ser comparado o condominio.
	 * @return Retorna verdade caso os condomínios sejam o mesmo e falso caso contrário.
	 */
	bool operator==(const Condominio & cond) const;
	/**
	 * @brief Operador para verificar se um condominio é menor que outro
	 * @param cond2 - condomínio externo com o qual vai ser comparado o condomínio.
	 * @return Retorna verdade caso o condominio tenha um número inferior de habitações que o condomínio externo, ou caso tenha um número de habitações iguais compara o número de vivendas.
	 */
	bool operator<(const Condominio & cond2) const;
};

#endif /* SRC_CONDOMINIO_H_ */
