// INTEGRANTES: LEONARDO AMORIM DE SOUSA, LUIS FELIPE DOS SANTOS,
// THOMAS ANDREW DE SOUZA BATISTA, NATHAN CARDOSO SILVA
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura do codigo*/

struct clientes {
  char nome[100];
  char sexo;
  int idade;
};
typedef struct clientes clientes;
struct vendas {
  clientes clientes;
  int numItens;
  int qtdsabores;
  float valorTotal;
};
typedef struct vendas vendas;
/*Funções*/
void cadastrarVendas(clientes clientes, vendas *vendas);
void VendaEspecifica(clientes clientes, vendas *vendas);
void verTodasVendas(clientes clientes, vendas *vendas);

/*Menu*/
int main(void) {
  clientes clientes;
  vendas vendas;
  int opcao = 0;
  do {
    printf("\n1) Cadastrar novas vendas\n");
    printf("2) Ver informações de uma venda específica\n");
    printf("3) Ver informações de todas as vendas\n");
    printf("4) Limpar Menu\n");
    printf("5) Encerra programa");
    printf("\nDigite aqui:  ");
    scanf("%i", &opcao);
    switch (opcao) {
    case 1:
      cadastrarVendas(clientes, &vendas);
      break;
    case 2:
      VendaEspecifica(clientes, &vendas);
      break;
    case 3:
      verTodasVendas(clientes, &vendas);
      break;
    case 4:
      system("clear");
      break;
    case 5:
      system("clear");
      printf("\nEncerrando o programa...\n");
      break;
    default:
      printf("\nOpção inválida tente novamente\n");
      break;
    }
  } while (opcao != 5);
  return 0;
}
void cadastrarVendas(clientes clientes, vendas *vendas) {
  int qtdvendas = 0;
  printf("Digite a quantidade de vendas que deseja cadastrar:   ");
  scanf("%i", &qtdvendas);

  /*alacação de memória das vendas*/

  vendas = malloc(qtdvendas * sizeof(*vendas));
  if (vendas == NULL) {
    printf("Erro: Memória Insuficiente!");
    free(vendas);
    return;
  }

  /*Criação do arquivo de texto*/

  FILE *arq;
  arq = fopen("registros.txt", "a");
  if (arq == NULL) {
    printf("Erro ao abrir o arquivo");
    return;
  }

  /*Iniciar cadastro*/

  for (int i = 0; i < qtdvendas; i++) {
    int cont = 0;
    int nome;

    /*pede o nome cliente*/

    do {
      printf("\nDigite o nome do cliente: ");
      getchar();
      /*Scanf bolado*/
      scanf("%[^\n]s", (*vendas).clientes.nome);
      nome = strlen((*vendas).clientes.nome);

      if (nome < 3) {
        printf("\nNome inválido. O nome deve ter mais de 3 caracteres. Por "
               "favor, tente novamente.\n");
      }
    } while (nome < 3);

    /*sexo do cliente*/

    do {
      printf("Digite o sexo do cliente\n");
      printf("(M) Masculino, (F) Feminino, (N) Nao desejo responder\n");
      scanf(" %c", &vendas[i].clientes.sexo);

      /*transforma toda caracter maúscular em minúscular*/

      vendas[i].clientes.sexo = tolower(vendas[i].clientes.sexo);

      if (vendas[i].clientes.sexo != 'm' && vendas[i].clientes.sexo != 'f' &&
          vendas[i].clientes.sexo != 'n') {
        printf("\nOpção inválida\n");
      }
    } while (vendas[i].clientes.sexo != 'm' && vendas[i].clientes.sexo != 'f' &&
             vendas[i].clientes.sexo != 'n');

    /*idade do cliente*/

    do {
      printf("Digite a idade do cliente:   ");
      scanf("%i", &vendas->clientes.idade);
      if (vendas->clientes.idade < 0) {
        printf("\nIdade inválida\n");
      }
    } while (vendas->clientes.idade < 0);

    /*Numero de itens */

    do {
      printf("Digite a quantidade de itens:   ");
      scanf("%i", &vendas->numItens);
      if (vendas->numItens < 0) {
        printf("\nquantidade de itens inválida\n");
      }
    } while (vendas->numItens < 0);

    /*quantidade de sabores*/

    do {
      printf("Digite a quantidade de sabores:   ");
      scanf("%i", &vendas->qtdsabores);
      if (vendas->qtdsabores < 0) {
        printf("\nquantidade de sabores inválida\n");
      }
    } while (vendas->qtdsabores < 0);

    /*Valor total*/

    do {
      printf("Digite o valor total:   ");
      scanf("%f", &vendas->valorTotal);
      if (vendas->valorTotal < 0) {
        printf("\nvalor  inválido\n");
      }
    } while (vendas->valorTotal < 0);

    printf("\nCadastro feito com sucesso!\n");

    /*Média*/

    float media = vendas->valorTotal / vendas->numItens;

    /*registro do cadastro*/

    fprintf(arq, "%s  %c  %i  %i  %i  %.2f %.2f\n", vendas->clientes.nome,
            vendas->clientes.sexo, vendas->clientes.idade, vendas->numItens,
            vendas->qtdsabores, vendas->valorTotal, media);
  }

  fclose(arq);
  free(vendas);
}
void VendaEspecifica(clientes clientes, vendas *vendas) {
  getchar(); /*limpeza do scanf*/

  char opcao;
  char nome[100];
  char linhas[100];

  /*busca pelo nome do clinte*/

  do {
    int encontrado = 0;
    printf("\nDigite o nome:  ");
    scanf("%[^\n]s", nome);
    printf("\n\n");

    /*abriu o arquivo de novo*/

    FILE *arq;
    arq = fopen("registros.txt", "r");
    if (arq == NULL) {
      printf("Erro ao abrir o arquivo");
      return;
    }
    while (fgets(linhas, sizeof(linhas), arq) != NULL) {
      char *t = strtok(linhas, " ");
      if (t != NULL && strcmp(t, nome) == 0) {
        printf("nome: %s\n", t);
        t = strtok(NULL, " "); // SEXO
        printf("sexo: %s\n", t);
        t = strtok(NULL, " "); // idade
        printf("idade: %s\n", t);
        t = strtok(NULL, " "); // itens
        printf("itens: %s\n", t);
        t = strtok(NULL, " "); // numSabores
        printf("numero de Sabores: %s\n", t);
        t = strtok(NULL, " "); // valor total
        printf("valor total: %s\n", t);
        t = strtok(NULL, " "); // Média
        printf("valor da Média: %s\n", t);
        encontrado = 1;
      }
    }
    if (!encontrado) {
      printf("Cliente não encontrado!\n");
    }
    fclose(arq);
    printf("Deseja pesquisar novamente? (s/n): ");
    scanf("  %c", &opcao);
    getchar();
  } while (opcao == 's' || opcao == 'S');
}
void verTodasVendas(clientes clientes, vendas *vendas) {
  char str[255];
  int qtdvalortotal = 0;
  int qtditens = 0;
  int qtdsabores = 0;
  int qtdmulheres = 0;
  int qtdhomens = 0;
  int qtdtotalitens = 0;
  int qtdtotalsabores = 0;
  float qtdtotalvalor = 0;
  float valor = 0;
  float valormedia = 0;
  int cont = 0;
  int contnome = 0;
  int nome = 0;
  char maiornome[100];
  int maior = 0;
  int maioridade = 0;
  /*Abre o arquivo*/
  FILE *arq;
  arq = fopen("registros.txt", "r");
  if (arq == NULL) {
    printf("Erro ao abrir o arquivo");
    return;
  }

  /*pega os menores valores dos itens*/
  do {
    printf("\nDigite o valor: ");
    scanf("%f", &valor);
    if (valor < 0) {
      printf("Valor inválido\n");
    }
  } while (valor < 0);

  char linhas[100];
  while (fgets(linhas, sizeof(linhas), arq) != NULL) {
    char *t = strtok(linhas, " ");
    int nome = strlen(t);
    if (t != NULL) {
      if (nome > maior) {
        strcpy(maiornome, t);
        maior = nome;
      }
      t = strtok(NULL, " "); // SEXO
      if (t != NULL && strcmp(t, "f") == 0) {
        qtdmulheres++;
      } else {
        qtdhomens++;
      }
      t = strtok(NULL, " "); // idade

      if (atoi(t) > maioridade) {
        maioridade = atoi(t);
      }
      t = strtok(NULL, " "); // itens
      qtdtotalitens += atoi(t);
      if (atoi(t) == 1) {
        qtditens++;
      }
      t = strtok(NULL, " "); // numSabores
      qtdtotalsabores += atoi(t);
      if (atoi(t) % 2 == 0) {
        qtdsabores++;
      }
      t = strtok(NULL, " "); // valor total
      qtdtotalvalor += atof(t);
      if (atof(t) < valor) {
        qtdvalortotal++;
      }
      t = strtok(NULL, " "); // Média
    }
    cont++;
  }
  float mediatotal = qtdtotalvalor / cont;

  /*printa a quantidade de valores abaixo do valor digitado*/
  printf("\nquantidade de vendas menores que %.2f: %i\n", valor, qtdvalortotal);
  /*printa a quantidade de vendas que só teve um item*/
  printf("quantidade itens com apenas 1 vendido: %i\n", qtditens);
  /*printa a quantidade de sabores pares*/
  printf("quantidade sabores pares: %i\n", qtdsabores);
  /*printa a quantidade de Mulheres*/
  printf("quantidade de compradoras Mulheres: %i\n", qtdmulheres);
  /*printa a quantidade de homens*/
  printf("quantidade de compradoras Homens: %i\n", qtdhomens);
  /*printa a quantidade total de itens*/
  printf("quantidade total de itens: %i\n", qtdtotalitens);
  /*printa a quantidade total de sabores*/
  printf("quantidade total de sabores: %i\n", qtdtotalsabores);
  /*printa o valor final */
  printf("valor total das compras: %.2f\n", qtdtotalvalor);
  /*printa o valor final */
  printf("media final: %.2f\n", mediatotal);

  printf("Maior nome: %s\n", maiornome);
  printf("Maior idade: %i\n", maioridade);

  fclose(arq);
}