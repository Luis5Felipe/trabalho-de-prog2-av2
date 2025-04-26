# Trabalho de Programação II – Sorveteria

## Requisitos

- Compilador C instalado (como GCC)
- IDE (Visual Studio Code, CLion, Code::Blocks ou outra de sua preferência)
- Git instalado

## Como rodar o projeto

1. Clone o repositório:
````bash
git clone git@github.com:Luis5Felipe/trabalho-de-prog2-av2.git
````
2. Acesse a pasta do projeto:
````bash
cd trabalho-de-prog2-av2
````
3. Compile o projeto:
````bash
gcc main.c -o sorveteria
````
4. Execute o programa:
````bash
./sorveteria
````

# Sobre o Projeto

Este trabalho consiste em modelar e implementar um sistema gerenciador para uma sorveteria.  
Leia atentamente o enunciado do problema, identifique os elementos do sistema e cumpra as etapas abaixo.  
O projeto será testado contra plágio vindo de Inteligência Artificial (ChatGPT entre outros).  
Caso o código seja produzido desta maneira, o trabalho do grupo será desconsiderado.

## Enunciado do Problema

Uma sorveteria precisa controlar suas compras, entender seus clientes e realizar algumas consultas.  
Para isso, você foi contratado para desenvolver a primeira versão de um software gerenciador dessa loja.

---

## Etapas

> **Leia todas as etapas antes de começar a implementar o trabalho.**  
> Lembre-se que a participação de todos influencia diretamente na nota final do trabalho.

---

### 1. Criar o Menu Principal

Você deve fazer um menu pedindo para o usuário escolher entre as seguintes opções:

- Cadastrar novas vendas
- Ver informações de uma venda específica, baseado no nome do cliente
- Ver informações de todas as vendas
- Encerrar o programa

---

### 2. Fazer o Cadastro de uma Quantidade de Vendas Definida pelo Usuário

- Pergunte ao usuário qual a quantidade de vendas que ele deseja cadastrar.
- Crie um vetor com alocação dinâmica de memória e cadastre cada venda realizada.

Cada venda é uma estrutura representada por:

- Cliente (estrutura):
    - Nome
    - Sexo
    - Idade
- Número de itens
- Número de sabores
- Valor total da compra

#### Validações obrigatórias:

- Impedir o cadastro de valores negativos e informar este erro.
- Impedir o cadastro quando o sexo do cliente for inválido (diferente de `m`, `f` ou `n`) e informar este erro.
- Impedir o cadastro se o nome do cliente possuir menos de 3 letras e informar este erro.

#### Observação:

- Informar ao final de cada cadastro de compra que a mesma foi cadastrada com sucesso, caso não aconteça nenhum erro.
- Após o término de todo o cadastro, salve as informações em um arquivo de texto nomeado **`registros.txt`**.
- Pergunte ao usuário se ele deseja cadastrar mais itens (quantidade informada novamente) ou voltar ao menu principal.

---

### 3. Pesquisar uma Venda Específica

- Peça o nome do cliente a ser pesquisado.
- Informar todas as vendas feitas para este cliente:
    - Valor total de cada compra
    - Número de sabores
    - Quantidade de itens em cada compra
- Exibir também a média de valor das compras feitas por este cliente.
- Caso não encontre o cliente, informar que não há compras naquele nome.

Após exibir as informações das compras ou a informação que não encontrou:

- Perguntar se o usuário deseja pesquisar novamente ou retornar ao menu principal.

---

### 4. Ver Informações de Todas as Vendas

Você deve:

- Pedir um valor que será usado para exibir a quantidade de vendas abaixo deste valor.
- Exibir a quantidade de vendas que teve somente 1 item vendido.
- Exibir a quantidade de vendas que teve um número par de sabores.
- Exibir a quantidade de compradores mulheres.
- Exibir o valor total comprado por homens.
- Exibir a quantidade total de itens vendidos.
- Exibir o número total de sabores vendidos.
- Exibir o valor total das compras.
- Exibir o valor médio de uma compra.
- Exibir os dados da venda do cliente com o maior nome (se ele fez mais de uma compra, exibir os dados de cada venda).
- Exibir os dados da venda do cliente mais novo (se ele fez mais de uma compra, exibir os dados de cada venda).

Após exibir as informações:

- Perguntar se o usuário deseja retornar ao menu principal.
    - Se sim, retorne ao menu principal.
    - Se não, encerre o programa.

---

### 5. Carregar Vendas Salvas no Início do Programa

- Ao abrir o programa, carregue todas as compras do arquivo **`registros.txt`**, caso exista.
- Todo o registro de compras deve ser salvo no **`registros.txt`**.
- Ao cadastrar novas vendas, elas devem ser adicionadas às vendas já existentes no arquivo.
- A melhor forma de navegar e gerenciar as informações salvas é de livre decisão do desenvolvedor.

---
