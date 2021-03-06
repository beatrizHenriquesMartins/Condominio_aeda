/*
 * Habitacao.h
 *
 *  Created on: 12/10/2015
 *      Author: teresachaves
 */

#ifndef SRC_HABITACAO_H_
#define SRC_HABITACAO_H_

#include <iostream>
#include <vector>
#include "Empregado.h"

using namespace std;

class Habitacao {
	string morada;
	int areaHabitacao;
	string tipo;
	vector<Empregado *> servicos; // Histórico de serviços da habitação
public:
	/**
	 * @brief Função que cria uma habitação.
	 * @param morada - localização geográfica da habitação.
	 * @param areaHabitacao - area habitacional.
	 */
	Habitacao(string morada, int areaHabitacao, string tipo);
	virtual ~Habitacao() {

	}
	;
	/**
	 * @brief Função que calcula o valor da base mensal de condomínio.
	 * @return Retorna o valor da base mensal de condomínio.
	 */
	virtual float mensalidade() const;
	/**
	 * @brief Adiciona um serviço ao histórico de serviços.
	 * @param servico - servico que foi requisitado.
	 */
	void adicionaServico(Empregado *servico);
	/**
	 * @brief Função para obter o histórico de serviços prestados nesta habitação.
	 * @return Retorna o histórico de serviços prestados nesta habitação.
	 */
	vector<Empregado *> getServicos() const;
    /**
	 * @brief Função para obter as informações da habitação.
	 * @return Retorna as informações da habitação.
	 */
	virtual void getInformacoes() const;
    /**
	 * @brief Função para obter a morada da habitação.
	 * @return Retorna a morada da habitação.
	 */
	string getMorada() const;
	/**
	 * @brief Função para obter a area habitacional.
	 * @return Retorna a area habitacional.
	 */
	int getAreaHabitacao() const;
	/**
	 * @brief Função para obter o tipo da habitação.
	 * @return Retorna o tipo da habitação.
	 */
	string getTipo() const;
    /**
     * @brief Função para atualizar a morada da habitação.
     * @param morada - Morada da habitação.
     */
    void setMorada(string morada);
    /**
     * @brief Função para atualizar a área habitacional.
     * @param morada - Área habitacional.
     */
    void setAreaHabitacao(int areaHabitacao);
    /**
	 * @brief Função para atualizar o tipo da habitação.
	 * @param tipo - tipo da habitação.
	 */
    void setTipo(string tipo);
    /**
     * @brief Função para atualizar os serviços da habitação.
     * @param servicos - Serviços da habitação a serem atualizados.
    */
    void setServicos(vector<Empregado *> servicos);
    /**
	 * @brief Operador para verificar se duas habitações são a mesma.
	 * @param hab - habitação externa com a qual vai ser comparada a habitação.
	 * @return Retorna verdade caso as habitações sejam a mesma e falso caso contrário.
	 */
	bool operator==(const Habitacao & hab);
};

#endif /* SRC_HABITACAO_H_ */
