/*
 * interface.cpp
 *
 *  Created on: 05/11/2015
 *      Author: teresachaves
 */

#include <iostream>

using namespace std;

void menuEmpregado() {
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

void menuCliente() {
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

void menuCondominio() {
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

void menuPrincipal() {
	int op;

	do {
			cout << "Menu Principal" << endl;
			cout << "     1. Condominio" << endl;
			cout << "     2. Cliente" << endl;
			cout << "     3. Empregaado" << endl;
			cout << "     2. Sair" << endl;
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

int main() {

	cout << endl << " ***** GESTÃO DE UM CONDOMINIO *****" << endl << endl;

	menuPrincipal();

	return 0;
}
