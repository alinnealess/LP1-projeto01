#include <iostream>
#include <map>
#include "cliente.hpp"
#include <vector>
#include <fstream>
#include "funcoesCompartilhadas.hpp"

using namespace std;

extern map<string, float> sanduiche;
extern map<string, float> suco;
vector<CarrinhoItem> carrinho;

void escolherProduto()
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
        float valor = sanduiche[saborSanduiche];
        bool found = false;
        for (CarrinhoItem &item : carrinho)
        {
          if (item.nome == saborSanduiche)
          {
            item.valor += valor;
            found = true;
            break;
          }
        }

        if (!found)
        {
          CarrinhoItem novoItem;
          novoItem.nome = saborSanduiche;
          novoItem.valor = valor;
          carrinho.push_back(novoItem);
        }

        cout << "\n---Sanduiche " << saborSanduiche << " adicionado ao carrinho.---" << endl;
      }
      else
      {
        cout << "\n\t---Sanduiche não encontrado no menu.---" << endl;
      }
    }
    else if (opcao == 2)
    {
      string saborSuco;
      cout << "Digite o nome do suco: ";
      cin >> saborSuco;

      if (suco.find(saborSuco) != suco.end())
      {
        float valor = suco[saborSuco];
        bool found = false;
        for (CarrinhoItem &item : carrinho)
        {
          if (item.nome == saborSuco)
          {
            item.valor += valor;
            found = true;
            break;
          }
        }

        if (!found)
        {
          CarrinhoItem novoItem;
          novoItem.nome = saborSuco;
          novoItem.valor = valor;
          carrinho.push_back(novoItem);
        }

        cout << "\n--Suco " << saborSuco << " adicionado ao carrinho.--" << endl;
      }
      else
      {
        cout << "\n---Suco não encontrado no menu.----" << endl;
      }
    }
    else if (opcao == 3)
    {
      break;
    }
  }
}

float calcularValorTotalCarrinho()
{

  float valorTotal = 0;
  for (const auto &item : carrinho)
  {
    valorTotal += item.valor;
  }
  return valorTotal;
}

void verCarrinho()
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
      cout << "\tProduto: " << item.nome << endl;
      cout << "\tValor: R$ " << item.valor << endl;
      cout << "\t--------------------------" << endl;
    }
  }
}

void excluirItemDoCarrinho(vector<CarrinhoItem> &carrinho, const string &itemASerExcluido)
{
  for (auto it = carrinho.begin(); it != carrinho.end();)
  {
    if (it->nome == itemASerExcluido)
    {
      it = carrinho.erase(it);
    }
    else
    {
      ++it;
    }
  }
}