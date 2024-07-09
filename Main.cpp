#include <iostream>
#include "Sistema.hpp"

void exibirMenu() {
    std::cout << "\n\n===== Sistema de Gestão de Voos Espaciais =====\n\n";
    std::cout << "1. Cadastrar Astronauta\n";
    std::cout << "2. Cadastrar Voo\n";
    std::cout << "3. Adicionar Astronauta a um Voo\n";
    std::cout << "4. Remover Astronauta de um Voo\n";
    std::cout << "5. Lançar Voo\n";
    std::cout << "6. Explodir Voo\n";
    std::cout << "7. Finalizar Voo\n";
    std::cout << "8. Listar Voos\n";
    std::cout << "9. Listar Astronautas Mortos\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

void cadastrarAstronauta(Sistema& sistema) {
    std::string nome, cpf;
    int idade;

    std::cout << "Digite o nome do astronauta: ";
    std::cin >> nome;
    std::cout << "Digite o CPF do astronauta: ";
    std::cin >> cpf;
    std::cout << "Digite a idade do astronauta: ";
    std::cin >> idade;

    sistema.cadastrarAstronauta(nome, cpf, idade);
   
}

void cadastrarVoo(Sistema& sistema) {
    int codigo;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    sistema.cadastrarVoo(codigo);
   
}

void adicionarAstronautaEmVoo(Sistema& sistema) {
    std::string cpf;
    int codigo;
    std::cout << "Digite o CPF do astronauta: ";
    std::cin >> cpf;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    sistema.adicionarAstronautaEmVoo(cpf, codigo);
}

void removerAstronautaDeVoo(Sistema& sistema) {
    std::string cpf;
    int codigo;
    std::cout << "Digite o CPF do astronauta: ";
    std::cin >> cpf;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    sistema.removerAstronautaDeVoo(cpf, codigo);
}

void lancarVoo(Sistema& sistema) {
    int codigo;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    sistema.lancarVoo(codigo);
}

void explodirVoo(Sistema& sistema) {
    int codigo;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    sistema.explodirVoo(codigo);
}

void finalizarVoo(Sistema& sistema) {
    int codigo;
    char sucesso;
    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;
    std::cout << "Foi finalizado com sucesso? (s/n): ";
    std::cin >> sucesso;

    sistema.finalizarVoo(codigo, (sucesso == 's' || sucesso == 'S'));
}

void listarVoos(Sistema& sistema) {
    std::cout << "===== Lista de Voos =====\n";
    sistema.listarVoos();
}

void listarAstronautasMortos(Sistema& sistema) {
    std::cout << "===== Lista de Astronautas Mortos =====\n";
    sistema.listarAstronautasMortos();
}

int main() {
    Sistema sistema;
    int escolha;
    do {
        
        exibirMenu();
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                cadastrarAstronauta(sistema);
                break;
            case 2:
                cadastrarVoo(sistema);
                break;
            case 3:
                adicionarAstronautaEmVoo(sistema);
                break;
            case 4:
                removerAstronautaDeVoo(sistema);
                break;
            case 5:
                lancarVoo(sistema);
                break;
            case 6:
                explodirVoo(sistema);
                break;
            case 7:
                finalizarVoo(sistema);
                break;
            case 8:
                listarVoos(sistema);
                break;
            case 9:
                listarAstronautasMortos(sistema);
                break;
            case 0:
                std::cout << "Encerrando o programa...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (escolha != 0);

    return 0;
}
