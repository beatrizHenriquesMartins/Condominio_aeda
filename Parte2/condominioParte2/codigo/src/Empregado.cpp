/*
 * Empregado.cpp
 *
 *  Created on: 19/10/2015
 *      Author: teresachaves
 */

#include "Empregado.h"

Empregado::Empregado(string nome, int bi, int numeroTelemovel, string email,
		string tipo, bool livre) {
	this->nome = nome;
	this->bi = bi;
	this->numeroTelemovel = numeroTelemovel;
	this->email = email;
	this->tipo = tipo;
	this->livre = livre;
}

string Empregado::getNome() const {
	return nome;
}

int Empregado::getBI() const {
	return bi;
}

int Empregado::getNumeroTelemovel() const {
	return numeroTelemovel;
}

string Empregado::getEmail() const {
	return email;
}

string Empregado::getTipo() const {
	return tipo;
}

bool Empregado::getLivre() const {
	return livre;
}

void Empregado::setNome(string nome) {
	this->nome = nome;
}

void Empregado::setBI(int bi) {
	this->bi = bi;
}

void Empregado::setNumeroTelemovel(int numeroTelemovel) {
	this->numeroTelemovel = numeroTelemovel;
}

void Empregado::setEmail(string email) {
	this->email = email;
}

void Empregado::setTipo(string tipo) {
	this->tipo = tipo;
}

void Empregado::setLivre(bool livre) {
	this->livre = livre;
}

bool Empregado::operator ==(const Empregado &empregado) {
	return (this->bi == empregado.getBI());
}
