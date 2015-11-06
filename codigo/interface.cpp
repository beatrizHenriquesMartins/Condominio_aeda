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
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	}while(op != 8);
}

void Interface::imprimeClientes() {
	cout << endl << "--- Lista de Clientes do condominio " << condominio->getNome() << " ---" << endl << endl;

	for(unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];

		cout << "-> Nome: " << c->getNome() << " BI: " << c->getBI() << endl;
	}

	cout << endl;
}

int Interface::procuraCliente(int bi) {
	for(unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];

		if(c->getBI() == bi)
			return i;
	}

	return -1;
}

void Interface::imprimeDadosCliente() {
	cout << endl << "--- Dados do Cliente ---" << endl << endl;

	cout << endl << "Número do bilhete de identidade do cliente: ";
	int bi;
	cin >> bi;

	int i = procuraCliente(bi);
	Cliente *c = condominio->getClientes()[i];

	cout << "-> Nome: " << c->getNome() << endl;
	cout << "   BI: " << c->getBI() << endl;
	cout << "   Habitações: ";

	for(unsigned int i = 0; i < c->getHabitacoes().size(); i++) {
		Habitacao *h = c->getHabitacoes()[i];

		if(i != 0) {
			cout << "               " << i+1 << ". " << h->getMorada() << endl;
		}
		else {
			cout << i+1 << ". " << h->getMorada() << endl;
		}
	}

	cout << endl;
}

void Interface::adicionaCliente() {
	cout << endl << "--- Adicionar um cliente novo ---" << endl;

	cout << "Nome: ";
	string nome;
	cin >> nome;

	cout <<  "BI: ";
	int bi;
	cin >> bi;

	vector<Habitacao *> habs; // As habitações são inseridas posteriormente no menu do cliente

	Cliente *c = new Cliente(nome, bi, habs);

	condominio->adicionaCliente(c);
}

