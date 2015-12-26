/*
 * interface.cpp
 *
 *  Created on: 05/11/2015
 *      Author: teresachaves
 */

#include "interface.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string>

Condominio Interface::interfaceAux(string ficheiroHabitacoes,
		string ficheiroClientes, string ficheiroEmpregados,
		string ficheiroServicos, string ficheiroCondominio) {
	vector<Habitacao *> hs = readHabitacoes(ficheiroHabitacoes);

	// Para testar se está a funcionar
	/*cout << "--- Habitações ---" << endl;
	 for(unsigned int i = 0; i < hs.size(); i++) {
	 Habitacao *h = hs[i];
	 cout << h->getMorada() << endl;
	 cout << h->getAreaHabitacao() << endl;
	 }*/

	vector<Cliente *> cs = readClientes(ficheiroClientes, hs);

	// Para testar se está a funcionar
	/*cout << "--- Clientes ---" << endl;
	for (unsigned int i = 0; i < cs.size(); i++) {
		Cliente *c = cs[i];
		cout << c->getNome() << endl;
		cout << c->getBI() << endl;
		for (unsigned int k = 0; k < hs.size(); k++) {
			Habitacao *h = hs[k];
			cout << h->getMorada() << endl;
			cout << h->getAreaHabitacao() << endl;
		}
	}*/

	vector<Empregado *> es = readEmpregados(ficheiroEmpregados);

	// Para testar se está a funcionar
	/*cout << "--- Empregados ---" << endl;
	 for(unsigned int i = 0; i < es.size(); i++) {
	 Empregado *e = es[i];
	 cout << e->getNome() << endl;
	 cout << e->getBI() << endl;
	 cout << e->getTipo() << endl;
	 cout << e->getLivre() << endl;
	 }*/

	vector<Servico *> ss = readServicos(ficheiroServicos, hs, es);

	// Para testar se está a funcionar
	/*cout << "--- Serviços ---" << endl;
	 for(unsigned int i = 0; i < cs.size(); i++) {
	 Cliente * cli = cs[i];

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

	Condominio * c = readCondominio(ficheiroCondominio, es, cs);

	/*cout << "--- Condominio ---" << endl << endl;

	 //cliente
	 for(unsigned int i = 0; i < c->getClientes().size(); i++) {
	 Cliente * cli = c->getClientes()[i];

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
	 for(unsigned int i = 0; i < c->getServico()->getEmpregados().size(); i++) {
	 Empregado *e = c->getServico()->getEmpregados()[i];
	 cout << e->getNome() << endl;
	 cout << e->getBI() << endl;
	 cout << e->getTipo() << endl;
	 cout << e->getLivre() << endl;
	 }*/

	return *c;
}

Interface::Interface(vector<string> condsDir) {
	conds = new EmpresaCondominios();

	for (unsigned int i = 0; i < condsDir.size(); i++) {
		string ficheiroHabitacoes = "condominios/" + condsDir[i]
				+ "/habitacoes.txt";
		string ficheiroClientes = "condominios/" + condsDir[i]
				+ "/clientes.txt";
		string ficheiroEmpregados = "condominios/" + condsDir[i]
				+ "/empregados.txt";
		string ficheiroServicos = "condominios/" + condsDir[i]
				+ "/servicos.txt";
		string ficheiroCondominio = "condominios/" + condsDir[i]
				+ "/condominio.txt";

		Condominio c = interfaceAux(ficheiroHabitacoes, ficheiroClientes,
				ficheiroEmpregados, ficheiroServicos, ficheiroCondominio);

		conds->adicionaCondominio(c);
	}
}

vector<Habitacao *> Interface::readHabitacoes(string nome) {
	vector<Habitacao *> habs;

	ifstream file(nome);
	if (!file.is_open()) {
		cout << "Não foi possível abrir o ficheiro!" << endl;
		return habs;
	}

	string tipo;
	while (getline(file, tipo)) {
		string morada;
		string areaHabitacao;
		getline(file, morada);
		getline(file, areaHabitacao);

		if (tipo == "a") {
			string tipologia;
			string piso;
			getline(file, tipologia);
			getline(file, piso);

			Habitacao * h = new Apartamento(morada, atoi(areaHabitacao.c_str()),
					"Apartamento", atoi(tipologia.c_str()), atoi(piso.c_str()));
			habs.push_back(h);
		}
		if (tipo == "v") {
			bool temP = false;

			string areaExterior;
			string temPiscina;
			getline(file, areaExterior);
			getline(file, temPiscina);

			if(temPiscina == "true")
				temP = true;

			Habitacao * h = new Vivenda(morada, atoi(areaHabitacao.c_str()),
					"Vivenda", atoi(areaExterior.c_str()), temP);
			habs.push_back(h);
		}
	}

	file.close();

	return habs;
}

vector<Cliente *> Interface::readClientes(string nome, vector<Habitacao *> hs) {
	vector<Cliente *> cls;
	ifstream file(nome);

	if (!file.is_open())
		return cls;

	string nomeCliente;
	while (getline(file, nomeCliente)) {
		string bi;
		string tipo;
		string telm;
		string email;
		vector<Habitacao *> habs;
		getline(file, bi);
		getline(file, telm);
		getline(file, email);
		getline(file, tipo);

		if (tipo == "habs") {
			string morada;
			getline(file, morada);

			while (morada != "endHabs") {
				int k = -1;
				for (unsigned int i = 0; i < hs.size(); i++) {
					Habitacao *h = hs[i];
					if (h->getMorada() == morada)
						k = i;
				}

				habs.push_back(hs[k]);

				getline(file, morada);
			}

			Cliente *c = new Cliente(nomeCliente, atoi(bi.c_str()),
					atoi(telm.c_str()), email, habs);

			cls.push_back(c);
		}
	}

	file.close();

	return cls;
}

