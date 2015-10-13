#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Apartamento.h"
#include "Vivenda.h"

void testa_mensalidade() {
	Apartamento a1("Rua da circunvalacao", 100, 1, 1);
	Vivenda v1("Rua da constituicao", 100, 200, true);

	ASSERT_EQUAL_DELTA(72, a1.mensalidade(), 0.001); // 50 + 0.2 * areaHabitacao + piso
	ASSERT_EQUAL_DELTA(100, v1.mensalidade(), 0.001); // 50 + 0.2 * areaHabitacao + 0.1 * areaExterior + 10 * temPiscina
}

void runSuite() {
cute::suite s;
s.push_back(CUTE(testa_mensalidade));
cute::ide_listener lis;
cute::makeRunner(lis)(s,
		"Testes unitarios Condominio");
}

int main() {
runSuite();
return 0;
}
