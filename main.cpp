#include <iostream>
#include <vector>
#include "gerente.hpp"
#include "cliente.hpp"
#include <string>
#include "funcoesCompartilhadas.hpp"

using namespace std;


int main()
{

  lerArquivoSanduiche();
  lerArquivoSuco();
  int perfil = 0;

  vector<CarrinhoItem> carrinho;

  while (perfil != 3)
  {
    // Menu inicial para escolher perfil do usuário:
    cout << "\n\t== BEM VINDO A LANCHONETE LP1 ==" << endl;
    cout << "\tSelecione o seu perfil:" << endl;
    cout << "\t1. Gerente" << endl;
    cout << "\t2. Cliente" << endl;
    cout << "\t3. Sair" << endl;
    cout << "Digite a opcao desejada: ";

    cin >> perfil;

    // Perfil Gerente
    if (perfil == 1)
    {
      cout << "\nOla, Gerente! \nDigite a sua senha: ";
      string senha;
      cin >> senha;
      if (senha != "admin")
      {
        cout << "Senha Incorreta. \nAcesso Negado!" << endl;
      }
      else
      {
        int opcao;
        while (opcao != 9)
        {
          cout << "\n\t === MENU DO GERENTE ===" << endl;
          cout << "\t 1. Listar sanduiches" << endl;
          cout << "\t 2. Listar sucos" << endl;
          cout << "\t 3. Adicionar novo sanduiche" << endl;
          cout << "\t 4. Adicionar novo suco" << endl;
          cout << "\t 5. Alterar valor de sanduiche" << endl;
          cout << "\t 6. Alterar valor de suco" << endl;
          cout << "\t 7. Excluir sanduiche" << endl;
          cout << "\t 8. Excluir suco" << endl;
          cout << "\t 9. Sair" << endl;
          cout << "Digite a opcao desejada: ";

          cin >> opcao;

          if (opcao == 1)
          {
            listarSanduiches();
          }
          else if (opcao == 2)
          {
            listarSucos();
          }
          else if (opcao == 3)
          {
            string saborSanduiche;
            float valor;

            cout << "Digite o sabor do sanduiche: ";
            cin >> saborSanduiche;

            cout << "Digite o valor do sanduiche: ";
            cin >> valor;

            cadastrarSanduiche(saborSanduiche, valor);
          }

          // cadastrarSuco
          else if (opcao == 4)
          {
            string saborSuco;
            float valor;

            cout << "Digite o sabor do suco: ";
            cin >> saborSuco;

            cout << "Digite o valor do suco: ";
            cin >> valor;

            cadastrarSuco(saborSuco, valor);
          }

          // Alterar valor de sanduiche
          else if (opcao == 5)
          {
            string saborSanduiche;
            float valor;

            cout << "Digite o sabor do sanduiche: ";
            cin >> saborSanduiche;

            cout << "Digite o novo valor do sanduiche: ";
            cin >> valor;

            alterarSanduiche(saborSanduiche, valor);
          }
          else if (opcao == 6)
          {
            string saborSuco;
            float valor;

            cout << "Digite o sabor do sanduiche: ";
            cin >> saborSuco;

            cout << "Digite o novo valor do sanduiche: ";
            cin >> valor;

            alterarSuco(saborSuco, valor);
          }
          else if (opcao == 7)
          {
            string saborSanduiche;
            cout << "\nSabor do Sanduiche: ";
            cin >> saborSanduiche;
            excluirSanduiche(saborSanduiche);
          }

          else if (opcao == 8)
          {
            string saborSuco;
            cout << "\nSabor do Suco: ";
            cin >> saborSuco;
            excluirSuco(saborSuco);
          }

          else if (opcao == 9)
          {
            break;
          }
        }
      }
    }

    // Perfil Cliente
    else if (perfil == 2)
    {
      int opcao;

      while (opcao != 7)
      {
        cout << "\n\t === MENU DO CLIENTE ===" << endl;
        cout << "\t1. Listar sanduiches" << endl;
        cout << "\t2. Listar sucos" << endl;
        cout << "\t3. Escolher um produto" << endl;
        cout << "\t4. Calcular o valor do carrinho" << endl;
        cout << "\t5. Ver o carrinho" << endl;
        cout << "\t6. Excluir um item do carrinho" << endl;
        cout << "\t7. Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        // listar sanduiches disponiveis
        if (opcao == 1)
        {
          listarSanduiches();
        }

        // listar sanduiches sucos
        else if (opcao == 2)
        {
          listarSucos();
        }

        // escolher produto
        else if (opcao == 3)
        {
          // string saborSanduiche;
          // float valor;
          escolherProduto();
        }

        // calcular o valor da compra
        else if (opcao == 4)
        {
          float valorTotal = calcularValorTotalCarrinho();
          cout << "Valor total do carrinho: R$ " << valorTotal << endl;
        }

        // visualizar o carrinho
        else if (opcao == 5)
        {
          verCarrinho();
        }

        // excluir item do carrinho
        else if (opcao == 6)
        {
          string itemASerExcluido;
          cout << "Digite o nome do item a ser excluido do carrinho: ";
          cin >> itemASerExcluido;
          excluirItemDoCarrinho(carrinho, itemASerExcluido);
          verCarrinho();
        }

        // sair do loop
        else if (opcao == 7)
        {
          break;
        }
      }
    }

    // Sair do sistema
    else if (perfil == 3)
    {
      salvarSanduiche();
      salvarSuco();
      cout << "\n\t==========================" << endl;
      cout << "\t    Sistema finalizado.    " << endl;
      cout << "\t Agradecemos a sua visita! " << endl;
      cout << "\t==========================" << endl;
    }

    // Caso o usuario digite um numero invaldio
    else
    {
      cout << "\n == Opcao invalida ===" << endl;
    }
  }
}