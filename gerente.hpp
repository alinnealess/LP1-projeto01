#ifndef GERENTE_HPP
#define GERENTE_HPP

//Adiciona um novo sanduíche ao menu
void cadastrarSanduiche(std::string sanduiche, float valor);
//Adiciona um novo suco ao menu
void cadastrarSuco(std::string suco, float valor);

//Altera o valor de um sanduíche existente no menu
void alterarSanduiche(std::string saborSanduiche, float valor);
//Altera o valor de um suco existente no menu.
void alterarSuco(std::string saborSuco, float valor);

//Remove um sanduíche do menu pelo nome.
void excluirSanduiche(std::string saborSanduiche);
//Remove um suco do menu pelo nome.
void excluirSuco(std::string saborSuco);

// Salva o menu de sanduíches de volta ao arquivo "sanduiche.txt".
void salvarSanduiche();
//Salva o menu de sucos de volta ao arquivo "suco.txt".
void salvarSuco();

#endif