vector<Empregado *> Interface::readEmpregados(string nome) {
	vector<Empregado *> emps;
	ifstream file(nome);
	if (!file.is_open())
		return emps;

	string nomeEmpregado;
	while (getline(file, nomeEmpregado)) {
		string bi;
		string telm;
		string email;
		string tipo;
		getline(file, bi);
		getline(file, telm);
		getline(file, email);
		getline(file, tipo);

		if (tipo == "Limpeza") {
			string livre;
			getline(file, livre);

			Empregado *e = new Limpeza(nomeEmpregado, atoi(bi.c_str()),
					atoi(telm.c_str()), email, tipo, atoi(livre.c_str()));
			emps.push_back(e);
		}
		if (tipo == "Canalizacao") {
			string livre;
			getline(file, livre);

			Empregado *e = new Canalizacao(nomeEmpregado, atoi(bi.c_str()),
					atoi(telm.c_str()), email, tipo, atoi(livre.c_str()));
			emps.push_back(e);
		}
		if (tipo == "Pintura") {
			string livre;
			getline(file, livre);

			Empregado *e = new Pintura(nomeEmpregado, atoi(bi.c_str()),
					atoi(telm.c_str()), email, tipo, atoi(livre.c_str()));
			emps.push_back(e);
		}
	}

	file.close();

	return emps;
}

vector<Servico *> Interface::readServicos(string nome,
		vector<Habitacao *> &habs, vector<Empregado *> &emps) {
	vector<Servico *> servs;
	ifstream file(nome);
	if (!file.is_open())
		return servs;

	string morada;
	while (getline(file, morada)) {
		int i_hab = -1;
		for (unsigned int i = 0; i < habs.size(); i++) {
			Habitacao *h = habs[i];
			if (h->getMorada() == morada)
				i_hab = i;
		}

		string bi;
		getline(file, bi);
		while (bi != "end") {
			int i_emp = -1;
			for (unsigned int i = 0; i < emps.size(); i++) {
				Empregado *e = emps[i];
				if (e->getBI() == atoi(bi.c_str()))
					i_emp = i;
			}

			Habitacao * hab = habs[i_hab];
			Empregado * emp = emps[i_emp];
			hab->adicionaServico(emp);

			getline(file, bi);
		}
	}

	file.close();

	return servs;
}

Condominio * Interface::readCondominio(string nome, vector<Empregado *> emps,
		vector<Cliente *> cls) {
	Condominio * condos = NULL;
	ifstream file(nome);

	if (!file.is_open()) {
		cout << "Não foi possível abrir o ficheiro!" << endl;
		return condos;
	}

	string nomeCondominio;
	string nif;
	string numTelf;
	string email;
	string maxEmpLimpeza;
	string maxEmpCanalizacao;
	string maxEmpPintura;
	string localizacao;

	getline(file, nomeCondominio);
	getline(file, nif);
	getline(file, numTelf);
	getline(file, email);
	getline(file, maxEmpLimpeza);
	getline(file, maxEmpCanalizacao);
	getline(file, maxEmpPintura);
	getline(file, localizacao);

	Servico *s = new Servico(emps, atoi(maxEmpLimpeza.c_str()),
			atoi(maxEmpCanalizacao.c_str()), atoi(maxEmpPintura.c_str()));

	condos = new Condominio(nomeCondominio, atoi(nif.c_str()),
			atoi(numTelf.c_str()), email, cls, s, localizacao);

	file.close();

	return condos;
}

int Interface::writeHabitacoes() const {
	string id = to_string(condominio->getId()); //converte o Id do condomínio para uma string
	string nome = "condominios/" + id + "-" + condominio->getDesignacao()
			+ "/habitacoes.txt"; //nome do ficheiro
	ofstream file(nome);

	if (!file.is_open())
		return -1;

	vector<Habitacao *>::const_iterator itb = habitacoes.begin();
	vector<Habitacao *>::const_iterator ite = habitacoes.end();

	for (; itb != ite; itb++) {
		string tipo = (*itb)->getTipo();

		if (tipo == "Apartamento")
			file << "a" << endl;
		else
			file << "v" << endl;
		file << (*itb)->getMorada() << endl;
		file << (*itb)->getAreaHabitacao() << endl;

		if (tipo == "Apartamento") {
			Apartamento *ap = (Apartamento *) (*itb);

			file << ap->getTipologia() << endl;
			file << ap->getPiso() << endl;
		}

		else if (tipo == "Vivenda") {
			Vivenda *viv = (Vivenda *) (*itb);

			file << viv->getAreaExterior() << endl;
			file << ((viv->getTemPiscina()) ? "true" : "false") << endl;
		}
	}

	file.close();

	return 0;
}

int Interface::writeClientes() const {
	string id = to_string(condominio->getId()); //converte o Id do condomínio para uma string
	string nome = "condominios/" + id + "-" + condominio->getDesignacao()
			+ "/clientes.txt"; //nome do ficheiro
	ofstream file(nome);

	if (!file.is_open())
		return -1;

	vector<Cliente *>::const_iterator itb = clientes.begin();
	vector<Cliente *>::const_iterator ite = clientes.end();

	for (; itb != ite; itb++) {
		file << (*itb)->getNome() << endl;
		file << (*itb)->getBI() << endl;
		file << (*itb)->getNumeroTelemovel() << endl;
		file << (*itb)->getEmail() << endl;

		file << "habs" << endl;

		vector<Habitacao *> habitacoes_cliente = (*itb)->getHabitacoes();

		vector<Habitacao *>::const_iterator ithb = habitacoes_cliente.begin();
		vector<Habitacao *>::const_iterator ithe = habitacoes_cliente.end();

		for (; ithb != ithe; ithb++)
			file << (*ithb)->getMorada() << endl;

		file << "endHabs" << endl;
	}

	file.close();

	return 0;
}

