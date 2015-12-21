/*
 * Empregado.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_EMPREGADO_H_
#define SRC_EMPREGADO_H_

#include <iostream>
#include <string>

using namespace std;

class Empregado {
	string nome;
	int bi;
	int numeroTelemovel;
	string email;
	string tipo;
	bool livre; //true - livre; false - ocupado;
public:
	/**
	 * @brief Função que cria um empregado.
	 * @param nome - nome do empregado.
	 * @param bi - número do bilhete de identidade.
	 * @param numeroTelemovel - número de telemóvel do empregado
	 * @param email - email do empregado.
	 * @param tipo - tipo de empregado.
	 * @param livre - se for verdadeiro então o empregado está livre, caso contrário está ocupado.
	 */
	Empregado(string nome, int bi, int numeroTelemovel, string email,
			string tipo, bool livre);
	/**
	 * @brief Função para obter o nome do empregado.
	 * @return Retorna o nome do empregado.
	 */
	string getNome() const;
	/**
	 * @brief Função para obter o número do bilhete de identidade do empregado.
	 * @return Retorna o número do bilhete de identidade do empregado.
	 */
	int getBI() const;
	/**
	 *@brief Função para obter o número de telemóvel do empregado.
	 *@return Retorna o número de telemóvel do empregado.
	 */
	int getNumeroTelemovel() const;
	/**
	 *@brief Função para obter o email do empregado.
	 *@return Retorna o email do empregado.
	 */
	string getEmail() const;
	/**
	 * @brief Função para obter o tipo de empregado.
	 * @return Retorna o tipo de empregado.
	 */
	string getTipo() const;
	/**
	 * @brief Função para verificar se um empregado está livre.
	 * @return Retorna verdadeiro se o empregado está livre e falso caso contrário.
	 */
	bool getLivre() const;
	/**
	 *@brief Função para atualizar o nome do empregado.
	 *@param nome - Novo nome do empregado.
	 */
	void setNome(string nome);
	/**
	 *@brief Função para atualizar o BI do empregado.
	 *@param bi - Novo BI do empregado.
	 */
	void setBI(int bi);
	/**
	 *@brief Função para atualizar o número de telemóvel do empregado.
	 *@param numeroTelemovel - Novo número de telemóvel do empregado.
	 */
	void setNumeroTelemovel(int numeroTelemovel);
	/**
	 *@brief Função para atualizar o email do empregado.
	 *@param email - Novo email do empregado.
	 */
	void setEmail(string email);
	/**
	 * @brief Função que altera o estado do empregado para livre ou ocupado.
	 * @param livre - valor que indica se se quer alterar o empregado para livre ou para ocupado.
	 */
	void setLivre(bool livre);
	/**
	 * @brief Função que altera o tipo de empregado.
	 * @param tipo - tipo de empregado.
	 */
	void setTipo(string tipo);
	/**
	 * @brief Operador para verificar se dois empregados são o mesmo.
	 * @param empregado - empregado externo com a qual vai ser comparado o empregado.
	 * @return Retorna verdade caso os empregados sejam o mesmo e falso caso contrário.
	 */
	bool operator==(const Empregado &empregado);
};

#endif /* SRC_EMPREGADO_H_ */
