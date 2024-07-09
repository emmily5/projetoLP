#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Astronauta.hpp"
#include "Voo.hpp"

class Sistema {
private:
    std::vector<Astronauta> Astronautas;
    std::vector<Voo> Voos;
    std::vector<Astronauta> AstronautasMortos;

public:
    void cadastrarAstronauta(const std::string& nome, const std::string& cpf, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronautaEmVoo(const std::string& cpf, int codigo);
    void removerAstronautaDeVoo(const std::string& cpf, int codigo);
    void lancarVoo(int codigo);
    void explodirVoo(int codigo);
    void finalizarVoo(int codigo, bool sucesso);
    void listarVoos();
    void listarAstronautasMortos();
};

#endif // SISTEMA_H
