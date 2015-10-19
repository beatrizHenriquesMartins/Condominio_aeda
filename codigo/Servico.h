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
	Servico(vector<Empregado *> empregados, int maxEmpLimpeza, int maxEmpCanalizacao, int maxEmpPintura);
	// Número de empregados de cada tipo
	int numEmpLimpeza() const;
	int numEmpCanalizacao() const;
	int numEmpPintura() const;
	// Número de empregados livres de cada tipo
	int numEmpLimpezaLivres() const;
	int numEmpCanalizacaoLivres() const;
	int numEmpPinturaLivres() const;
	int adicionaEmpregado(Empregado *empregado);
	int getServicosDisponiveis() const;
	vector<Empregado *> getEmpregados() const;
};

#endif /* SRC_SERVICO_H_ */
