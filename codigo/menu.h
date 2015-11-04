#include <iostream>

using namespace std;

void menuCondominio();
void pagAdicionarCliente();
void pagAdicionarHabitacao();
void pagVerListaClientes();
void pagPagarMensalidade();
void menuServicos();
void servicosRequisitarServicos();
void servicosFimdoServico();
void menuEmpregados();
void empregadosLipezas();
void empregadosCanalizacao();
void empregadosPinturas();
void empregadosAdicionarEmpregado();
void empregadoRemoverEmpregado();

void menu() {

	cout << " ***** TRABALHO 5 - CONDOMINIO *****" << endl << endl;

	int opcao;

	do {
		cout << "Menu" << endl;
		cout << "     1.Condominio" << endl;
		cout << "     2.Sair" << endl;
		cout << "Introduza uma opção: ";
		cin >> opcao;
		cout << "\n";

		switch (opcao) {
		case 1:
			break;

		case 2:
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}

	} while (opcao != 2);
}

void menuCondominio() {
	int op;

	do {
		cout << "Condomínio" << endl;
		cout << "     1.Adiciona Cliente" << endl;
		cout << "     2.Adiciona Habitacao" << endl;
		cout << "     3.Ver Lista  Clientes" << endl;
		cout << "     4.Pagar mensalidades" << endl;
		cout << "     5.Serviços" << endl;
		cout << "     6.Empregados" << endl;
		cout << "     7.Sair" << endl;

		cout << "Introduza uma opção: ";
		cout << "\n";

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

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 7);
}

void menuServicos() {
	int op;

	do {
		cout << "Serviços:" << endl;
		cout << "     1.Requisitar Serviço" << endl;
		cout << "     2.Fim do Serviço" << endl;
		cout << "     3.Sair" << endl;
		cout << "Introduza uma opção: ";

		switch (op) {
		case 1:
			break;

		case 2:
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 3);
}

void menuEmpregados() {
	int op;

	do {
		cout << "Empregados:" << endl;
		cout << "     1.Limpeza" << endl;
		cout << "     2.Canalização" << endl;
		cout << "     3.Pintura" << endl;
		cout << "     4.Adicionar Empregado" << endl;
		cout << "     5.Remover Empregado" << endl;
		cout << "     6.Sair" << endl;
		cout << "Introduza uma opção: ";

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
		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 6);
}
