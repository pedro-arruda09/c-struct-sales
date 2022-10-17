#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto
{
  char id_prod[5];
  char nome_prod[30];
  int tipo, cod_prod;
  float valor;
  char descricao[100];
};

struct Cliente
{
  char id_cliente[5];
  char nome_cliente[30];
  char endereco[100];
  int status, cod_cliente;
};

struct Compra
{
  char id_compra[5];
  char id_cliente[5];
  char id_prod[5];
};

#define MAX 100
typedef struct Produto *ptr_prod;
ptr_prod p_prod[MAX];

typedef struct Cliente *ptr_cliente;
ptr_cliente p_cliente[MAX];

typedef struct Compra *ptr_compra;
ptr_compra p_compra[MAX];

int p;

void inserirProduto(int qtd_prod);
void buscarProduto();
void opcaoProduto();
void inserirCliente(int qtd_cliente);
void buscarCliente();
void removerCliente();
void opcaoCliente();
void opcao();
void compra();

void inserirProduto(int qtd_prod)
{
  do
  {
    printf("\nDigite o número de produtos que você deseja inserir: ");
    scanf("%i", &qtd_prod);
  } while (qtd_prod <= 0);

  for (int i = 0; i < qtd_prod; i++)
  {
    p_prod[i] = (ptr_prod)malloc(sizeof(struct Produto));
    printf("\nProduto (%i):\n\n", i);
    printf("Tipo: ");
    scanf("%i", &p_prod[i]->tipo);
    printf("Nome: ");
    scanf("%s", p_prod[i]->nome_prod);
    printf("Valor: ");
    scanf("%f", &p_prod[i]->valor);
    p_prod[i]->cod_prod = i;
    printf("Código do produto: %i\n", i);
  }
  system("clear");
}

void buscarProduto()
{
  int v;
  printf("\nDigite o código do produto: ");
  scanf("%i", &v);
  printf("\nO produto possui nome %s, tipo %i e valor %f\n", p_prod[v]->nome_prod, p_prod[v]->tipo, p_prod[v]->valor);
}

void removerProduto()
{
  int i, n = 0;
  int posicao;

  printf("Digite o código do produto que deseja remover: %d\n", n - 1);
  scanf("%d", &posicao);

  for (i = posicao; i < n - 1; i++)
  {
    p_prod[i] = p_prod[i + 1];
  }
  n--;
}

void opcaoProduto()
{
  int qtd_prod;
  int opcao;
  printf("Deseja fazer o que?\n\n1.Inserir\n2.Buscar\n3.Remover\n\n");
  scanf("%i", &opcao);
  system("clear");
  switch (opcao)
  {
  case 1:
    inserirProduto(qtd_prod);
    break;
  case 2:
    buscarProduto();
    break;
  case 3:
    removerProduto();
    break;
  default:
    break;
  }
}

void inserirCliente(int qtd_cliente)
{
  do
  {
    printf("\nDigite o número de clientes que você deseja inserir: ");
    scanf("%i", &qtd_cliente);
  } while (qtd_cliente <= 0);

  for (int i = 0; i < qtd_cliente; i++)
  {
    p_cliente[i] = (ptr_cliente)malloc(sizeof(struct Cliente));
    printf("Cliente (%i):\n\n", i);
    printf("Nome: ");
    scanf("%s", p_cliente[i]->nome_cliente);
    printf("Endereço: ");
    scanf("%s", p_cliente[i]->endereco);
    p_cliente[i]->cod_cliente = i;
    printf("Código do cliente: %i\n", i);
  }
  system("clear");
}

void buscarCliente()
{
  int v;
  printf("Digite o código do cliente: ");
  scanf("%i", &v);
  printf("\nO cliente possui nome %s e mora no endereço %s\n", p_cliente[v]->nome_cliente, p_cliente[v]->endereco);
}

void removerCliente()
{
  int i, n = 0;
  int posicao;

  printf("Digite o código do cliente que deseja remover: %d\n", n - 1);
  scanf("%d", &posicao);

  for (i = posicao; i < n - 1; i++)
  {
    p_cliente[i] = p_cliente[i + 1];
  }
  n--;
}

void opcaoCliente()
{
  int qtd_cliente;
  int opcao;
  printf("Deseja fazer o que?\n\n1.Inserir\n2.Buscar\n3.Remover\n\n");
  scanf("%i", &opcao);
  system("clear");
  switch (opcao)
  {
  case 1:
    inserirCliente(qtd_cliente);
    break;
  case 2:
    buscarCliente();
    break;
  case 3:
    removerCliente();
    break;
  default:
    break;
  }
}

void compra()
{
  int qtd = 0;
  int c;
  printf("\nDigite o código do cliente: ");
  scanf("%i", &c);
  printf("\nO cliente possui nome %s e mora no endereço %s\n", p_cliente[c]->nome_cliente, p_cliente[c]->endereco);
  int cod_cliente = p_cliente[c]->cod_cliente;
  int v;
  printf("\nQue produto você deseja?");
  printf("\nDigite o código do produto: ");
  scanf("%i", &v);
  int cod_produto = p_prod[v]->cod_prod;
  printf("\nO produto possui nome %s, tipo %i e valor %f\n", p_prod[v]->nome_prod, p_prod[v]->tipo, p_prod[v]->valor);
  printf("%c", p_compra[v]);
  int op;
  printf("\nDeseja adicionar ao carrinho?\n1.Sim\n2.Não\n\n");
  scanf("%i", &op);
  system("clear");
  if (op == 1)
  {
    qtd++;
    printf("\nValor total: %f", p_prod[v]->valor * qtd);
    char compra[cod_cliente][cod_produto];
    printf("%c", compra[cod_cliente][cod_produto]);
  }
  else
  {
    opcao();
  }
}

void recomendar(int cod_prod) {
    int a, i, j, c = 0;
    scanf("%d", &a);
    int vetor[a];
    for (i = 0; i < a; i++) {
        scanf("%d", &vetor[i]);
    }
    for (i = 0; i < a; i++) {
        for (j = i + 1; j < a; j++) {
            if (vetor[i] == vetor[j]) {
                c++;
            }
        }
    printf("%d\n", c);
    return 0;
}
}

void opcao()
{
  int opcao;
  printf("\n1.Produto\n2.Cliente\n3.Compra\n\n");
  scanf("%i", &opcao);
  system("clear");
  switch (opcao)
  {
  case 1:
    opcaoProduto();
    int op;
    int i = 0;
    do
    {
      printf("\n1.Produto\n2.Início\n\n");
      scanf("%i", &op);
      system("clear");
      if (op == 1)
      {
        opcaoProduto();
      }
      else
      {
        main();
      }
    } while (i == 0);
    break;
  case 2:
    opcaoCliente();
    int op2;
    int i2 = 0;
    do
    {
      printf("\n1.Cliente\n2.Início\n\n");
      scanf("%i", &op);
      system("clear");
      if (op == 1)
      {
        opcaoCliente();
      }
      else
      {
        main();
      }
    } while (i == 0);
    break;
  case 3:
    compra();
    int op3;
    printf("\nDeseja continuar comprando?\n1.Sim\n2.Não\n\n");
    scanf("%i", &op3);
    if (op3 == 1)
    {
      compra();
    }
    else
    {
      main();
    }
  default:
    break;
  }
}

int main()
{
  opcao();

  return 0;
}