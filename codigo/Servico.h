/*
 * Servico.h
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <vector>
#include "Limpeza.h"
#include "Canalizacao.h"
#include "Pintura.h"

class Servico {
	vector<Empregado *> empregados;
	int servicosDisponiveis;
	int maxEmpLimpeza;
	int maxEmpCanalizacao;
	int maxEmpPintura;
public:
	/**
	 * @brief Função que cria uma empresa de serviços.
	 * @param empregados - empregados da empresa.
	 * @param maxEmpLimpeza - número máximo de empregados de limpeza permitidos nesta empresa.
	 * @param maxEmpCanalizacao - número máximo de canalizadores permitidos nesta empresa.
	 * @param maxEmpPintura - número máximo de pintores permitidos nesta empresa.
	 */
	Servico(vector<Empregado *> empregados, int maxEmpLimpeza, int maxEmpCanalizacao, int maxEmpPintura);
	/**
	 * @brief Função para obter o número máximo de empregados de limpeza permitidos.
	 * @return Retorna o número máximo de empregados de limpeza permitidos.
	 */
	int numEmpLimpeza() const;
	/**
	 * @brief Função para obter o número máximo de canalizadores permitidos.
	 * @return Retorna o número máximo de canalizadores permitidos.
	 */
	int numEmpCanalizacao() const;
	/**
	 * @brief Função para obter o número máximo de pintores permitidos.
	 * @return Retorna o número máximo de pintores permitidos.
	 */
	int numEmpPintura() const;
	/**
	 * @brief Função para obter o número de empregados de limpeza livres.
	 * @return Retorna o número de empregados de limpeza livres.
	 */
	int numEmpLimpezaLivres() const;
	/**
	 * @brief Função para obter o número de canalizadores livres.
	 * @return Retorna o número de canalizadores livres.
	 */
	int numEmpCanalizacaoLivres() const;
	/**
	 * @brief Função para obter o número de pintores livres.
	 * @return Retorna o número de pintores livres.
	 */
	int numEmpPinturaLivres() const;
	/**
	 * @brief Adiciona um empregado aos empregados da empresa de serviços.
	 * @param empregado - empregado que se quer adicionar aos empregados da empresa de serviços.
	 * @return Retorna 0 em caso de sucesso, -1 se o empregado já existe, -2 se o limite de empregados desse tipo foi atingido ou -3 se não é tipo de serviço válido
	 */
	int adicionaEmpregado(Empregado *empregado);
	/**
	 * @brief Função para obter o número de empregados que estão livres na empresa de serviços.
	 * @return Retorna o número de empregados que estão livres na empresa de serviços.
	 */
	int getServicosDisponiveis() const;
	/**
	 * @brief Função para obter os empregados da empresa de serviços.
	 * @return Retorna os empregados da empresa de serviços.
	 */
	vector<Empregado *> getEmpregados() const;
};

#endif /* SRC_SERVICO_H_ */