int Interface::writeEmpregados() const {
	string id = to_string(condominio->getId()); //converte o Id do condomínio para uma string
	string nome = "condominios/" + id + "-" + condominio->getDesignacao()
			+ "/empregados.txt"; //nome do ficheiro
	ofstream file(nome);

	if (!file.is_open())
		return -1;

	Servico * servico = condominio->getServico();

	vector<Empregado *> empregados_servico = servico->getEmpregados();
	vector<Empregado *>::const_iterator itb = empregados_servico.begin();
	vector<Empregado *>::const_iterator ite = empregados_servico.end();

	for (; itb != ite; itb++) {

		file << (*itb)->getNome() << endl;
		file << (*itb)->getBI() << endl;
		file << (*itb)->getNumeroTelemovel() << endl;
		file << (*itb)->getEmail() << endl;
		file << (*itb)->getTipo() << endl;
		file << (*itb)->getLivre() << endl;

	}

	file.close();

	return 0;
}

int Interface::writeServicos() const {
	string id = to_string(condominio->getId()); //converte o Id do condomínio para uma string
	string nome = "condominios/" + id + "-" + condominio->getDesignacao()
			+ "/servicos.txt"; //nome do ficheiro
	ofstream file(nome);

	if (!file.is_open())
		return -1;

	vector<Habitacao *>::const_iterator itb = habitacoes.begin();
	vector<Habitacao *>::const_iterator ite = habitacoes.end();

	for (; itb != ite; itb++) {
		file << (*itb)->getMorada() << endl;

		vector<Empregado *> servicos_habitacao = (*itb)->getServicos();
		vector<Empregado *>::const_iterator itsb = servicos_habitacao.begin();
		vector<Empregado *>::const_iterator itse = servicos_habitacao.end();

		for (; itsb != itse; itsb++)
			file << (*itsb)->getBI() << endl;

		file << "end" << endl;
	}

	file.close();

	return 0;
}

int Interface::writeCondominio() const {
	string id = to_string(condominio->getId()); //converte o Id do condomínio para uma string
	string nome = "condominios/" + id + "-" + condominio->getDesignacao()
			+ "/condominio.txt"; //nome do ficheiro
	ofstream file(nome);

	cout << nome << endl;

	if (!file.is_open())
		return -1;

	Servico *servico = condominio->getServico();

	file << condominio->getDesignacao() << endl;
	file << condominio->getNIF() << endl;
	file << condominio->getNumeroTelefone() << endl;
	file << condominio->getEmail() << endl;

	file << servico->getNumMaxLimpeza() << endl;
	file << servico->getNumMaxCanalizacao() << endl;
	file << servico->getNumMaxPintura() << endl;

	file << condominio->getLocalizacao() << endl;

	file.close();

	return 0;
}

int Interface::procuraHabitacao(string morada) {
	for (unsigned int i = 0; i < habitacoes.size(); i++) {
		Habitacao *h = habitacoes[i];
		if (h->getMorada() == morada)
			return i;
	}
	return -1;
}

int Interface::procuraCliente(int bi) {
	for (unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];

		if (c->getBI() == bi)
			return i;
	}

	return -1;
}

int Interface::procuraEmpregado(int bi) {
	for (unsigned int i = 0; i < empregados.size(); i++) {
		Empregado *e = empregados[i];
		if (e->getBI() == bi)
			return i;
	}
	return -1;
}

void Interface::imprimeClientes() {
	cout << endl << "*** Lista de Clientes do condominio "
			<< condominio->getDesignacao() << " ***" << endl << endl;

	for (unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];

		cout << "-> Nome: " << c->getNome() << " BI: " << c->getBI() << endl;
	}

	cout << endl;
}

void Interface::imprimeDadosCliente() {
	cout << endl << "*** Dados do Cliente ***" << endl << endl;

	cout << endl << "Número do bilhete de identidade do cliente: ";
	int bi;
	cin >> bi;

	int i = procuraCliente(bi);
	Cliente *c = condominio->getClientes()[i];

	cout << "-> Nome: " << c->getNome() << endl;
	cout << "   BI: " << c->getBI() << endl;
	cout << "   Número de telemóvel: " << c->getNumeroTelemovel() << endl;
	cout << "   Email: " << c->getEmail() << endl;
	cout << "   Habitações: ";

	for (unsigned int i = 0; i < c->getHabitacoes().size(); i++) {
		Habitacao *h = c->getHabitacoes()[i];

		if (i != 0) {
			cout << "               " << i + 1 << ". " << h->getMorada()
					<< endl;
		} else {
			cout << i + 1 << ". " << h->getMorada() << endl;
		}
	}

	cout << endl;
}

