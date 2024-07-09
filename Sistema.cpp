#include "Sistema.hpp"
#include <iostream>
#include <algorithm>

void Sistema::cadastrarAstronauta(const std::string& nome, const std::string& cpf, int idade) {
    for (const auto& a : Astronautas) {
        if (a.Cpf == cpf) {
            std::cerr << "\nAstronauta com CPF " << cpf << " já cadastrado.\n\n";
            return;
        }
    }
    Astronautas.emplace_back(nome, cpf, idade);
    std::cout << "\nAstronauta cadastrado com sucesso!\n\n";

}

void Sistema::cadastrarVoo(int codigo) {
    for (const auto& v : Voos) {
        if (v.Codigo == codigo) {
            std::cerr << "\nVoo com código " << codigo << " já cadastrado.\n\n";
            return;
        }
    }
    Voos.emplace_back(codigo);
    std::cout << "\nVoo cadastrado com sucesso!\n\n";
}

void Sistema::adicionarAstronautaEmVoo(const std::string& cpf, int codigo) {
    auto astronautaIt = std::find_if(Astronautas.begin(), Astronautas.end(),
        [&cpf](const Astronauta& a) { return a.Cpf == cpf; });

    if (astronautaIt == Astronautas.end()) {
        std::cerr << "\nAstronauta com CPF " << cpf << " não encontrado.\n\n";
        return;
    }

    auto vooIt = std::find_if(Voos.begin(), Voos.end(),
        [codigo](const Voo& v) { return v.Codigo == codigo; });

    if (vooIt == Voos.end()) {
        std::cerr << "\nVoo com código " << codigo << " não encontrado.\n\n";
        return;
    }

    Astronauta* a = &(*astronautaIt);
    Voo& v = *vooIt;
    if (a->Disponivel && v.Status == "planejado") {
        v.adicionarAstronauta(a);
        a->setDisponibilidade(false);
    } else {
        std::cerr << "\nNão é possível adicionar astronauta ao voo.\n\n";
    }
}

void Sistema::removerAstronautaDeVoo(const std::string& cpf, int codigo) {
    auto astronautaIt = std::find_if(Astronautas.begin(), Astronautas.end(),
        [&cpf](const Astronauta& a) { return a.Cpf == cpf; });

    if (astronautaIt == Astronautas.end()) {
        std::cerr << "\nAstronauta com CPF " << cpf << " não encontrado.\n\n";
        return;
    }

    auto vooIt = std::find_if(Voos.begin(), Voos.end(),
        [codigo](const Voo& v) { return v.Codigo == codigo; });

    if (vooIt == Voos.end()) {
        std::cerr << "\nVoo com código " << codigo << " não encontrado.\n\n";
        return;
    }

    Astronauta* a = &(*astronautaIt);
    Voo& v = *vooIt;
    if (v.Status == "planejado") {
        v.removerAstronauta(cpf);
        a->setDisponibilidade(true);
    } else {
        std::cerr << "\nNão é possível remover astronauta do voo.\n\n";
    }

    std::cout << "Astronauta removido!\n\n";
}

void Sistema::lancarVoo(int codigo) {
    auto vooIt = std::find_if(Voos.begin(), Voos.end(),
        [codigo](const Voo& v) { return v.Codigo == codigo; });

    if (vooIt == Voos.end()) {
        std::cerr << "\nVoo com código " << codigo << " não encontrado.\n\n";
        return;
    }

    Voo& v = *vooIt;
    if (v.verificarDisponibilidade()) {
        v.Status = "em curso";
    } else {
        std::cerr << "Não é possível lançar o voo.\n\n";
    }
}

void Sistema::explodirVoo(int codigo) {
    auto vooIt = std::find_if(Voos.begin(), Voos.end(),
        [codigo](const Voo& v) { return v.Codigo == codigo; });

    if (vooIt == Voos.end()) {
        std::cerr << "Voo com código " << codigo << " não encontrado.\n\n";
        return;
    }

    Voo& v = *vooIt;
    if (v.Status == "em curso") {
        v.Status = "explodido";
        for (auto a : v.Passageiros) {
            AstronautasMortos.push_back(*a);
            a->setEstado(false);
        }
        v.Passageiros.clear();
    } else {
        std::cerr << "O voo não está em curso.\n";
    }
}

void Sistema::finalizarVoo(int codigo, bool sucesso) {
    auto vooIt = std::find_if(Voos.begin(), Voos.end(),
        [codigo](const Voo& v) { return v.Codigo == codigo; });

    if (vooIt == Voos.end()) {
        std::cerr << "Voo com código " << codigo << " não encontrado.\n";
        return;
    }

    Voo& v = *vooIt;
    if (v.Status == "em curso") {
        v.Status = sucesso ? "finalizado com sucesso" : "finalizado sem sucesso";
        for (auto a : v.Passageiros) {
            a->setDisponibilidade(true);
        }
    } else {
        std::cerr << "O voo não está em curso.\n";
    }
}

void Sistema::listarVoos() {
    for (const auto& v : Voos) {
        std::cout << "Voo Código: " << v.Codigo << ", Status: " << v.Status << "\n";
        for (const auto& a : v.Passageiros) {
            std::cout << "  Astronauta: " << a->Cpf << ", " << a->Nome << "\n";
        }
    }
}

void Sistema::listarAstronautasMortos() {
    for (const auto& a : AstronautasMortos) {
        std::cout << "Astronauta Morto - CPF: " << a.Cpf << ", Nome: " << a.Nome << "\n";
    }
}
