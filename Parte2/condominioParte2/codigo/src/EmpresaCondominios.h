/*
 * EmpresaCondominios.h
 *
 *  Created on: 21/12/2015
 *      Author: teresachaves
 */

#ifndef SRC_EMPRESACONDOMINIOS_H_
#define SRC_EMPRESACONDOMINIOS_H_

#include <iostream>
#include "Condominio.h"
#include "BST.h"

using namespace std;

class EmpresaCondominios {
	BST<Condominio> conds;
public:
	/**
	 * @brief Função que cria uma empresa de condomínios.
	 */
	EmpresaCondominios();
	/**
	 * @brief Função que adiciona um condomínio à empresa.
	 * @param condominio - Condomínio a adicionar à empresa.
	 * @return Retorna 0 se conseguir inserir o novo codomínio, ou seja se este ainda não existe. ou -1 caso contrário.
	 */
	int adicionaCondominio(Condominio condominio);
	/**
	 * @brief Função que remove um condomínio da empresa.
	 * @param id - Identificador do condomínio a remover.
	 * @return Retorna 0 caso consiga remover o condomínio, ou seja se este existe, ou -1 caso contrário.
	 */
	int removeCondominio(int id);
	/**
	 * @brief Função que retorna os condomínios da empresa.
	 * @return Retorna os condomínios da empresa.
	 */
	BST<Condominio> getCondominios() const;
	/**
	 * @brief Função que atualiza os condomínios da empresa.
	 * @param condominios - Nova BST de condomínios da empresa.
	 */
	void setCondominios(BST<Condominio> condominios);
	/**
	 * @brief Função que dado um nome retorna um condominio com esse nome.
	 * @param nome - nome do condomínio.
	 * @return Retorna o condomínio caso encontre ou notFound caso contrário.
	 */
	Condominio find(string nome);
};

#endif /* SRC_EMPRESACONDOMINIOS_H_ */
