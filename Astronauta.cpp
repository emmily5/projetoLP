#include "Astronauta.hpp"

Astronauta::Astronauta(std::string nome, std::string cpf, int idade) {
    Nome = nome;
    Cpf = cpf;
    Idade = idade;
    Disponivel = true;
    Estado = true;
}

void Astronauta::setDisponibilidade(bool d) {
    Disponivel = d;
}

void Astronauta::setEstado(bool e) {
    Estado = e;
}
