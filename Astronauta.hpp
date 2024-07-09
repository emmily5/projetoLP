#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
public:
    std::string Nome;
    std::string Cpf;
    int Idade;
    bool Disponivel;  // true se disponível, false se indisponível
    bool Estado;      // true se vivo, false se morto

    Astronauta(std::string nome, std::string cpf, int idade);

    // Getters para uso na interface textual
    std::string getNome() const { return Nome; }
    std::string getCpf() const { return Cpf; }
    int getIdade() const { return Idade; }
    std::string getDisponibilidade() const { return Disponivel ? "Disponível" : "Indisponível"; }
    std::string getEstado() const { return Estado ? "Vivo" : "Morto"; }

    void setDisponibilidade(bool d);
    void setEstado(bool e);
};

#endif // ASTRONAUTA_H
