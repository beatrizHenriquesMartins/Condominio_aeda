/*
 * interface.cpp
 *
 *  Created on: 05/11/2015
 *      Author: teresachaves
 */

#include "interface.h"

void Interface::menuEmpregado() {
	int op;

	do {
		cout << "Empregado" << endl;
		cout << "     1. Terminar serviço" << endl;
		cout << "     2. Consultar histórico serviços" << endl;
		cout << "     3. Sair" << endl;

		cout << "Introduza uma opção: ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			break;

		case 2:
			break;

		case 3:
			cout << "A sair do programa..." << endl;
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 3);
}

void Interface::menuCliente() {
	int op;

	do {
		cout << "Cliente" << endl;
		cout << "     1. Pagar mensalidade" << endl;
		cout << "     2. Adicionar habitação" << endl;
		cout << "     3. Remover habitação" << endl;
		cout << "     4. Requisitar serviço" << endl;
		cout << "     5. Listar habitações" << endl;
		cout << "     6. Consultar dados habitação" << endl;
		cout << "     7. Listar histórico serviços habitação" << endl;
		cout << "     8. Sair" << endl;

		cout << "Introduza uma opção: ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			cout << "A sair do programa..." << endl;
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	}while(op != 8);
}

void Interface::menuCondominio() {
	int op;

	do {
		cout << "Condomínio" << endl;
		cout << "     1. Adiciona Cliente" << endl;
		cout << "     2. Remover Cliente" << endl;
		cout << "     3. Consultar Lista  Clientes" << endl;
		cout << "     4. Consultar dados Cliente" << endl;
		cout << "     5. Sair" << endl;

		cout << "Introduza uma opção: ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			cout << "A sair do programa..." << endl;
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 5);
}

void Interface::menuPrincipal() {
	int op;

	do {
			cout << "Menu Principal" << endl;
			cout << "     1. Condominio" << endl;
			cout << "     2. Cliente" << endl;
			cout << "     3. Empregaado" << endl;
			cout << "     4. Sair" << endl;
			cout << "Introduza uma opção: ";
			cin >> op;
			cout << endl;

			switch (op) {
			case 1:
				menuCondominio();
				break;

			case 2:
				menuCliente();
				break;

			case 3:
				menuEmpregado();
				break;

			case 4:
				cout << "A sair do programa..." << endl;
				break;

			default:
				cout << "Introduza uma opção válida!" << endl;
				break;
			}

	} while (op != 4);
}

int Interface::readHabitacoes(string nome) {
	ifstream file(nome);
	if(!file.is_open())
		return -1;

	string tipo;
	while(getline(file, tipo)){
		string morada;
		string areaHabitacao;
		getline(file, morada);
		getline(file, areaHabitacao);

		if(tipo == "a") {
			string tipologia;
			string piso;
			getline(file, tipologia);
			getline(file, piso);

			Habitacao * h = new Apartamento(morada, atoi(areaHabitacao.c_str()), atoi(tipologia.c_str()), atoi(piso.c_str()));
			habitacoes.push_back(h);
		}
		if(tipo == "v") {
			string areaExterior;
			string temPiscina;
			getline(file, areaExterior);
			getline(file, temPiscina);

			Habitacao * h = new Vivenda(morada, atoi(areaHabitacao.c_str()), atoi(areaExterior.c_str()), atoi(temPiscina.c_str()));
			habitacoes.push_back(h);
		}
	}
	return 0;
}

int Interface::readClientes(string nome) {
	/*ifstream file(nome);
	if(!file.is_open())
		return -1;

	string tipo;
	while(getline(file, tipo)){
		string nomeCliente;
		string bi;
		string tipo;
		getline(file, nomeCliente);
		getline(file, bi);
		getline(file, tipo);

		if(tipo == "habs") {
			string morada;
			while(getline(file, morada) != "endHabs") {

			}
		}
	}
	return 0;*/
}

int Interface::readEmpregados(string nome) {

}

int Interface::readCondominio(string nome) {

}

Interface::Interface(string ficheiroHabitacoes, string ficheiroClientes, string ficheiroEmpregados, string ficheiroCondominio) {
	readHabitacoes(ficheiroHabitacoes);
	readClientes(ficheiroClientes);
	readEmpregados(ficheiroEmpregados);
	readCondominio(ficheiroCondominio);
}

int main(int argc, char *argv[]) {
	// Verifica número de argumentos
	if(argc != 5) {
		cerr << "É necessário especificar o nome dos 4 ficheiros.";
		return -1;
	}
	string argv1 = argv[1];
	string argv2 = argv[2];
	string argv3 = argv[3];
	string argv4 = argv[4];

	Interface interface(argv1, argv2, argv3, argv4);

	cout << endl << " ***** GESTÃO DE UM CONDOMINIO *****" << endl << endl;



	interface.menuPrincipal();

	return 0;
}
