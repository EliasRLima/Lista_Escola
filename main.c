#include <stdio.h>
#include <stdlib.h>

struct tipo_disciplina{
    int cod_disciplina;
    char nome_disciplina[10];
};
typedef struct tipo_disciplina Disciplina;

struct tipo_aluno{
    int cod_aluno;
    int serie;
    char nome_aluno[250];
};
typedef struct tipo_aluno Aluno;

struct tipo_nota{
    struct tipo_aluno aluno;
    struct tipo_disciplina disciplina;
    float nota1;
    float nota2;
    float nota3;
    float nota_recuperacao;
    struct tipo_nota *prox;
};
typedef struct tipo_nota elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {NULL, NULL, 0, 0, 0, 0, NULL};

#include "tad_list2.c";
#include "lista_escola.c";


int main(){

    tipo_lista lista;
    inicializa_lista(&lista);
    carregar_lista(&lista);
    //printf("O sistema iniciou com %d elementos!\n", lista.tamanho);
    int menu = 0;

    while(menu != 5){
        //system("cls");1
        //listar(lista);
        //printf("O sistema esta com %d elementos!\n", lista.tamanho);
        printf("Bem vindo!\n1 - diario por serie\n2 - adicionar aluno\n5 - Sair\nEscolha: ");
        scanf("%d",&menu);
        if(menu == 1){
            printf("Digite o codigo da disciplina: ");
            int d;
            scanf("%d",&d);
            listar_serie(lista,d);
            //system("pause");
            continue;
        }else if(menu == 2){
            cadAluno();
            printf("O aluno foi adicionado!\n");
            carregar_lista(&lista);
            //printf("O sistema atualizou para %d elementos!\n", lista.tamanho);
            //system("pause");
            continue;
        }
        //system("pause");
    }
    return 0;
    
}