#include "Voo.hpp"
#include <algorithm>

Voo::Voo(int codigo) : Codigo(codigo), Status("planejado") {}

void Voo::adicionarAstronauta(Astronauta* a) {
    Passageiros.push_back(a);
}

void Voo::removerAstronauta(const std::string& cpf) {
    Passageiros.erase(std::remove_if(Passageiros.begin(), Passageiros.end(),
        [&cpf](Astronauta* a) { return a->Cpf == cpf; }), Passageiros.end());
}

bool Voo::verificarDisponibilidade() {
    return Status == "planejado" && !Passageiros.empty();
}