void Interface::removeCliente() {
	cout << endl << "--- Remover um cliente novo ---" << endl;

	cout <<  "BI: ";
	int bi;
	cin >> bi;

	int i = procuraCliente(bi);
	Cliente *c = condominio->getClientes()[i];
	condominio->removeCliente(c);
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
			adicionaCliente();

			// Para testar se está a funcionar
			/*cout << "--- Condominio ---" << endl << endl;

			//cliente
			for(unsigned int i = 0; i < condominio->getClientes().size(); i++) {
				Cliente * cli = condominio->getClientes()[i];

				cout << "--- Cliente ---" << endl;
				cout << cli->getNome() << endl;
				cout << cli->getBI() << endl;

				//habitacoes de cada cliente
				cout << "--- Habitações ---" << endl;
				for(unsigned int j = 0; j < cli->getHabitacoes().size(); j++) {
					Habitacao *h = cli->getHabitacoes()[j];
					cout << h->getMorada() << endl;
					cout << h->getAreaHabitacao() << endl;

					cout << "--- Serviços da habitação ---" << endl;
					for(unsigned int k = 0; k < h->getServicos().size(); k++) {
						Empregado * servico = h->getServicos()[k];
						cout << servico->getNome() << endl;
						cout << servico->getBI() << endl;
						cout << servico->getTipo() << endl;
						cout << servico->getLivre() << endl;
					}
				}
			}*/

			break;

		case 2: // Remover Cliente
			removeCliente();

			// Para testar se está a funcionar
			/*cout << "--- Condominio ---" << endl << endl;

			//cliente
			for(unsigned int i = 0; i < condominio->getClientes().size(); i++) {
				Cliente * cli = condominio->getClientes()[i];

				cout << "--- Cliente ---" << endl;
				cout << cli->getNome() << endl;
				cout << cli->getBI() << endl;

				//habitacoes de cada cliente
				cout << "--- Habitações ---" << endl;
				for(unsigned int j = 0; j < cli->getHabitacoes().size(); j++) {
					Habitacao *h = cli->getHabitacoes()[j];
					cout << h->getMorada() << endl;
					cout << h->getAreaHabitacao() << endl;

					cout << "--- Serviços da habitação ---" << endl;
					for(unsigned int k = 0; k < h->getServicos().size(); k++) {
						Empregado * servico = h->getServicos()[k];
						cout << servico->getNome() << endl;
						cout << servico->getBI() << endl;
						cout << servico->getTipo() << endl;
						cout << servico->getLivre() << endl;
					}
				}
			}*/

			break;

		case 3:
			// melhoramento - ordenar lista por nome ou por bi

			imprimeClientes();
			break;

		case 4:
			// melhoramento - ordenar por ordem alfabética de morada

			imprimeDadosCliente();
			break;

		case 5:
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

int Interface::procuraHabitacao(string morada) {
	for(unsigned int i = 0; i < habitacoes.size(); i++ ) {
		Habitacao *h = habitacoes[i];
		if(h->getMorada() == morada)
			return i;
	}
	return -1;
}

int Interface::readClientes(string nome) {
	ifstream file(nome);
	if(!file.is_open())
		return -1;

	string nomeCliente;
	while(getline(file, nomeCliente)){
		string bi;
		string tipo;
		vector<Habitacao *> habs;
		getline(file, bi);
		getline(file, tipo);

		if(tipo == "habs") {
			string morada;
			getline(file, morada);

			while(morada != "endHabs") {
				int i = procuraHabitacao(morada);

				habs.push_back(habitacoes[i]);

				getline(file, morada);
			}

			Cliente *c = new Cliente(nomeCliente, atoi(bi.c_str()), habs);
			clientes.push_back(c);
		}
	}
	return 0;
}

int Interface::readEmpregados(string nome) {
	ifstream file(nome);
	if(!file.is_open())
		return -1;

	string nomeEmpregado;
	while(getline(file, nomeEmpregado)){
		string bi;
		string tipo;
		getline(file, bi);
		getline(file, tipo);

		if(tipo == "Limpeza") {
			string livre;
			getline(file, livre);

			Empregado *e = new Limpeza(nomeEmpregado, atoi(bi.c_str()), tipo, atoi(livre.c_str()));
			empregados.push_back(e);
		}
		if(tipo == "Canalizacao") {
			string livre;
			getline(file, livre);

			Empregado *e = new Canalizacao(nomeEmpregado, atoi(bi.c_str()), tipo, atoi(livre.c_str()));
			empregados.push_back(e);
		}
		if(tipo == "Pintura") {
			string livre;
			getline(file, livre);

			Empregado *e = new Pintura(nomeEmpregado, atoi(bi.c_str()), tipo, atoi(livre.c_str()));
			empregados.push_back(e);
		}
	}
	return 0;
}

int Interface::readCondominio(string nome) {
	ifstream file(nome);
	if(!file.is_open())
		return -1;

	string nomeCondominio;
	while(getline(file, nomeCondominio)){
		string nif;
		string maxEmpLimpeza;
		string maxEmpCanalizacao;
		string maxEmpPintura;

		getline(file, nif);
		getline(file, maxEmpLimpeza);
		getline(file, maxEmpCanalizacao);
		getline(file, maxEmpPintura);

		Servico *s = new Servico(empregados, atoi(maxEmpLimpeza.c_str()), atoi(maxEmpCanalizacao.c_str()), atoi(maxEmpPintura.c_str()));

		condominio = new Condominio(nomeCondominio, atoi(nif.c_str()), clientes, s);
	}

	return 0;
}

int Interface::procuraEmpregado(int bi) {
	for(unsigned int i = 0; i < empregados.size(); i++ ) {
		Empregado *e = empregados[i];
		if(e->getBI() == bi)
			return i;
	}
	return -1;
}

int Interface::readServicos(string nome) {
	ifstream file(nome);
	if(!file.is_open())
		return -1;

	string morada;
	while(getline(file, morada)){
		int i_hab = procuraHabitacao(morada);

		string bi;
		getline(file, bi);
		while(bi != "end") {
			int i_emp = procuraEmpregado(atoi(bi.c_str()));

			Habitacao * hab = habitacoes[i_hab];
			Empregado * emp = empregados[i_emp];
			hab->adicionaServico(emp);

			getline(file, bi);
		}
	}

	return 0;
}

Interface::Interface(string ficheiroHabitacoes, string ficheiroClientes, string ficheiroEmpregados, string ficheiroServicos, string ficheiroCondominio) {
	readHabitacoes(ficheiroHabitacoes);

	// Para testar se está a funcionar
	/*cout << "--- Habitações ---" << endl;
	for(unsigned int i = 0; i < habitacoes.size(); i++) {
		Habitacao *h = habitacoes[i];
		cout << h->getMorada() << endl;
		cout << h->getAreaHabitacao() << endl;
	}*/

	readClientes(ficheiroClientes);

	// Para testar se está a funcionar
	/*cout << "--- Clientes ---" << endl;
	for(unsigned int i = 0; i < clientes.size(); i++) {
		Cliente *c = clientes[i];
		cout << c->getNome() << endl;
		cout << c->getBI() << endl;
		for(unsigned int k = 0; k < clientes[i]->getHabitacoes().size(); k++) {
			Habitacao *h = clientes[i]->getHabitacoes()[k];
			cout << h->getMorada() << endl;
			cout << h->getAreaHabitacao() << endl;
		}
	}*/

	readEmpregados(ficheiroEmpregados);

	// Para testar se está a funcionar
	/*cout << "--- Empregados ---" << endl;
	for(unsigned int i = 0; i < empregados.size(); i++) {
			Empregado *e = empregados[i];
			cout << e->getNome() << endl;
			cout << e->getBI() << endl;
			cout << e->getTipo() << endl;
			cout << e->getLivre() << endl;
	}*/

	readServicos(ficheiroServicos);

	// Para testar se está a funcionar
	/*cout << "--- Serviços ---" << endl;
	for(unsigned int i = 0; i < clientes.size(); i++) {
		Cliente * cli = clientes[i];

		for(unsigned int j = 0; j < cli->getHabitacoes().size(); j++) {
			Habitacao * hab = cli->getHabitacoes()[j];
			cout << hab->getMorada() << endl;

			for(unsigned int k = 0; k < hab->getServicos().size(); k++) {
				Empregado * servico = hab->getServicos()[k];
				cout << servico->getNome() << endl;
				cout << servico->getBI() << endl;
				cout << servico->getTipo() << endl;
				cout << servico->getLivre() << endl;
			}
		}
	}*/

	readCondominio(ficheiroCondominio);

	/*cout << "--- Condominio ---" << endl << endl;

	//cliente
	for(unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente * cli = condominio->getClientes()[i];

		cout << "--- Cliente ---" << endl;
		cout << cli->getNome() << endl;
		cout << cli->getBI() << endl;

		//habitacoes de cada cliente
		cout << "--- Habitações ---" << endl;
		for(unsigned int j = 0; j < cli->getHabitacoes().size(); j++) {
			Habitacao *h = cli->getHabitacoes()[j];
			cout << h->getMorada() << endl;
			cout << h->getAreaHabitacao() << endl;

			cout << "--- Serviços da habitação ---" << endl;
			for(unsigned int k = 0; k < h->getServicos().size(); k++) {
				Empregado * servico = h->getServicos()[k];
				cout << servico->getNome() << endl;
				cout << servico->getBI() << endl;
				cout << servico->getTipo() << endl;
				cout << servico->getLivre() << endl;
			}
		}
	}
	//empregados do condominio
	cout << "--- Empregados ---" << endl;
	for(unsigned int i = 0; i < condominio->getServico()->getEmpregados().size(); i++) {
			Empregado *e = condominio->getServico()->getEmpregados()[i];
			cout << e->getNome() << endl;
			cout << e->getBI() << endl;
			cout << e->getTipo() << endl;
			cout << e->getLivre() << endl;
	}*/

}

int main(int argc, char *argv[]) {
	// Verifica número de argumentos
	if(argc != 6) {
		cerr << "É necessário especificar o nome dos 4 ficheiros.";
		return -1;
	}

	string argv1 = argv[1];
	string argv2 = argv[2];
	string argv3 = argv[3];
	string argv4 = argv[4];
	string argv5 = argv[5];

	Interface interface(argv1, argv2, argv3, argv4, argv5);

	cout << endl << " ***** GESTÃO DE UM CONDOMINIO *****" << endl << endl;

	interface.menuPrincipal();

	return 0;
}
