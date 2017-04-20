#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct elemento{
    char nome[50];
}t_elemento;

typedef struct fila{
    t_elemento dados[MAX];
    int inicio;
    int fim;
    int quant_element;

}t_fila;

t_fila criar(){
    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;

    return fila;
}
void limpa_tela(){
    system("pause");
    system("cls");
}
int isVazia(t_fila * fila){
    return(fila->dados==0);
}
int isCheia(t_fila * fila){
    return (fila->quant_element == MAX);
}
int inserir(t_fila * fila, t_elemento valor){
    if (isCheia(fila))
        return 0;
    (fila->quant_element)++;
    fila->fim = (fila->fim+1)%MAX;
    fila->dados[fila->fim] = valor;
    return 1;
}
t_elemento remover(t_fila * fila){
    t_elemento valor = {""};
    if(isVazia(fila))
        return valor;

    valor = fila->dados[fila->inicio];
    fila->dados[fila->inicio].nome[0] = '\0';
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1)%MAX;
    printf("\nA pessoa '%s' foi retirada.\n",valor.nome);
    return valor;
}
void exibir(t_fila * fila){
    int i;
    if(isVazia(fila)){
        printf("Dila vazia \n");
        return;
    }
    printf("\nExibindo fila\n");
    printf("Inicio: %d\n",fila->inicio);
    printf("Fim: %d\n\n",fila->fim);

    for(i = 0; i < MAX;i++){
            printf("%d::%s\n",(i+1),fila->dados[i].nome);
    }
}
void mostrarFila(t_fila * fila){
    printf("\nExibindo fila\n");
    int i;
    int cont = 1;
    for(i = fila->inicio; i != (fila->fim+1)%MAX; i = (i+1)%MAX){
        printf("%d::%s\n",cont,fila->dados[i].nome);
        cont ++;
    }
    printf("Inicio: %d\n",fila->inicio);
    printf("Fim: %d\n",fila->fim);
}
int main()
{
    int i;
    t_elemento valor;
    //CRIAR FILA
    t_fila fila;
    fila = criar();

    //INSERIR 4 PESSOAS E EXIBIR A FILA EM CADA ENTRADA
    for(i = 0; i<4; i++){
        printf("Digite o nome de uma pessoa: \n");
        gets(valor.nome);

        inserir(&fila, valor);
        mostrarFila(&fila);

    }
    limpa_tela();
    //TIRAR 3 PESSOAS E A CADA SAIDA MOSTRAR A FILA
    printf("Retirada de 3 pessoas da Fila: \n\n");
    for(i = 0; i<3;i++){
        remover(&fila);
        mostrarFila(&fila);
    }
    limpa_tela();
    //Entra 4 pessoas e a cada entrada mostrar a fila
    for(i = 0; i<4; i++){
        printf("Digite o nome de uma pessoa: \n");
        scanf("%s",&valor.nome);

        inserir(&fila, valor);
        mostrarFila(&fila);
    }
    return 0;
}
