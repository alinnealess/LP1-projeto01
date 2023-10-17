#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <map>

// Definição da estrutura CarrinhoItem, que representa um item no carrinho.
struct CarrinhoItem {
    std::string nome; // Nome do produto
    float valor; // Valor do produto
};

// Funções para ler informações de arquivo.
void lerArquivoSanduiche(); // Lê informações sobre sanduíches de um arquivo.
void lerArquivoSuco(); // Lê informações sobre sucos de um arquivo.

// Funções relacionadas ao carrinho de compras.
void escolherProduto(std::map<std::string, float> &carrinho); // Permite ao cliente escolher produtos e adicioná-los ao carrinho.
void verCarrinho(const std::map<std::string, float> &carrinho);  // Exibe o conteúdo do carrinho de compras.

// Funções relacionadas ao cálculo do valor total do carrinho e à remoção de itens do carrinho.
float calcularValorTotalCarrinho(const std::map<std::string, float> &carrinho); // Calcula o valor total dos itens no carrinho.
void excluirItemDoCarrinho(std::map<std::string, float> &carrinho, const std::string &itemASerExcluido); // Remove um item específico do carrinho.

#endif