void Interface::imprimeDadosCondominio() {
	int numHabs = 0, numLimpeza = 0, numCanalizacao = 0, numPintura = 0;

	cout << "Nome: " << condominio->getDesignacao() << endl;
	cout << "NIF: " << condominio->getNIF() << endl;
	cout << "Número de telefone: " << condominio->getNumeroTelefone() << endl;
	cout << "Email: " << condominio->getEmail() << endl << endl;

	cout << "Número de clientes: " << condominio->getClientes().size() << endl;

	for (int i = 0; i < condominio->getClientes().size(); i++)
		numHabs += condominio->getClientes()[i]->getHabitacoes().size();

	cout << "Número de habitações: " << numHabs << endl;
	cout << "Número de empregados: "
			<< condominio->getServico()->getEmpregados().size() << endl;

	for (int i = 0; i < condominio->getServico()->getEmpregados().size(); i++) {
		if (condominio->getServico()->getEmpregados()[i]->getTipo()
				== "Limpeza") {
			numLimpeza++;
		}

		else if (condominio->getServico()->getEmpregados()[i]->getTipo()
				== "Canalizacao") {
			numCanalizacao++;
		}

		else
			numPintura++;
	}

	cout << "     Número de empregados de Limpeza: " << numLimpeza << endl;
	cout << "     Número de empregados de Canalização: " << numCanalizacao
			<< endl;
	cout << "     Número de empregados de Pintura: " << numPintura << endl
			<< endl;

}

void Interface::imprimeHabitacoes() {
	vector<Cliente*> c = condominio->getClientes();

	for (unsigned int i = 0; i < c.size(); i++) {
		vector<Habitacao*> habs = c[i]->getHabitacoes();

		cout << "*** Lista Habitações do cliente " << c[i]->getBI() << " ***"
				<< endl;

		for (int j = 0; j < habs.size(); j++) {
			Habitacao *hab = habs[j];
			cout << "     Morada: " << hab->getMorada() << endl;
			cout << "     Área Habitação: " << hab->getAreaHabitacao() << "m^2"
					<< endl;
			cout << "     Mensalidade: " << hab->mensalidade() << "€" << endl;
		}

		cout << endl;
	}

	cout << endl;
}

void Interface::adicionaCliente() {
	cout << endl << "*** Adicionar um cliente novo ***" << endl;

	cout << "Nome: ";
	string nome;
	cin >> nome;

	cout << "BI: ";
	int bi;
	cin >> bi;

	cout << "Numero de telemovel: ";
	int numTelm;
	cin >> numTelm;

	cout << "Email: ";
	string email;
	cin >> email;

	vector<Habitacao *> habs; // As habitações são inseridas posteriormente no menu do cliente

	Cliente *c = new Cliente(nome, bi, numTelm, email, habs);

	condominio->adicionaCliente(c);
}

void Interface::removeCliente() {
	cout << endl << "*** Remover um cliente novo ***" << endl;

	cout << "BI: ";
	int bi;
	cin >> bi;

	int i = procuraCliente(bi);
	Cliente *c = condominio->getClientes()[i];
	condominio->removeCliente(c);
}

void Interface::pagaMensalidade() {
	int bi;
	float total = 0;

	cout << "BI Cliente: ";
	cin >> bi;
	cout << endl;

	Cliente* c = clientes[procuraCliente(bi)];
	vector<Habitacao*> h = c->getHabitacoes();

	for (int i = 0; i < h.size(); i++) {
		Habitacao *hab = h[i];
		cout << hab->getMorada() << ": " << hab->mensalidade() << "€" << endl;
		total = total + hab->mensalidade();
	}
	cout << "Total a pagar: " << total << "€" << endl;

}

void Interface::adicionaHabitacao() {
	int bi, nHab, areaHab;
	string tipoHab, morada;

	cout << "Introduza o BI do Cliente: ";
	cin >> bi;
	cin.ignore();

	Cliente* c = clientes[procuraCliente(bi)];
	vector<Habitacao*> h = c->getHabitacoes();

	cout << "N.º de habitações novas: ";
	cin >> nHab;
	cin.ignore();

	while (nHab > 0) {
		cout << "Vivenda ou Apartamento: ";
		getline(cin, tipoHab);

		if (tipoHab == "Vivenda") {
			cout << "Morada: ";
			getline(cin, morada);
			cout << "\n";

			cout << "Área Habitação: ";
			cin >> areaHab;
			cin.ignore();
			cout << "\n";

			int areaExterior;

			cout << "Área Exterior: ";
			cin >> areaExterior;
			cin.ignore();
			cout << "\n";

			string piscina;
			cout << "Tem Piscina? (S ou N) ";
			cin >> piscina;
			cin.ignore();
			if (piscina == "S") {
				Vivenda* habitacao = new Vivenda(morada, areaHab, "Vivenda",
						areaExterior, true);
				c->adicionaHabitacao(habitacao);
			} else {
				Vivenda* habitacao = new Vivenda(morada, areaHab, "Vivenda",
						areaExterior, false);
				c->adicionaHabitacao(habitacao);
			}
		} else if (tipoHab == "Apartamento") {
			cout << "Morada: ";
			getline(cin, morada);
			cout << "\n";

			cout << "Área Habitação: ";
			cin >> areaHab;
			cin.ignore();
			cout << "\n";

			int tipologia, piso;

			cout
					<< "Tipologia (escreva apenas o número. Exemplo: T3 escreve-se 3): ";
			cin >> tipologia;
			cin.ignore();
			cout << "\n";

			cout << "Piso: ";
			cin >> piso;
			cin.ignore();
			cout << "\n";

			Apartamento* habitacao = new Apartamento(morada, areaHab,
					"Apartamento", tipologia, piso);
			c->adicionaHabitacao(habitacao);
		}
		nHab--;
	}
}

void Interface::consultarDadosHabitacao() {
	string morada;

	cout << "Introduza a morada da habitação: ";
	cin.ignore();
	getline(cin, morada);
	cout << "\n";

	for (unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];
		for (unsigned int j = 0; j < c->getHabitacoes().size(); j++) {
			Habitacao *h = c->getHabitacoes()[j];
			if (h->getMorada() == morada)
				h->getInformacoes();
		}
	}
}

