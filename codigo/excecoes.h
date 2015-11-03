/*
 * excecoes.h
 *
 *  Created on: 03/11/2015
 *      Author: teresachaves
 */

#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <iostream>

using namespace std;

class EmpregadoExistente {
	int bi;
public:
	/**
	 * @brief Cria exceção quando se tenta adicionar um empregado que já existe.
	 * @param num_bi - Número do bilhete de identidade do empregado.
	 */
	EmpregadoExistente(int num_bi);
	/**
	 * @brief Função para obter o número do bilhete de identidade do empregado.
	 * @return Retorna o número do bilhete de identidade do empregado.
	 */
	int getBI() const;
};

class LimiteMaximoEmpregados {
	string tipo;
public:
	/**
	 * @brief Cria exceção quando se tenta adicionar um empregado de um tipo que já atingiu o limite máximo definido pela empresa de serviços.
	 * @param t - tipo de empregado.
	 */
	LimiteMaximoEmpregados(string t);
	/**
	 * @brief Função para obter o tipo de empregado.
	 * @return Retorna o tipo de empregado.
	 */
	string getTipo() const;
};

class ServicoInvalido {
	string tipo;
public:
	/**
	 * @brief Cria exceção quando se tenta adicionar um empregado de um tipo que não existe na empresa de serviços.
	 * @param t - tipo de empregado.
	 */
	ServicoInvalido(string t);
	/**
	 * @brief Função para obter o tipo de empregado.
	 * @return Retorna o tipo de empregado.
	 */
	string getTipo() const;
};


class EmpregadosIndisponiveis {
	string tipo;
public:
	/**
	 * @brief Cria exceção quando se tenta requisitar um empregado de um tipo que não tem empregados disponíveis no momento.
	 * @param t - tipo de empregado.
	 */
	EmpregadosIndisponiveis(string t);
	/**
	 * @brief Função para obter o tipo de empregado.
	 * @return Retorna o tipo de empregado.
	 */
	string getTipo() const;
};

#endif /* SRC_EXCECOES_H_ */
