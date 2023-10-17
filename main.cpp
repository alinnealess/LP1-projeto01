#include <iostream>

#include "gerente.hpp"
#include "cliente.hpp" // Inclui arquivos de cabeçalho personalizados
#include <string>
#include "funcoesCompartilhadas.hpp" // Inclui arquivos de cabeçalho personalizados

using namespace std;

int main()
{
  map<string, float> carrinho; // Cria um mapa para o carrinho do cliente

  lerArquivoSanduiche(); // Carrega informações sobre sanduíches de um arquivo
  lerArquivoSuco();      // Carrega informações sobre sucos de um arquivo
  int perfil = 0;        // Inicializa a variável para o perfil do usuário

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

          // Chama a função para listar sanduíches
          if (opcao == 1)
          {
            listarSanduiches(); 
          }
          // Chama a função para listar sucos
          else if (opcao == 2)
          {
            listarSucos(); 
          }

          // Chama a função para adicionar um novo sanduíche
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

          // // Chama a função para adicionar um novo suco
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

          // Alterar valor de suco
          else if (opcao == 6)
          {
            string saborSuco;
            float valor;

            cout << "Digite o sabor do suco: ";
            cin >> saborSuco;

            cout << "Digite o novo valor do suco: ";
            cin >> valor;

            alterarSuco(saborSuco, valor);
          }

          // excluir sanduiche
          else if (opcao == 7)
          {
            string saborSanduiche;
            cout << "\nSabor do Sanduiche: ";
            cin >> saborSanduiche;
            excluirSanduiche(saborSanduiche);
          }

          // excluir suco
          else if (opcao == 8)
          {
            string saborSuco;
            cout << "\nSabor do Suco: ";
            cin >> saborSuco;
            excluirSuco(saborSuco);
          }

          // encerrar loop
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

        // listar  sucos
        else if (opcao == 2)
        {
          listarSucos();
        }

        // escolher produto
        else if (opcao == 3)
        {
          escolherProduto(carrinho);
        }

        // calcular o valor da compra
        else if (opcao == 4)
        {
          float valorTotal = calcularValorTotalCarrinho(carrinho);
          cout << "Valor total do carrinho: R$ " << valorTotal << endl;
        }

        // visualizar o carrinho
        else if (opcao == 5)
        {
          verCarrinho(carrinho);
        }

        // excluir item do carrinho
        else if (opcao == 6)
        {
          string itemASerExcluido;
          cout << "Digite o nome do item a ser excluido do carrinho: ";
          cin >> itemASerExcluido;
          excluirItemDoCarrinho(carrinho, itemASerExcluido);
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
      salvarSanduiche(); // Salva as informações dos sanduíches em um arquivo
      salvarSuco();      // Salva as informações dos sucos em um arquivo
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