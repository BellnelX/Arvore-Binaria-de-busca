#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
}NoArv;

// versão com retorno
NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL) {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1 (raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1 (raiz->direita, num);
        return raiz;
    }
    
}

//versão sem retorno
void inserir_versao_2 (NoArv **raiz, int num){
    if (*raiz == NULL){
        *raiz= malloc(sizeof(NoArv));
        (*raiz) -> valor = num;
        (*raiz) ->esquerda = NULL;
        (*raiz) ->direita = NULL;
    }
    else{
        if (num < (*raiz) ->valor)
        inserir_versao_2(&((*raiz) ->esquerda), num);
        else
            inserir_versao_2(&((*raiz) -> direita), num);
    }
}

// imprimir_versao_1 = pre-ordem
void imprimir_versao_1(NoArv *raiz) {
    if (raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
    
}

// imprimir_versao_2 = em-ordem
void imprimir_versao_2(NoArv *raiz) {
    if (raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main (){

    NoArv *raiz = NULL;
    int opcao, valor;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao) ;

        switch (opcao){
            case 1:
                printf("\n\tDigite um valor: ");
                scanf("%d", &valor);
                //raiz = inserir_versao_1 (raiz, valor);
                inserir_versao_2 (&raiz, valor);
                break;
            case 2:
                printf("\n\tPrimeira Impressão:\n\t");
                imprimir_versao_1 (raiz);
                printf("\n");
                printf("\n\tSegunda Impressão:\n\t");
                imprimir_versao_2 (raiz);
                printf("\n");
                break;
            default:
                if (opcao != 0)
                    printf ("\n\t Opção invalida!!!");
        }
    } while (opcao != 0);
    

    return 0;
}