void Interface::removeHabitacao() {
	int bi;
	string morada;
	cout << "Introduza o BI do Cliente: ";
	cin >> bi;
	cin.ignore();
	cout << "\n";

	int i = procuraCliente(bi);
	Cliente* c = condominio->getClientes()[i];

	cout << "Introduza a morada: ";
	getline(cin, morada);
	cout << "\n";

	for (unsigned int j = 0; j < c->getHabitacoes().size(); j++) {
		Habitacao *h = c->getHabitacoes()[j];
		if (h->getMorada() == morada) {
			c->removeHabitacao(h);
			break;
		}
	}

}

void Interface::requisitaServico() {
	cout << "Morada: " << endl;
	string morada;
	cin.ignore();
	getline(cin, morada);

	cout << "Tipo de serviço: " << endl;
	string tipo;
	cin >> tipo;
	cin.ignore();

	for (unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];
		for (unsigned int j = 0; j < c->getHabitacoes().size(); j++) {
			Habitacao *h = c->getHabitacoes()[j];
			if (h->getMorada() == morada)
				condominio->requisitaServico(tipo, h);
		}
	}
}

void Interface::terminaServico() {
	int bi;
	string morada;

	cout << "Introduza BI do Empregado: ";
	cin >> bi;
	cin.ignore();
	cout << "\n";

	int i = procuraEmpregado(bi);
	Servico* s = condominio->getServico();
	Empregado* e = s->getEmpregados()[i];

	condominio->fimDoServico(e);
}

void Interface::historicoServicosHabitacao() {
	string morada;

	cout << "Introduza a morada da habitação: ";
	cin.ignore();
	getline(cin, morada);
	cout << "\n";

	for (unsigned int i = 0; i < condominio->getClientes().size(); i++) {
		Cliente *c = condominio->getClientes()[i];
		for (unsigned int j = 0; j < c->getHabitacoes().size(); j++) {
			Habitacao *h = c->getHabitacoes()[j];
			if (h->getMorada() == morada) {
				for (unsigned int k = 0; k < h->getServicos().size(); k++) {
					Empregado *e = h->getServicos()[k];
					cout << "Nome: " << e->getNome() << endl;
					cout << "BI: " << e->getBI() << endl;
					cout << "Tipo: " << e->getTipo() << endl;
				}
			}
		}
	}

	cout << endl;
}

void Interface::menuPrincipal() {
	int op;

	do {
		cout << endl << "*** Menu Principal ***" << endl << endl;
		cout << "     1. Condominio" << endl;
		cout << "     2. Cliente" << endl;
		cout << "     3. Empregado" << endl;
		cout << "     4. Sair" << endl;

		cout << ">  ";
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
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}

	} while (op != 4);
}

void Interface::menuCondominio() {
	int op;

	do {
		cout << endl << "*** Condomínio ***" << endl << endl;
		cout << "     1. Adiciona Cliente" << endl;
		cout << "     2. Remover Cliente" << endl;
		cout << "     3. Consultar Lista  Clientes" << endl;
		cout << "     4. Consultar dados Cliente" << endl;
		cout << "     5. Atualizar dados do Cliente" << endl;
		cout << "     6. Consultar dados do Condominio" << endl;
		cout << "     7. Atualizar dados do Condomínio" << endl;
		cout << "     8. Sair" << endl;

		cout << "> ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			cout << endl << "*** Adiciona Cliente ***" << endl << endl;
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
			cout << endl << "*** Remover Cliente ***" << endl << endl;
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
			cout << endl << "*** Consultar Lista  Clientes ***" << endl << endl;
			imprimeClientes();
			break;

		case 4:
			cout << endl << "*** Consultar dados Cliente ***" << endl << endl;
			imprimeDadosCliente();
			break;

		case 5:
			int bi_atualizar;
			cout << endl << "*** Atualizar dados do Cliente ***" << endl
					<< endl;

			cout << "Qual o bi do cliente a atualizar?" << endl << endl;
			cout << "> ";

			cin >> bi_atualizar;
			cin.ignore();

			menuAtualizaCliente(bi_atualizar);
			break;

		case 6:
			cout << endl << "*** Consultar dados do condomínio ***" << endl
					<< endl;
			imprimeDadosCondominio();
			break;

		case 7:
			cout << endl << "*** Atualizar dados do Condomínio ***" << endl;

			menuAtualizaCondominio();
			break;

		case 8:
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 8);
}

void Interface::menuCliente() {
	int op, bi_atualizar;
	string morada_atualizar;

	do {
		cout << endl << "*** Cliente ***" << endl << endl;
		cout << "     1. Pagar mensalidade" << endl;
		cout << "     2. Adicionar habitação" << endl;
		cout << "     3. Remover habitação" << endl;
		cout << "     4. Requisitar serviço" << endl;
		cout << "     5. Listar habitações" << endl;
		cout << "     6. Consultar dados habitação" << endl;
		cout << "     7. Listar histórico serviços habitação" << endl;
		cout << "     8. Consultar dados do Condomínio" << endl;
		cout << "     9. Atualizar dados do Cliente" << endl;
		cout << "     10. Atualizar dados de uma habitação" << endl;
		cout << "     11. Sair" << endl;

		cout << "> ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			cout << endl << "*** Pagar mensalidade ***" << endl << endl;
			pagaMensalidade();
			break;

		case 2:
			cout << endl << "*** Adicionar habitação ***" << endl << endl;
			adicionaHabitacao();
			break;

		case 3:
			cout << endl << "*** Remover habitação ***" << endl << endl;
			removeHabitacao();
			break;

		case 4:
			cout << endl << "*** Requisita Serviço ***" << endl << endl;
			requisitaServico();
			break;

		case 5:
			cout << endl << "*** Listar habitações ***" << endl << endl;
			imprimeHabitacoes();
			break;

		case 6:
			cout << endl << "*** Consultar dados habitação ***" << endl << endl;
			consultarDadosHabitacao();
			break;

		case 7:
			cout << endl << "*** Listar histórico serviços habitação ***"
					<< endl << endl;
			historicoServicosHabitacao();
			break;

		case 8:
			cout << endl << "*** Consultar dados do condomínio ***" << endl
					<< endl;
			imprimeDadosCondominio();
			break;

		case 9:
			cout << endl << "*** Atualizar dados do Cliente ***" << endl
					<< endl;

			cout << "Qual o bi do cliente a atualizar?" << endl << endl;
			cout << "> ";

			cin >> bi_atualizar;
			cin.ignore();

			menuAtualizaCliente(bi_atualizar);
			break;

		case 10:
			cout << endl << "*** Atualizar dados de uma habitação ***" << endl;

			cout << "Qual a morada da habitação a atualizar?" << endl << endl;
			cout << "> ";

			cin.ignore();
			getline(cin, morada_atualizar);

			menuAtualizaHabitacao(morada_atualizar);
			break;

		case 11:
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 11);
}

