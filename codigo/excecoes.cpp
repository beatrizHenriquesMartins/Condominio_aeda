/*
 * excecoes.cpp
 *
 *  Created on: 03/11/2015
 *      Author: teresachaves
 */

#include "excecoes.h"

// --- EMPREGADO EXISTENTE ---

EmpregadoExistente::EmpregadoExistente(int num_bi) : bi(num_bi) {

}

int EmpregadoExistente::getBI() const {
	return bi;
}

// --- LIMITE MAXIMO DE EMPREGADOS ---

LimiteMaximoEmpregados::LimiteMaximoEmpregados(string t) : tipo(t) {

}

string LimiteMaximoEmpregados::getTipo() const {
	return tipo;
}

// --- SERVICO INVALIDO ---

ServicoInvalido::ServicoInvalido(string t) : tipo(t) {

}

string ServicoInvalido::getTipo() const {
	return tipo;
}
