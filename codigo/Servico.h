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
#include "excecoes.h"

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
	 * @brief Função para obter o número de empregados de limpeza existentes.
	 * @return Retorna o número de empregados de limpeza existentes.
	 */
	int numEmpLimpeza() const;
	/**
	 * @brief Função para obter o número de canalizadores existentes.
	 * @return Retorna o número de canalizadores existentes.
	 */
	int numEmpCanalizacao() const;
	/**
	 * @brief Função para obter o número de pintores existentes.
	 * @return Retorna o número de pintores existentes.
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
	 * @brief Procura um dado empregado nos empregados da empresa de serviços.
	 * @param empregado - empregado que se pretende procurar.
	 * @return Retorna a posição do empregado no vetor de empregados ou -1 caso não exista.
	 */
	int procuraEmpregado(Empregado *empregado);
	/**
	 * @brief Adiciona um empregado aos empregados da empresa de serviços.
	 * @param empregado - empregado que se quer adicionar aos empregados da empresa de serviços.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int adicionaEmpregado(Empregado *empregado);
	/**
	 * @brief Remove um empregado dos empregados da empresa.
	 * @param empregado - empregado que se quer remover dos empregados da empresa de serviços.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int removeEmpregado(Empregado *empregado);
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
	/**
	 * @brief Função decrementa o número de servicos disponiveis.
	 * @return Retorna 0 em caso de sucesso e -1 caso o número de empregados disponíveis seja zero.
	 */
	int decServicosDisponiveis();
	/**
	 * @brief Função incrementa o número de servicos disponiveis.
	 * @return Retorna 0 em caso de sucesso.
	 */
	int incServicosDisponiveis();
	/**
	 * @brief Função para obter o número máximo de empregados de limpeza permitidos.
	 * @return Retorna o número máximo de empregados de limpeza permitidos.
	 */
	int getNumMaxLimpeza() const;
	/**
	 * @brief Função para obter o número máximo de canalizadores permitidos.
	 * @return Retorna o número máximo de canalizadores permitidos.
	 */
	int getNumMaxCanalizacao() const;
	/**
	 * @brief Função para obter o número máximo de pintores permitidos.
	 * @return Retorna o número máximo de pintores permitidos.
	 */
	int getNumMaxPintura() const;
};


#endif /* SRC_SERVICO_H_ */
