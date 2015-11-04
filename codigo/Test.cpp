#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Apartamento.h"
#include "Vivenda.h"
#include "Condominio.h"
#include "menu.h"

void testa_mensalidade() {
	Apartamento a1("Rua da circunvalacao", 100, 1, 1);
	Vivenda v1("Rua da constituicao", 100, 200, true);

	// Testa mensalidade de um apartamento
	ASSERT_EQUAL_DELTA(72, a1.mensalidade(), 0.001); // 50 + 0.2 * areaHabitacao + piso

	// Testa mensalidade de uma vivenda
	ASSERT_EQUAL_DELTA(100, v1.mensalidade(), 0.001); // 50 + 0.2 * areaHabitacao + 0.1 * areaExterior + 10 * temPiscina
}

void testa_pagarMensalidade() {
	Habitacao *a1 = new Apartamento("Rua da circunvalacao", 100, 1, 1);
	Habitacao *v1 = new Vivenda("Rua da constituicao", 100, 200, true);
	Habitacao *v2 = new Vivenda("Rua da boavista", 100, 200, false);

	vector<Habitacao *> habitacoes;

	Cliente *cliente1 = new Cliente("Maria", 12345678, habitacoes);

	cliente1->adicionaHabitacao(a1);
	cliente1->adicionaHabitacao(v1);

	string nome = "BestCondominio";
	int nif = 122312543;
	vector<Cliente *> clientes;
	vector<Empregado *> empregados;
	Servico * servico = new Servico(empregados, 2, 2, 2);
	Condominio *c1 = new Condominio(nome, nif, clientes, servico);

	c1->adicionaCliente(cliente1);

	// Testa pagarMensalidade de um apartamento
	ASSERT_EQUAL_DELTA(72, a1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(72, c1->pagarMensalidade(a1), 0.001);

	// Testa pagarMensalidade de uma vivenda
	ASSERT_EQUAL_DELTA(100, v1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(100, c1->pagarMensalidade(v1), 0.001);

	// Testa pagarMensalidade de uma Habitação que não existe
	ASSERT_THROWS(c1->pagarMensalidade(v2), HabitacaoInexistente);
	try {
		c1->pagarMensalidade(v2);
	}
	catch(HabitacaoInexistente &e) {
		cout << "-> Apanhou exceção HabitacaoInexistente. A habitação com morada \"" << e.getMorada() << "\" não existe neste condomínio." << endl;
	}
}

void testa_adicionaEmpregado() {
	vector<Empregado *> empregados;

	Empregado *e1 = new Limpeza("Sara", 12345678, "Limpeza", true);
	Empregado *e2 = new Canalizacao("Luis", 87654321, "Canalizacao", true);
	Empregado *e3 = new Pintura("Jose", 109876543, "Pintura", true);
	Empregado *e4 = new Limpeza("Manuel", 11223344, "Limpeza", true);
	Empregado *e5 = new Canalizacao("Luis", 55667788, "Canalizacao", true);
	Empregado *e6 = new Pintura("Jose", 90908080, "Pintura", true);
	Empregado *e7 = new Limpeza("Rui", 11113344, "Limpeza", true);
	Empregado *e8 = new Canalizacao("Maria", 55557788, "Canalizacao", true);
	Empregado *e9 = new Pintura("Alberto", 90008000, "Pintura", true);
	Empregado *e10 = new Pintura("Ricardo", 98762903, "Cozinha", true);

	Servico *s1 = new Servico(empregados, 2, 2, 2);

	// Verifica se é possível incrementar o número de empregados disponíveis quando a empresa não tem empregados
	ASSERT_THROWS(s1->incServicosDisponiveis(), EmpresaSemEmpregados);
	try {
		s1->incServicosDisponiveis();
	}
	catch(EmpresaSemEmpregados &e) {
		cout << "-> Apanhou exceção EmpresaSemEmpregados. A empresa ainda não tem empregados por isso não é possível incrementar o número de serviços disponíveis." << endl;
	}

	// Testa se consegue adicionar novos empregados
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e1));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e4));

	// Testa se consegue adicionar novos empregados com nomes iguais
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e5));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e2));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e6));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e3));

	// Testa se adiciona um empregado que já existe
	ASSERT_THROWS(s1->adicionaEmpregado(e1), EmpregadoExistente);
	try {
		s1->adicionaEmpregado(e1);
	}
	catch(EmpregadoExistente &e) {
		cout << "-> Apanhou exceção EmpregadoExistente. Empregado já existe e tem bi: " << e.getBI() << endl;
	}

	// Testa o número de serviços disponíveis
	ASSERT_EQUAL(6, s1->getServicosDisponiveis());

	// Testa se é possível adicionar mais empregados que o limite definido pelo utilizador
	// para o tipo Limpeza
	ASSERT_THROWS(s1->adicionaEmpregado(e7), LimiteMaximoEmpregados);
	try {
		s1->adicionaEmpregado(e7);
	}
	catch(LimiteMaximoEmpregados &e) {
		cout << "-> Apanhou exceção LimiteMaximoEmpregados. Número máximo de empregados do tipo " << e.getTipo() << " foi atingido." << endl;
	}

	// para o tipo Canalizacao
	ASSERT_THROWS(s1->adicionaEmpregado(e8), LimiteMaximoEmpregados);
	try {
		s1->adicionaEmpregado(e8);
	}
	catch(LimiteMaximoEmpregados &e) {
		cout << "-> Apanhou exceção LimiteMaximoEmpregados. Número máximo de empregados do tipo " << e.getTipo() << " foi atingido." << endl;
	}

	// para o tipo Pintura
	ASSERT_THROWS(s1->adicionaEmpregado(e9), LimiteMaximoEmpregados);
	try {
		s1->adicionaEmpregado(e9);
	}
	catch(LimiteMaximoEmpregados &e) {
		cout << "-> Apanhou exceção LimiteMaximoEmpregados. Número máximo de empregados do tipo " << e.getTipo() << " foi atingido." << endl;
	}

	// Testa um serviço que não é válido
	ASSERT_THROWS(s1->adicionaEmpregado(e10), ServicoInvalido);
	try {
		s1->adicionaEmpregado(e10);
	}
	catch(ServicoInvalido &e) {
		cout << "-> Apanhou exceção ServicoInvalido. " << e.getTipo() << " não existe nesta empresa de serviços." << endl;
	}
}