void Interface::menuEmpregado() {
	int op;

	do {
		cout << endl << "*** Empregado ***" << endl << endl;
		cout << "     1. Terminar serviço" << endl;
		cout << "     2. Consultar histórico serviços" << endl;
		cout << "     3. Consultar dados do condomínio" << endl;
		cout << "     4. Sair" << endl;

		cout << "> ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			cout << endl << "*** Terminar serviço ***" << endl << endl;
			terminaServico();
			break;

		case 2:
			cout << endl << "*** Consultar histórico serviços ***" << endl
					<< endl;
			historicoServicosHabitacao();
			break;

		case 3:
			cout << endl << "*** Consultar dados do condomínio ***" << endl
					<< endl;
			imprimeDadosCondominio();
			break;

		case 4:
			break;

		default:
			cout << "Introduza uma opção válida!" << endl;
			break;
		}
	} while (op != 4);
}

int Interface::menuAtualizaCliente(int bi_atualizar) {
	int idCliente = procuraCliente(bi_atualizar);

	if (bi_atualizar == -1) {
		cout << endl << "Não existe nenhum Cliente com o bi " << bi_atualizar
				<< "!" << endl;
		return -1;
	}

	else {
		int op;

		do {
			cout << endl << "O que pretende atualizar?" << endl;
			cout << "     1. Nome" << endl;
			cout << "     2. BI" << endl;
			cout << "     3. Número de telemóvel" << endl;
			cout << "     4. Email" << endl;
			cout << "     5. Sair" << endl;

			cout << "> ";

			cin >> op;
			cin.ignore();

			cout << endl;

			string novoNome, novoEmail;
			int novoBI, novoTelm;

			switch (op) {
			case 1: // mudar nome
				cout << endl << "Insira o novo nome" << endl;
				cout << "> ";

				getline(cin, novoNome);

				clientes[idCliente]->setNome(novoNome);
				cout << endl << "Nome atualizado com sucesso!" << endl;
				op = 5;
				break;

			case 2: // mudar bi
				cout << endl << "Insira o novo bi" << endl;
				cout << "> ";

				cin >> novoBI;
				cin.ignore();

				clientes[idCliente]->setBI(novoBI);
				cout << endl << "BI atualizado com sucesso!" << endl;
				op = 5;
				break;

			case 3: // mudar número de telemóvel
				cout << endl << "Insira o novo número de telemóvel" << endl;
				cout << "> ";

				cin >> novoTelm;
				cin.ignore();

				clientes[idCliente]->setNumeroTelemovel(novoTelm);
				cout << endl << "Número de telemóvel atualizado com sucesso!"
						<< endl;
				op = 5;
				break;

			case 4: // mudar email
				cout << endl << "Insira o novo email" << endl;
				cout << "> ";

				cin >> novoEmail;
				cin.ignore();

				clientes[idCliente]->setEmail(novoEmail);
				cout << endl << "Email atualizado com sucesso!" << endl;
				op = 5;
				break;

			case 5: // sair
				break;

			default:
				cout << endl << "Escolha uma opção válida!" << endl;
				continue;
			}
		} while (op != 5);

		return 0;
	}
}

void Interface::menuAtualizaCondominio() {
	int op;

	do {
		int novo_nif, novo_numTelf;
		string novo_email, novo_nome;
		stringstream newName, oldName;

		cout << endl << "O que pretende atualizar?" << endl;
		cout << "     1. NIF" << endl;
		cout << "     2. Número de telefone" << endl;
		cout << "     3. Email" << endl;
		cout << "     4. Sair" << endl;

		cout << "> ";

		cin >> op;
		cin.ignore();

		switch (op) {
		case 1:
			cout << endl << "*** Atualizar NIF do Condomínio ***" << endl
					<< endl;

			cout << "Novo NIF: ";
			cin >> novo_nif;
			cin.ignore();

			condominio->setNIF(novo_nif);
			cout << endl << "NIF atualizado com sucesso!" << endl;
			op = 4;
			break;

		case 2:
			cout << endl << "*** Atualizar número de telefone do Condomínio ***"
					<< endl << endl;

			cout << "Novo número de telefone: ";
			cin >> novo_numTelf;
			cin.ignore();

			condominio->setNumeroTelefone(novo_numTelf);
			cout << endl << "Número de telefone atualizado com sucesso!"
					<< endl;
			op = 4;
			break;

		case 3:
			cout << endl << "*** Atualizar email do Condomínio ***" << endl
					<< endl;

			cout << "Novo email: ";
			getline(cin, novo_email);

			condominio->setEmail(novo_email);
			cout << endl << "Email atualizado com sucesso!" << endl;
			op = 4;
			break;

		case 4:
			break;

		default:
			cout << endl << "Escolha uma opção válida!" << endl;
			break;
			;
		}
	} while (op != 4);
}

