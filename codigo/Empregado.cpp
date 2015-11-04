/*
 * Empregado.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Empregado.h"

Empregado::Empregado(string nome, int bi, string tipo, bool livre) {
	this->nome = nome;
	this->bi = bi;
	this->tipo = tipo;
	this->livre = livre;
}

string Empregado::getNome() const {
	return nome;
}

int Empregado::getBI() const {
	return bi;
}

string Empregado::getTipo() const {
	return tipo;
}

bool Empregado::getLivre() const {
	return livre;
}

void Empregado::setLivre(bool livre) {
	this->livre = livre;
}

bool Empregado::operator ==(const Empregado &empregado) {
	return (this->bi == empregado.getBI());
}