void testa_requisitaServico() {
	vector<Empregado *> empregados;

	Empregado *e1 = new Limpeza("Sara", 12345678, "Limpeza", true);
	Empregado *e2 = new Canalizacao("Luis", 87654321, "Canalizacao", true);
	Empregado *e3 = new Pintura("Jose", 109876543, "Pintura", true);
	Empregado *e4 = new Limpeza("Manuel", 11223344, "Limpeza", false);
	Empregado *e5 = new Canalizacao("Luis", 55667788, "Canalizacao", false);
	Empregado *e6 = new Pintura("Jose", 90908080, "Pintura", false);

	Servico s1(empregados, 2, 2, 2);

	s1.adicionaEmpregado(e1);
	s1.adicionaEmpregado(e2);
	s1.adicionaEmpregado(e3);
	s1.adicionaEmpregado(e4);
	s1.adicionaEmpregado(e5);
	s1.adicionaEmpregado(e6);

	vector<Habitacao *> habitacoes;

	Cliente *cliente1 = new Cliente("Maria", 12345678, habitacoes);

	string nome = "BestCondominio";
	int nif = 122312543;
	vector<Cliente *> clientes;

	Condominio *c1 = new Condominio(nome, nif, clientes, &s1);

	// Verifica se é possível requesitar um serviço de cada tipo
	ASSERT_EQUAL(0, c1->requisitaServico("Limpeza"));
	ASSERT_EQUAL(0, c1->requisitaServico("Canalizacao"));
	ASSERT_EQUAL(0, c1->requisitaServico("Pintura"));

	// Verifica se é possível requesitar um serviço que não está disponível
	// Limpeza
	ASSERT_THROWS(c1->requisitaServico("Limpeza"), EmpregadosIndisponiveis);
	try {
		c1->requisitaServico("Limpeza");
	}
	catch(EmpregadosIndisponiveis &e) {
		cout << "-> Apanhou exceção EmpregadosIndisponiveis. Empregados de " << e.getTipo() << " não estão disponíveis de momento." << endl;
	}

	// Canalização
	ASSERT_THROWS(c1->requisitaServico("Canalizacao"), EmpregadosIndisponiveis);
	try {
		c1->requisitaServico("Canalizacao");
	}
	catch(EmpregadosIndisponiveis &e) {
		cout << "-> Apanhou exceção EmpregadosIndisponiveis. Empregados de " << e.getTipo() << " não estão disponíveis de momento." << endl;
	}

	//Pintura
	ASSERT_THROWS(c1->requisitaServico("Pintura"), EmpregadosIndisponiveis);
	try {
		c1->requisitaServico("Pintura");
	}
	catch(EmpregadosIndisponiveis &e) {
		cout << "-> Apanhou exceção EmpregadosIndisponiveis. Empregados de " << e.getTipo() << " não estão disponíveis de momento." << endl;
	}

	// Verifica se é possível requesitar um serviço inexistente
	ASSERT_THROWS(c1->requisitaServico("Cozinha"), ServicoInvalido);
	try {
		c1->requisitaServico("Cozinha");
	}
	catch(ServicoInvalido &e) {
		cout << "-> Apanhou exceção ServicoInvalido. " << e.getTipo() << " não existe nesta empresa de serviços." << endl;
	}

}

