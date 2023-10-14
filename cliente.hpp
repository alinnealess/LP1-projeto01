#ifndef CLIENTE_HPP
#define CLIENTE_HPP


#include <vector>
#include <string>

struct CarrinhoItem {
    std::string nome;
    float valor;
};

void lerArquivoSanduiche();
void lerArquivoSuco();

void escolherProduto();
void verCarrinho(); 

float calcularValorTotalCarrinho();
void excluirItemDoCarrinho(std::vector<CarrinhoItem> &carrinho, const std::string &itemASerExcluido); 
#endif