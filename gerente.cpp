#include <iostream>
#include <map>
#include "gerente.hpp"
#include <vector>
#include <fstream>
#include "funcoesCompartilhadas.hpp"

using namespace std;

extern map<string, float> sanduiche;
extern map<string, float> suco;

// função para inserir novo sanduiche
void cadastrarSanduiche(string saborSanduiche, float valor)
{
  sanduiche[saborSanduiche] = valor;

  cout << "\t\n----Sanduiche cadastrado com sucesso!----";
}

// função para inserir novo suco
void cadastrarSuco(string saborSuco, float valor)
{
  suco[saborSuco] = valor;

  cout << "\t\n----Suco cadastrado com sucesso!----";
}

// função para alterar o valor do sanduiche
void alterarSanduiche(string saborSanduiche, float valor){
  sanduiche[saborSanduiche] = valor;
  cout << "\t\n----Valor do Sanduiche alterado com sucesso!----";
}

// função para alterar o valor do suco
void alterarSuco(string saborSuco, float valor){
  suco[saborSuco] = valor;
  cout << "\t\n----Valor do Suco alterado com sucesso!----";
}

// função para excluir o sanduiche
void excluirSanduiche(string saborSanduiche)
{
  sanduiche.erase(saborSanduiche);
}

// função para excluir o suco
void excluirSuco(string saborSuco)
{
  suco.erase(saborSuco);
}

// função para salvar sanduiche
void salvarSanduiche()
{
  fstream arquivo;
  arquivo.open("sanduiche.txt", ios::out);
  map<string, float>::iterator it;
  for (it = sanduiche.begin(); it != sanduiche.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}

// função para salvar suco
void salvarSuco()
{
  fstream arquivo;
  arquivo.open("suco.txt", ios::out);
  map<string, float>::iterator it;
  for (it = suco.begin(); it != suco.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}