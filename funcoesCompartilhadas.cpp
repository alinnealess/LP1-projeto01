#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "funcoesCompartilhadas.hpp"

using namespace std;

map<string, float> sanduiche;
map<string, float> suco;

void lerArquivoSanduiche()
{
  // Implementação da função lerArquivoSanduiche
  vector<string> linhas;
  fstream arquivoSanduiche;

  arquivoSanduiche.open("sanduiche.txt", ios::in);
  string temp;

  while (getline(arquivoSanduiche, temp))
  {
    linhas.push_back(temp);
  }
  arquivoSanduiche.close();

  for (int i = 0; i < linhas.size(); i += 2)
  {
    sanduiche[linhas[i]] = stof(linhas[i + 1]);
  }
}

void lerArquivoSuco()
{
  // Implementação da função lerArquivoSuco

  vector<string> linha;
  fstream arquivoSuco;

  arquivoSuco.open("suco.txt", ios::in);
  string temp;

  while (getline(arquivoSuco, temp))
  {
    linha.push_back(temp);
  }
  arquivoSuco.close();

  for (int i = 0; i < linha.size(); i += 2)
  {
    suco[linha[i]] = stof(linha[i + 1]);
  }
}

void listarSanduiches()
{
  map<string, float>::iterator it;

  cout << "\n=====================================" << endl;
  for (it = sanduiche.begin(); it != sanduiche.end(); it++)
  {
    cout << "Sanduiche: " << it->first << endl;
    cout << "Valor: R$ " << it->second << endl;
    cout << "=====================================" << endl;
  }
  cout << endl;
}

// função para listar suco
void listarSucos()
{
  map<string, float>::iterator it;
  cout << "\n=====================================" << endl;
  for (it = suco.begin(); it != suco.end(); it++)
  {
    cout << "Suco: " << it->first << endl;
    cout << "Valor: R$ " << it->second << endl;
    cout << "=====================================" << endl;
  }
  cout << endl;
}