void testa_fimDoServico() {
	vector<Empregado *> empregados;

	Empregado *e1 = new Limpeza("Sara", 12345678, "Limpeza", true);
	Empregado *e2 = new Canalizacao("Luis", 87654321, "Canalizacao", true);
	Empregado *e3 = new Pintura("Jose", 109876543, "Pintura", true);
	Empregado *e4 = new Limpeza("Manuel", 11223344, "Limpeza", false);
	Empregado *e5 = new Canalizacao("Luis", 55667788, "Canalizacao", false);
	Empregado *e6 = new Pintura("Jose", 90908080, "Pintura", false);
	Empregado *e7 = new Pintura("Maria", 10927363, "Pintura", false);

	Servico s1(empregados, 2, 2, 2);

	s1.adicionaEmpregado(e1);
	s1.adicionaEmpregado(e2);
	s1.adicionaEmpregado(e3);
	s1.adicionaEmpregado(e4);
	s1.adicionaEmpregado(e5);
	s1.adicionaEmpregado(e6);

	vector<Habitacao *> habitacoes;

	Cliente *cliente1 = new Cliente("Maria", 12345678, habitacoes);

	string nome = "BestCondominio";
	int nif = 122312543;
	vector<Cliente *> clientes;

	Condominio *c1 = new Condominio(nome, nif, clientes, &s1);

	// REQUISITA SERVIÇOS
	ASSERT_EQUAL(0, c1->requisitaServico("Limpeza"));
	ASSERT_EQUAL(0, c1->requisitaServico("Canalizacao"));
	ASSERT_EQUAL(0, c1->requisitaServico("Pintura"));

	// Verifica se os empregados voltam a ficar livres
	ASSERT_EQUAL(0, c1->fimDoServico(e1));
	ASSERT_EQUAL(0, c1->fimDoServico(e2));
	ASSERT_EQUAL(0, c1->fimDoServico(e3));
	ASSERT_EQUAL(0, c1->fimDoServico(e4));
	ASSERT_EQUAL(0, c1->fimDoServico(e5));
	ASSERT_EQUAL(0, c1->fimDoServico(e6));

	// Verifica se consegue colocar um empregado que não está nos empregados da empresa de serviços
	ASSERT_THROWS(c1->fimDoServico(e7), EmpregadoInexistente);
	try {
		c1->fimDoServico(e7);
	}
	catch(EmpregadoInexistente &e) {
		cout << "-> Apanhou exceção EmpregadoInexistente. Empregado com BI: " << e.getBI() << " não existe nesta empresa de serviços." << endl;
	}

	// Verifica se consegue colocar livre um empregado que já está livre
	ASSERT_THROWS(c1->fimDoServico(e2), EmpregadoLivre);
	try {
		c1->fimDoServico(e2);
	}
	catch(EmpregadoLivre &e) {
		cout << "-> Apanhou exceção EmpregadoLivre. Empregado com BI: " << e.getBI() << " está livre." << endl;
	}
}

void testa_adicionaCliente() {
	vector<Habitacao *> hab;
	Cliente *c1 = new Cliente("Maria", 12345678, hab);
	Cliente *c2 = new Cliente("Manuela", 12345678, hab);
	Cliente *c3 = new Cliente("Maria", 98765432, hab);

	vector<Cliente *> clientes;
	vector<Empregado *> empregados;
	Servico s1(empregados, 2, 2, 2);
	Condominio *cond = new Condominio("Condo", 213453423, clientes, &s1);

	// Verifica se é possível adicionar um cliente
	ASSERT_EQUAL(0, cond->adicionaCliente(c1));

	// Verifica se é possível adicionar um cliente com o mesmo nome
	ASSERT_EQUAL(0, cond->adicionaCliente(c3));

	// Verifica se é possível adicionar um cliente que já existe
	ASSERT_THROWS(cond->adicionaCliente(c2), ClienteExistente);
	try {
		cond->adicionaCliente(c2);
	}
	catch(ClienteExistente &e) {
		cout << "-> Apanhou exceção ClienteExistente. O cliente  com BI " << e.getBI() << " já existe no condomínio." << endl;
	}
}

