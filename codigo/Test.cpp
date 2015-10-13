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
	Habitacao *v2 = new Vivenda ("Rua da boavista", 100, 200, false);

	vector<Habitacao *> habitacoes;
	Condominio *c1 = new Condominio(habitacoes);

	c1->adicionaHabitacao(a1);
	c1->adicionaHabitacao(v1);

	// Testa pagarMensalidade de um apartamento
	ASSERT_EQUAL_DELTA(72, a1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(72, c1->pagarMensalidade(a1), 0.001);

	// Testa pagarMensalidade de uma vivenda
	ASSERT_EQUAL_DELTA(100, v1->mensalidade(), 0.001);
	ASSERT_EQUAL_DELTA(100, c1->pagarMensalidade(v1), 0.001);

	// Testa pagarMensalidade de uma Habitação que não existe
	ASSERT_EQUAL(-1, c1->pagarMensalidade(v2));
}

void runSuite() {
	cute::suite s;
	s.push_back(CUTE(testa_mensalidade));
	s.push_back(CUTE(testa_pagarMensalidade));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Testes unitarios Condominio");
}

int main() {
	runSuite();
	return 0;
}
