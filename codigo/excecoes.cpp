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

// --- EMPREGADOS INDISPONIVEIS ---

EmpregadosIndisponiveis::EmpregadosIndisponiveis(string t) : tipo(t) {

}

string EmpregadosIndisponiveis::getTipo() const {
	return tipo;
}

// --- CLIENTE EXISTENTE ---

ClienteExistente::ClienteExistente(int num_bi) : bi(num_bi) {

}

int ClienteExistente::getBI() const {
	return bi;
}

// --- EMPRESA SEM EMPREGADOS ---

EmpresaSemEmpregados::EmpresaSemEmpregados() {

}

// --- EMPREGADO OCUPADO ---

EmpregadoOcupado::EmpregadoOcupado(int num_bi) : bi(num_bi) {

}

int EmpregadoOcupado::getBI() const {
	return bi;
}

// --- EMPREGADO INEXISTENTE ---

EmpregadoInexistente::EmpregadoInexistente(int num_bi) : bi(num_bi) {

}

int EmpregadoInexistente::getBI() const {
	return bi;
}