int Interface::menuAtualizaHabitacao(string morada_atualizar) {
	int idMorada = procuraHabitacao(morada_atualizar);

	vector<Habitacao *>::iterator itHab = habitacoes.begin() + idMorada;

	if (idMorada == -1) {
		cout << endl << "Não existe nenhuma habitação com a morada "
				<< morada_atualizar << "!" << endl;
		return -1;
	}

	else {
		int op;

		do {
			cout << endl << "O que pretende atualizar?" << endl;
			cout << "     1. Morada" << endl;
			cout << "     2. Área habitacional" << endl;

			if ((*itHab)->getTipo() == "Apartamento") {
				cout << "     3. Tipologia" << endl;
				cout << "     4. Piso" << endl;
				cout << "     5. Sair" << endl;
			} else {
				cout << "     3. Área Exterior" << endl;
				cout << "     4. Piscina" << endl;
				cout << "     5. Sair" << endl;
			}

			cout << "> ";

			cin >> op;
			cin.ignore();

			cout << endl;

			string novaMorada, novoPiscina;
			int novaAreaHab, novaTipologia, novaAreaExt, novoPiso;
			int inputOK = 0;

			switch (op) {
			case 1:
				cout << endl << "Insira a nova morada" << endl;
				cout << "> ";

				getline(cin, novaMorada);

				(*itHab)->setMorada(novaMorada);
				cout << endl << "Morada atualizada com sucesso!" << endl;
				op = 5;
				break;

			case 2:
				cout << endl << "Insira o novo area habitacional" << endl;
				cout << "> ";

				cin >> novaAreaHab;
				cin.ignore();

				(*itHab)->setAreaHabitacao(novaAreaHab);
				cout << endl << "Área habitacional atualizada com sucesso!"
						<< endl;
				op = 5;
				break;

			case 3:
				if ((*itHab)->getTipo() == "Apartamento") {
					Apartamento *ap = (Apartamento *) (*itHab);

					cout << endl << "Insira a nova tipologia" << endl;
					cout << "> ";

					cin >> novaTipologia;
					cin.ignore();

					ap->setTipologia(novaTipologia);

					cout << endl
							<< "Tipologia atualizada com sucesso! O apartamento passou a ter uma tipologia = "
							<< ap->getTipologia() << "." << endl;
					op = 5;
					break;
				}

				else {
					Vivenda *viv = (Vivenda *) (*itHab);
					cout << endl << "Insira a nova área exterior" << endl;
					cout << "> ";

					cin >> novaAreaExt;
					cin.ignore();

					viv->setAreaExterior(novaAreaExt);

					cout << endl
							<< "Área exterior atualizada com sucesso! A vivenda passou a ter uma area exterior de "
							<< viv->getAreaExterior() << "." << endl;
					op = 5;
					break;
				}

			case 4:
				if ((*itHab)->getTipo() == "Apartamento") {
					Apartamento *ap = (Apartamento *) (*itHab);

					cout << endl << "Insira o novo piso" << endl;
					cout << "> ";

					cin >> novoPiso;
					cin.ignore();

					ap->setPiso(novoPiso);

					cout << endl
							<< "Piso atualizado com sucesso! O apartamento passou a ter piso = "
							<< ap->getPiso() << "." << endl;
					op = 5;
					break;
				}

				else {
					Vivenda *viv = (Vivenda *) (*itHab);

					while (inputOK == 0) {
						cout << endl << "Tem piscina? (Sim/Nao)" << endl;
						cout << "> ";

						getline(cin, novoPiscina);

						if (novoPiscina == "Sim" || novoPiscina == "sim"
								|| novoPiscina == "SIM") {
							viv->setTemPiscina(true);
							inputOK = 1;
						}

						else if (novoPiscina == "Nao" || novoPiscina == "nao"
								|| novoPiscina == "NAO") {
							viv->setTemPiscina(false);
							inputOK = 1;
						}

						else
							cout << endl << "Insira uma opção válida!" << endl;
					}

					cout << endl << "Área exterior atualizada com sucesso!"
							<< endl;
					op = 5;
					break;
				}

			case 5:
				break;

			default:
				cout << endl << "Escolha uma opção válida!" << endl;
				continue;
			}
		} while (op != 5);

		return 0;
	}
}

EmpresaCondominios * Interface::getEmpresaCondominios() {
	return conds;
}

void Interface::setAll(Condominio *cond) {
	condominio = cond;

	vector<Habitacao *> habs;

	vector<Cliente *> clients = cond->getClientes();

	for(unsigned int i = 0; i < clients.size(); i++) {
		vector<Habitacao *> habs_client = clients[i]->getHabitacoes();

		for(unsigned j = 0; j < habs_client.size(); j++)
			habs.push_back(habs_client[j]);
	}

	habitacoes = habs;
	clientes = cond->getClientes();
	empregados = cond->getServico()->getEmpregados();
}

// Função para recolher o nome de todos os diretórios

