#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct stack Stack;

struct stack {
  int top; // elemento array[n-1] -> topo da pilha, n é o tamanho do array
  int array[MAX];
};
// primeira posição livre do vetor é array[n]
// topo da pilha é array[n-1]
// array[0] a array[MAX - 1] são as posições livres da pilha

Stack *create_stack(void) {
  Stack *s = malloc(sizeof(Stack));
  s->top = 0;
  return s;
}

void push(Stack *s, int value) {
  if (s->top == MAX) {
    printf("Stack Overflow - pilha cheia!\n");
    exit(1);
  }
  // insere o elemento na próxima posição livre
  s->array[s->top] = value;
  s->top++;
}

int empty_stack(Stack *s) {
  // retorna se vazia
  return (s->top == 0);
}

int pop(Stack *s) {
  int v;
  if (empty_stack(s)) {
    printf("Stack Underflow - pilha vazia!\n");
    exit(1);
  }
  v = s->array[s->top - 1]; // pega o elemento do topo
  s->top--;
  return v;
}

void peek(Stack *s) {
  if (empty_stack(s)) {
    printf("Stack Underflow - pilha vazia !\n");
    exit(1);
  }
  printf("Topo da pilha: %d\n", s->array[s->top - 1]);
}

void erase_stacK(Stack *s) {
  // limpa a memoria alocada para pilha
  free(s);
}

void print_stack(Stack *s) {
  int i;
  printf("Imprimessão da pilha: \n[");
  for (i = s->top - 1; i >= 0; i--) {
    printf("%d", s->array[i]);
  }
  printf("\b\b ] \n");
}

int main(void) {
  int opcao = 0;
  do {
    printf("---- Menu ----\n");
    printf("1 - Criar pilha\n");
    printf("2 - Inserir elemento no topo\n");
    printf("3 - Remover elemento do topo\n");
    printf("4 - Espiar pilha \n");
    printf("5 - Imprimir pilha\n");
    printf("6 - Apagar pilha\n");
    printf("7 - Sair\n");

    printf("Selecione uma opção: ");
    scanf("%d", &opcao);

    Stack *s;

    switch (opcao) {
    case 1:
      s = create_stack();
      break;
    case 2:
      printf("Digite o valor a ser inserido: ");
      int valor;
      scanf("%d", &valor);
      push(s, valor);
      printf("Valor inserido com sucesso!\n");
      break;
    case 3:
      pop(s);
      printf("Valor removido com sucesso!\n");
    case 4:
      peek(s);
    case 5:
      print_stack(s);
    case 6:
      erase_stacK(s);
      printf("Pilha apagada com sucesso!\n");
    }
  } while (opcao != 7);
  return 0;
}