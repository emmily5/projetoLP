#ifndef VOO_H
#define VOO_H

#include <vector>
#include <string>
#include "Astronauta.hpp"

class Voo {
public:
    int Codigo;
    std::vector<Astronauta*> Passageiros;  // Usamos ponteiros para evitar a cópia dos objetos
    std::string Status;  // "planejado", "em curso", "finalizado com sucesso", "explodido"

    Voo(int codigo);

    // Getters para uso na interface textual
    int getCodigo() const { return Codigo; }
    std::string getStatus() const { return Status; }

    void adicionarAstronauta(Astronauta* a);
    void removerAstronauta(const std::string& cpf);
    bool verificarDisponibilidade();
};

#endif // VOO_H