vector<string> getDirs(vector<string> &dirNames) {
	const char* PATH = "condominios";
	stringstream ss;
	vector<string> ret;

	DIR *dir = opendir(PATH);

	struct dirent *entry = readdir(dir);

	while (entry != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			entry = readdir(dir);

		else if (entry->d_type == DT_DIR) {
			dirNames.push_back(entry->d_name); // para guardar os nomes das pastas

			// para guardar o nome dos condominios
			ss << entry->d_name;
			string s = ss.str();
			string name = s.substr(s.find("-") + 1);
			ss.str("");
			ss.clear();
			ret.push_back(name);
			entry = readdir(dir);
		}
	}

	closedir(dir);

	return ret;
}

// Função para verificar se o input é válido

bool validInput(string in) {
	for (unsigned int i = 0; i < in.size(); i++) {
		if (!isdigit(in[i]))
			return false;
	}
	return true;
}

int main() {
	vector<string> nomeDirs;
	vector<string> cond = getDirs(nomeDirs);
	string op;

	Interface interface(nomeDirs);

	cout << " * * * * * * * * * * * * * * * * * * * *  " << endl;
	cout << "*                                        *" << endl;
	cout << "*   Bem vindo ao gestor de condominios   *" << endl;
	cout << "*                                        *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * *  " << endl << endl;

	while (1) {
		vector<string>::iterator itb = cond.begin();
		int i = 1;

		cout << endl << "*** Menu inicial ***" << endl << endl;

		for (; itb != cond.end(); itb++) {
			cout << i << ". " << (*itb) << endl;
			i++;
		}

		cout << i++ << ". Adicionar um novo condominio" << endl;
		cout << i++ << ". Remover um condominio" << endl;
		cout << i++ << ". Sair" << endl;
		cout << endl << "> ";

		cin >> op;

		if (validInput(op)) {
			// é um condominio
			if (atoi(op.c_str()) <= cond.size()) {

				string nomeOp = cond[atoi(op.c_str()) - 1];

				Condominio cOp = interface.getEmpresaCondominios()->find(nomeOp);

				interface.setAll(&cOp);

				interface.menuPrincipal();

				interface.writeClientes();
				interface.writeCondominio();
				interface.writeEmpregados();
				interface.writeHabitacoes();
				interface.writeServicos();

				cin.ignore();
			}

			// é uma das outras opções
			if (atoi(op.c_str()) == cond.size() + 1) { // adiciona novo condominio
				string nome, email;
				int nif, numTelf, maxLimpeza, maxCanalizacao, maxPintura;

				cout << endl << "*** Adicionar um novo Condomínio ***" << endl
						<< endl;

				cout << "Nome: ";
				cin >> nome;
				cin.ignore();
				cout << endl;

				cout << "NIF: ";
				cin >> nif;
				cin.ignore();
				cout << endl;

				cout << "Número de Telefone: ";
				cin >> numTelf;
				cin.ignore();
				cout << endl;

				cout << "Email: ";
				getline(cin, email);
				cout << endl;

				cout << "Número máximo de empregados de Limpeza: ";
				cin >> maxLimpeza;
				cin.ignore();

				cout << "Número máximo de empregados de Canalização: ";
				cin >> maxCanalizacao;
				cin.ignore();

				cout << "Número máximo de empregados de Pintura: ";
				cin >> maxPintura;
				cin.ignore();

				cout << endl
						<< "Atenção! Inicialmente este condomínio vai estar vazio, é necessário inserir os dados manualmente."
						<< endl << endl;

				stringstream novoCond, novoHabs, novoClientes, novoEmpregados,
						novoServicos, novoCondominio;

				novoCond << "condominios/" << cond.size() + 1 << "-" << nome;

				mkdir(novoCond.str().c_str(),
				S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

				novoHabs << novoCond.str() << "/habitacoes.txt";
				novoClientes << novoCond.str() << "/clientes.txt";
				novoEmpregados << novoCond.str() << "/empregados.txt";
				novoServicos << novoCond.str() << "/servicos.txt";
				novoCondominio << novoCond.str() << "/condominio.txt";

				ofstream fileNovoHabs(novoHabs.str());
				ofstream fileNovoClientes(novoClientes.str());
				ofstream fileNovoEmpregados(novoEmpregados.str());
				ofstream fileNovoServicos(novoServicos.str());
				ofstream fileNovoCondominio(novoCondominio.str());

				fileNovoCondominio << nome << endl << nif << endl << numTelf
						<< endl << email << endl << maxLimpeza << endl
						<< maxCanalizacao << endl << maxPintura;
			}

			else if (atoi(op.c_str()) == cond.size() + 2) { // remover um condominio
				while (1) {
					vector<string>::iterator itb = cond.begin();
					int i = 1, op2;
					string confirmation;

					cout << endl << "*** Remover um condomínio ***" << endl
							<< endl;

					cout << "Qual o condomínio que quer remover? " << endl;

					// lista os condominios existentes
					for (; itb != cond.end(); itb++) {
						cout << i << ". " << (*itb) << endl;
						i++;
					}

					cout << i++ << ". Sair" << endl;

					cout << endl << "> ";
					cin >> op2;
					cin.ignore();

					//  opção válida
					if (op2 <= cond.size()) {
						cout << endl
								<< "Tem a certeza que pretende remover o condomínio "
								<< cond[op2 - 1] << "? (Y/N)" << endl;
						cin >> confirmation;
						cin.ignore();

						if (confirmation == "y" || confirmation == "Y") {
							// TODO:remover condominio
						} else
							continue;
					}

					// sair
					else if (op2 == cond.size() + 1)
						break;

					// opção não válida
					else {
						cout << endl << "Escolha uma opção válida!" << endl;
						continue;
					}
				}
			}

			else if (atoi(op.c_str()) == cond.size() + 3)
				return 0;
		}

		else
			cout << "Por favor escolha uma opcao valida!" << endl << endl;
	}

	return 0;
}
