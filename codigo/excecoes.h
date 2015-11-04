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
	 * @param num_bi - número do bilhete de identidade do empregado.
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

class ClienteExistente {
	int bi;
public:
	/**
	 * @brief Cria exceção quando se tenta adicionar um cliente que já existe nos clientes do condomínio.
	 * @param num_bi - número do bilhete de identidade do cliente.
	 */
	ClienteExistente(int num_bi);
	/**
	 * @brief Função para obter o número do bilhete de identidade do cliente.
	 * @return Retorna o número do bilhete de identidade do cliente.
	 */
	int getBI() const;
};

class EmpresaSemEmpregados {
public:
	/**
	 * @brief Cria exceção quando a empresa de serviços não tem empregados.
	 */
	EmpresaSemEmpregados();
};

class EmpregadoOcupado {
	int bi;
public:
	/**
	 * @brief Cria exceção quando se tenta remover um empregado que está ocupado.
	 * @param num_bi - número do bilhete de identidade do empregado.
	 */
	EmpregadoOcupado(int num_bi);
	/**
	 * @brief Função para obter o número do bilhete de identidade do empregado.
	 * @return Retorna o número do bilhete de identidade do empregado.
	 */
	int getBI() const;
};

class EmpregadoLivre {
	int bi;
public:
	/**
	 * @brief Cria exceção quando se tenta finalizar um serviço de um empregado que está livre.
	 * @param num_bi - número do bilhete de identidade do empregado.
	 */
	EmpregadoLivre(int num_bi);
	/**
	 * @brief Função para obter o número do bilhete de identidade do empregado.
	 * @return Retorna o número do bilhete de identidade do empregado.
	 */
	int getBI() const;
};

class EmpregadoInexistente {
	int bi;
public:
	/**
	 * @brief Cria exceção quando se tenta remover um empregado que não existe.
	 * @param num_bi - número do bilhete de identidade do empregado.
	 */
	EmpregadoInexistente(int num_bi);
	/**
	 * @brief Função para obter o número do bilhete de identidade do empregado.
	 * @return Retorna o número do bilhete de identidade do empregado.
	 */
	int getBI() const;
};

class HabitacaoInexistente {
	string morada;
public:
	/**
	 * @brief Cria exceção quando se procura uma habitação que não existe.
	 * @param m - morada da habitação que foi procurada.
	 */
	HabitacaoInexistente(string m);
	/**
	 * @brief Função para obter a morada da habitação.
	 * @return Retorna a morada da habitação.
	 */
	string getMorada() const;
};

class HabitacaoExistente {
	string morada;
public:
	/**
	 * @brief Cria exceção quando se tenta adicionar uma habitação que já existe.
	 * @param m - morada da habitação.
	 */
	HabitacaoExistente(string m);
	/**
	 * @brief Função para obter a morada da habitação.
	 * @return Retorna a morada da habitação.
	 */
	string getMorada() const;
};

#endif /* SRC_EXCECOES_H_ */
