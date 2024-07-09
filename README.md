# Primeiro projeto da disciplina de Linguagem de Programação 1 (IMD0030), implementado em C++.

## Para executar o programa
Em seu terminal, execute os seguintes comandos:
```
g++ -c Astronauta.cpp -o Astronauta.o

```
g++ -c Voo.cpp -o Voo.o

```
g++ -c Sistema.cpp -o Sistema.o

```
g++ main.cpp Astronauta.o Voo.o Sistema.o -o final.exe

```
Após compilar, execute o seguinte comando e o programa será iniciado:

```
./final.exe

# Sobre o projeto
Este projeto envolve a criação de um sistema de gestão de astronautas e voos espaciais. O sistema permite o cadastro de astronautas, incluindo CPF, nome e idade, e o cadastro de voos espaciais, com um código de voo e uma lista de passageiros (astronautas). Funcionalidades principais incluem: cadastrar astronautas e voos, adicionar ou remover astronautas de voos enquanto estão em planejamento, lançar voos, marcar astronautas como indisponíveis durante o voo, explodir voos (resultando na morte dos astronautas), finalizar voos (marcando astronautas como disponíveis novamente) e listar todos os voos (planejados, em curso e finalizados) com seus astronautas. O sistema também lista todos os astronautas mortos, incluindo CPF, nome e voos que participaram.