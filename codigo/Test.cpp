#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Apartamento.h"
#include "Vivenda.h"
#include "Condominio.h"

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

	//cout << "Morada do cliente: " << c1->getClientes()[0]->getHabitacoes()[0]->getMorada() << endl;

	// Testa pagarMensalidade de um apartamento
	ASSERT_EQUAL_DELTA(72, a1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(72, c1->pagarMensalidade(a1), 0.001);

	// Testa pagarMensalidade de uma vivenda
	ASSERT_EQUAL_DELTA(100, v1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(100, c1->pagarMensalidade(v1), 0.001);

	// Testa pagarMensalidade de uma Habitação que não existe
	ASSERT_EQUAL(-1, c1->pagarMensalidade(v2));
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

	// Testa se consegue adicionar novos empregados
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e1));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e4));

	// Testa se consegue adicionar novos empregados com nomes iguais
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e5));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e2));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e6));
	ASSERT_EQUAL(0, s1->adicionaEmpregado(e3));

	// Testa se adiciona um empregado que já existe
	ASSERT_EQUAL(-1, s1->adicionaEmpregado(e1));

	// Testa o número de serviços disponíveis
	ASSERT_EQUAL(6, s1->getServicosDisponiveis());

	// Testa se é possível adicionar mais empregados que o limite definido pelo utilizador
	ASSERT_EQUAL(-2, s1->adicionaEmpregado(e7)); // para o tipo Limpeza
	ASSERT_EQUAL(-2, s1->adicionaEmpregado(e8)); // para o tipo Canalizacao
	ASSERT_EQUAL(-2, s1->adicionaEmpregado(e9)); // para o tipo Pintura

	// Testa um serviço que não é válido
	ASSERT_EQUAL(-3, s1->adicionaEmpregado(e10));
}

void testa_requesitaServico() {
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
	ASSERT_EQUAL(0, c1->requesitaServico("Limpeza"));
	ASSERT_EQUAL(0, c1->requesitaServico("Canalizacao"));
	ASSERT_EQUAL(0, c1->requesitaServico("Pintura"));

	// Verifica se é possível requesitar um serviço que não está disponível
	ASSERT_EQUAL(-2, c1->requesitaServico("Limpeza"));
	ASSERT_EQUAL(-2, c1->requesitaServico("Canalizacao"));
	ASSERT_EQUAL(-2, c1->requesitaServico("Pintura"));

	// Verifica se é possível requesitar um serviço inexistente
	ASSERT_EQUAL(-1, c1->requesitaServico("Cozinha"));
}

void testa_fimDoServico() {
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

	// REQUISITA SERVIÇOS
	ASSERT_EQUAL(0, c1->requesitaServico("Limpeza"));
	ASSERT_EQUAL(0, c1->requesitaServico("Canalizacao"));
	ASSERT_EQUAL(0, c1->requesitaServico("Pintura"));

	// Verifica se os empregados voltam a ficar livres
	ASSERT_EQUAL(0, c1->fimDoServico(e1));
	ASSERT_EQUAL(0, c1->fimDoServico(e2));
	ASSERT_EQUAL(0, c1->fimDoServico(e3));
	ASSERT_EQUAL(0, c1->fimDoServico(e4));
	ASSERT_EQUAL(0, c1->fimDoServico(e5));
	ASSERT_EQUAL(0, c1->fimDoServico(e6));

	// Verifica se consegue colocar livre um empregado que já está livre
	ASSERT_EQUAL(-1, c1->fimDoServico(e2));
}

void runSuite() {
	cute::suite s;
	s.push_back(CUTE(testa_mensalidade));
	s.push_back(CUTE(testa_pagarMensalidade));
	s.push_back(CUTE(testa_adicionaEmpregado));
	s.push_back(CUTE(testa_requesitaServico));
	s.push_back(CUTE(testa_fimDoServico));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Testes unitarios Condominio");
}

int main() {
	runSuite();
	return 0;
}