void testa_removeEmpregado() {
	vector<Empregado *> empregados;

	Servico *s1 = new Servico(empregados, 2, 2, 2);

	Empregado *e0 = new Limpeza("Joao", 99878901, "Limpeza", true);
	Empregado *e1 = new Limpeza("Sara", 12345678, "Limpeza", true);
	Empregado *e2 = new Canalizacao("Luis", 87654321, "Canalizacao", false);
	Empregado *e3 = new Pintura("Jose", 109876543, "Pintura", true);
	Empregado *e4 = new Limpeza("Manuel", 11223344, "Limpeza", true);
	Empregado *e5 = new Canalizacao("Luis", 55667788, "Canalizacao", true);

	// Verifica se é possível decrementar o número de serviços disponíveis quando a empresa ainda não tem empregados.
	ASSERT_THROWS(s1->decServicosDisponiveis(), EmpresaSemEmpregados);
	try {
		s1->decServicosDisponiveis();
	}
	catch(EmpresaSemEmpregados &e) {
		cout << "-> Apanhou exceção EmpresaSemEmpregados. A empresa ainda não tem empregados por isso não é possível decrementar o número de serviços disponíveis." << endl;
	}

	// Verifica se é possível remover um empregado de uma empresa de serviços sem empregados
	ASSERT_THROWS(s1->removeEmpregado(e0), EmpresaSemEmpregados);
	try {
		s1->removeEmpregado(e0);
	}
	catch(EmpresaSemEmpregados &e) {
		cout << "-> Apanhou exceção EmpresaSemEmpregados. A empresa ainda não tem empregados." << endl;
	}

	s1->adicionaEmpregado(e1);
	s1->adicionaEmpregado(e2);
	s1->adicionaEmpregado(e3);
	s1->adicionaEmpregado(e4);

	// Verifica se é possível remover um empregado que está ocupado.
	ASSERT_THROWS(s1->removeEmpregado(e2), EmpregadoOcupado);
	try {
		s1->removeEmpregado(e2);
	}
	catch(EmpregadoOcupado &e) {
		cout << "-> Apanhou exceção EmpregadoOcupado. O empregado com bi " << e.getBI() << " está ocupado." << endl;
	}

	// Verifica se é possível remover um empregado que não existe na empresa de serviços
	ASSERT_THROWS(s1->removeEmpregado(e5), EmpregadoInexistente);
	try {
		s1->removeEmpregado(e5);
	}
	catch(EmpregadoInexistente &e) {
		cout << "-> Apanhou exceção EmpregadoInexistente. O empregado com bi " << e.getBI() << " não existe nesta empresa de serviços." << endl;
	}
}

void testa_adicionaHabitacao() {
	Habitacao *a1 = new Apartamento("Rua da circunvalacao", 100, 1, 1);

	vector<Habitacao *> habitacoes;

	Cliente *cliente1 = new Cliente("Maria", 12345678, habitacoes);
	Cliente *cliente2 = new Cliente("Manuel", 98765432, habitacoes);

	// Verifica se é possível adicionar uma habitação
	cliente1->adicionaHabitacao(a1);
	cliente2->adicionaHabitacao(a1);

	// Verifica se é possível adicionar uma habitação que já existe
	ASSERT_THROWS(cliente1->adicionaHabitacao(a1), HabitacaoExistente);
	try {
		cliente1->adicionaHabitacao(a1);
	}
	catch(HabitacaoExistente &e) {
		cout << "-> Apanhou exceção HabitacaoExistente. A habitação com morada \"" << e.getMorada() << "\" já existe neste cliente." << endl;
	}
}

void runSuite() {
	cute::suite s;
	s.push_back(CUTE(testa_mensalidade));
	s.push_back(CUTE(testa_pagarMensalidade));
	s.push_back(CUTE(testa_adicionaEmpregado));
	s.push_back(CUTE(testa_requisitaServico));
	s.push_back(CUTE(testa_fimDoServico));
	s.push_back(CUTE(testa_adicionaCliente));
	s.push_back(CUTE(testa_removeEmpregado));
	s.push_back(CUTE(testa_adicionaHabitacao));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Testes unitarios Condominio");
}

int main() {
	runSuite();
    menu();
	return 0;
}
