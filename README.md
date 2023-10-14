# LP1 DISCIPLINA DE LÓGICA DE PROGRAMAÇÃO

Programa em C++ de uma interface de linha de comando simples para um sistema de pedidos de sanduíches e sucos em uma lanchoente. Os usuários podem escolher entre dois perfis: "Gerente" e "Cliente". O perfil de Gerente oferece opções para gerenciar o menu, enquanto o perfil de Cliente permite que os clientes façam pedidos e gerenciem seu carrinho de compras.

Principais componentes e funcionalidades do código:

1. **Programa Principal (main.cpp)**:
   - Ele fornece um menu para que os usuários escolham entre Gerente, Cliente ou sair.
   - Dependendo do perfil escolhido, o programa direciona o usuário para a seção de Gerente ou Cliente.

2. **Perfil de Gerente**:
   - O perfil de Gerente requer uma senha (admin) para acesso.
   - Ele oferece opções de menu para gerenciar os itens de sanduíches e sucos, incluindo listagem, adição, alteração e remoção de itens.
   - Permite salvar o menu atualizado em arquivos (sanduiche.txt e suco.txt).

3. **Perfil de Cliente**:
   - O perfil de Cliente permite que os clientes:
     - Listem os itens de sanduíches e sucos disponíveis.
     - Escolham produtos para adicionar ao carrinho.
     - Calculem o valor total dos itens em seu carrinho.
     - Vejam seu carrinho de compras.
     - Removam itens do carrinho.

4. **Funções de Gerente (gerente.cpp)**:
   - Contém funções para gerenciar o menu (cadastrarSanduiche, cadastrarSuco, alterarSanduiche, excluirSanduiche, salvarSanduiche, etc.).
   - Essas funções modificam um mapa que armazena os itens de sanduíches e sucos.

5. **Funções de Cliente (cliente.cpp)**:
   - Contém funções para que os clientes interajam com o menu e seu carrinho (escolherProduto, calcularValorTotalCarrinho, verCarrinho, excluirItemDoCarrinho).
   - Essas funções permitem que os clientes escolham itens, calculem totais, visualizem seu carrinho e removam itens do carrinho.

6. **Arquivos de Cabeçalho (gerente.hpp e cliente.hpp)**:
   - Declaram as funções que são definidas nos respectivos arquivos .cpp.

7. **Arquivos de Dados (sanduiche.txt e suco.txt)**:
   - Esses arquivos armazenam os itens do menu e seus preços. O formato é "nome" seguido de "preço".

Há uma interface de linha de comando básica para gerenciar um menu e fazer pedidos, e ela utiliza arquivos de texto para persistir dados do menu. Os usuários podem navegar pelo menu, criar/atualizar itens de menu como gerente ou fazer pedidos como cliente.
