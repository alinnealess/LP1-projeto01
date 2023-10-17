#include <iostream>
#include <map>
#include "cliente.hpp" // Inclui arquivos de cabeçalho personalizados
#include <fstream>
#include "funcoesCompartilhadas.hpp" // Inclui arquivos de cabeçalho personalizados

using namespace std;

extern map<string, float> sanduiche; // Mapas para sanduíches e sucos
extern map<string, float> suco;
map<string, float> carrinho;

// Função para escolher um produto e adicioná-lo ao carrinho
void escolherProduto(map<std::string, float> &carrinho)
{
  int opcao = 0;
  while (opcao != 3)
  {
    cout << "\n\t==ESCOLHA SEU PEDIDO==" << endl;
    cout << "\t1. Escolher Sanduiche" << endl;
    cout << "\t2. Escolher Suco" << endl;
    cout << "\t3. Voltar ao Menu Anterior" << endl;
    cout << "\tDigite a opcao desejada: ";
    cin >> opcao;


    if (opcao == 1)
    {
      string saborSanduiche;
      cout << "Digite o nome do sanduiche: ";
      cin >> saborSanduiche;

      if (sanduiche.find(saborSanduiche) != sanduiche.end())
      {
        cout << "Sanduiche " << saborSanduiche << " adicionado ao carrinho." << endl;
        carrinho[saborSanduiche] = sanduiche[saborSanduiche]; // Adiciona o preço do sanduíche
      }
      else
      {
        cout << "Sanduiche não encontrado no menu." << endl;
      }
    }
    else if (opcao == 2)
    {
      string saborSuco;
      cout << "Digite o nome do suco: ";
      cin >> saborSuco;

      if (suco.find(saborSuco) != suco.end())
      {
        cout << "Suco " << saborSuco << " adicionado ao carrinho." << endl;
        carrinho[saborSuco] = suco[saborSuco]; // Adiciona o preço do suco
      }
      else
      {
        cout << "Suco não encontrado no menu." << endl;
      }
    }
    else if (opcao == 3)
    {
      break;
    }
  }
}

// Função para calcular o valor total dos itens no carrinho
float calcularValorTotalCarrinho(const map<string, float> &carrinho)
{
  float valorTotal = 0;
  for (const auto &item : carrinho)
  {
    valorTotal += item.second; // Adiciona o valor do produto ao valor total
  }
  return valorTotal;
}

// Função para visualizar o conteúdo do carrinho de compras
void verCarrinho(const map<string, float> &carrinho)
{
  if (carrinho.empty())
  {
    cout << "\t---Seu carrinho está vazio.---" << endl;
  }
  else
  {
    cout << "\t=== Carrinho de Compras ===" << endl;
    for (const auto &item : carrinho)
    {
      cout << "\tProduto: " << item.first << endl; // Chave (nome do produto)
      cout << "\tValor: R$ " << item.second << endl; // Valor do produto
      cout << "\t--------------------------" << endl;
    }
  }
}

// Função para remover um item do carrinho
void excluirItemDoCarrinho(map<string, float> &carrinho, const string &itemASerExcluido)
{
  auto it = carrinho.find(itemASerExcluido);
  if (it != carrinho.end())
  {
    carrinho.erase(it);
  }
}