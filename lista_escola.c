#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listar_aluno(Aluno a){
  printf("\nNome: %s\nSerie: %d\nCodigo %d\n",a.nome_aluno, a.serie, a.cod_aluno);
  return 1;
}

Aluno getAluno(int cod)
{
  Aluno a;
  a.cod_aluno = 0;
  FILE *arq2;
    
    arq2 = fopen("alunos.txt","r");
    
    if (!arq2){
        printf("Falha ao abrir arquivo aluno.\n");
        fclose(arq2);
        return a;
    }
    int i;

    char txt[100];

    while(fgets(txt, 100, arq2) != (char*)EOF){
        if(feof(arq2)){
            break;
        }
        char *token = strtok(txt," ");
        a.cod_aluno = (int)atof(token);
        token = strtok(NULL, " ");
        a.serie = (int)atof(token);
        //printf("indo pegar nome!\n");
        token = strtok(NULL, "@");
        //printf("pegou por @\n");
        strcpy(a.nome_aluno, token);
        if(cod==a.cod_aluno)
        {
          //listar_aluno(a);
          fclose(arq2);
          return a;
        }
    }fclose(arq2);
    
    Aluno b;
    b.cod_aluno = 0;
    return b;

}

 Disciplina getDisciplina(int cod_disciplina)
{
  Disciplina b;
  FILE *arq3;
  //printf("indo buscar a %d!\n",cod_disciplina);
    
    arq3 = fopen("disciplinas.txt","r");
    
    if (!arq3){
        printf("Falha ao abrir arquivo disciplinas.\n");
        fclose(arq3);
        return b;
    }
    int i;

    

    char txt[100];

    while(fgets(txt, 100, arq3) != (char*)EOF){
        if(feof(arq3)){
            break;
        }
        char *token = strtok(txt," ");
        
        b.cod_disciplina = (int)atof(token);
        token = strtok(NULL, " ");
        strcpy(b.nome_disciplina, token);
        //printf("verificar se %d = %d!\n",cod_disciplina, b.cod_disciplina);
        if(cod_disciplina==b.cod_disciplina)
        {
          fclose(arq3);
          return b;
        }

    }fclose(arq3);
    
    Disciplina c;
    return c;

}



int carregar_lista(tipo_lista *lista){
    FILE *arq;
    arq = fopen("notas.txt","r");
    elemento  p;
    int cod_aluno;
    int cod_disciplina;

    if (!arq){
        printf("Falha ao abrir arquivo notas.\n");
        return 0;
    }

    int i;
    //printf("inicializa\n");
    inicializa_lista(lista); //reiniciar a lista

    char txt[100];
    char *token;
    const char s[2] = " ";

    while(fgets(txt, 100, arq) != (char*)EOF){
        
        if(feof(arq)){
            break;
        }
        char a[3];
        a[0] = txt[0];
        a[1] = txt[1];
        a[2] = txt[2];
        cod_aluno = (int)atof(a);
        p.aluno=getAluno(cod_aluno);

        a[0] = txt[4];
        a[1] = '\0';
        cod_disciplina = (int)atof(a);
        //printf("Pegando disciplina %d!\n",cod_disciplina);
        p.disciplina=getDisciplina(cod_disciplina);
        //printf("pegou d\n");
        //token = strtok(NULL, s);
        a[0] = txt[6];
        a[1] = txt[7];
        a[2] = txt[8];
        p.nota1=(float)atof(a);
        //token = strtok(NULL, s);
        a[0] = txt[10];
        a[1] = txt[11];
        a[2] = txt[12];
        p.nota2= (float)atof(a);
        //token = strtok(NULL, s);
        a[0] = txt[14];
        a[1] = txt[15];
        a[2] = txt[16];
        p.nota3= (float)atof(a);
        //token = strtok(NULL, s);
        a[0] = txt[18];
        a[1] = txt[19];
        a[2] = txt[20];
        p.nota_recuperacao=(int)atof(a);

        incluir_elemento(lista,tamanho_quantidade_nodos(*lista)+1,p);
    
      };
    fclose(arq);
     return 1;
}



char getConceito(float n1,float n2,float n3,float rec)
{
  float media=0;
  float media2=0;


  media=(n1+n2+n3)/3;
  media2=(n1+n2+n3+rec)/3;

  char rt;
  if(media>=7)
  {
    rt = 'A';
  }
  else
  {
    if(media2>=6)
    {
      rt = 'A';
    }
    else
    {
      rt = 'R';
    }

  }

  return rt;


}

int listar(tipo_lista l){
    if(l.tamanho == 0){
        printf("Lista vazia!\n");
        return 1;
    }
    
    int i;
    elemento e;
    for(i=1;i<=l.tamanho;i++){
        int j = obter_elemento(l, i, &e);
        if(j){
            //printf("%d\t%d\t%s\t%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%c\t%s\n",e.aluno.cod_aluno, e.aluno.serie, e.disciplina.nome_disciplina, e.disciplina.cod_disciplina,e.nota1,e.nota2,e.nota3,e.nota_recuperacao,getConceito(e.nota1, e.nota2, e.nota3, e.nota_recuperacao),e.aluno.nome_aluno);
            printf("\n\nAluno:\nCodigo\tSerie\tNome\n");
            printf("%d\t",e.aluno.cod_aluno);
            printf("%d\t",e.aluno.serie);
            printf("%s",e.aluno.nome_aluno);
            printf("Disciplina:\nCodigo\tNome\n");
            printf("%d\t",e.disciplina.cod_disciplina);
            printf("%s",e.disciplina.nome_disciplina);
            printf("Notas:\nN1\tN2\tN3\tNR\tSituacao\n");
            printf("%.2f\t",e.nota1);
            printf("%.2f\t",e.nota2);
            printf("%.2f\t",e.nota3);
            printf("%.2f\t",e.nota_recuperacao);
            printf("%c\n",getConceito(e.nota1,e.nota2,e.nota3, e.nota_recuperacao));
        }
    }
    return 1;
}

int max_serie(){
  int max = 0;
  Aluno a;
  FILE *arq2;
    
    arq2 = fopen("alunos.txt","r");
    
    if (!arq2){
        printf("Falha ao abrir arquivo aluno para buscar series.\n");
        fclose(arq2);
        return 0;
    }
    int i;

    char txt[100];

    while(fgets(txt, 100, arq2) != (char*)EOF){
        if(feof(arq2)){
            break;
        }
        char *token = strtok(txt," ");
        a.cod_aluno = (int)atof(token);
        token = strtok(NULL, " ");
        a.serie = (int)atof(token);
        token = strtok(NULL, "@");
        strcpy(a.nome_aluno, token);
        if(a.serie > max)
        {
          max = a.serie;
        }
    }fclose(arq2);
    return max;
}

int listar_serie(tipo_lista l,int disc){
  Disciplina d = getDisciplina(disc);

  if(d.cod_disciplina == 0){
    printf("Nao foi localizada disciplina com o codigo %d!\n",disc);
    return;
  }

  int i, k;elemento e;
  for(i=1;i<=max_serie();i++){
    printf("Serie %d: \n",i);
    for(k=0;k<=tamanho_quantidade_nodos(l);k++){
      int j = obter_elemento(l, k, &e);
      if(j){
        if(e.disciplina.cod_disciplina == disc && e.aluno.serie == i){
            printf("%s%.2f\t%.2f\t%.2f\t%.2f\t%c\n",e.aluno.nome_aluno, e.nota1, e.nota2, e.nota3, e.nota_recuperacao, getConceito(e.nota1,e.nota2,e.nota3, e.nota_recuperacao));
        }
      }
    }
  }

}

int max_Disciplina()
{
  int max = 0;
  Disciplina b;
  FILE *arq3;
  arq3 = fopen("disciplinas.txt","r");
    
    if (!arq3){
        printf("Falha ao abrir arquivo disciplinas para verificar tamanho.\n");
        fclose(arq3);
        return 0;
    }
    int i;
    char txt[100];
    while(fgets(txt, 100, arq3) != (char*)EOF){
        if(feof(arq3)){
            break;
        }
        char *token = strtok(txt," ");
        b.cod_disciplina = (int)atof(token);
        token = strtok(NULL, " ");
        strcpy(b.nome_disciplina, token);
        if(max < b.cod_disciplina)
        {
          max = b.cod_disciplina;
        }

    }
    fclose(arq3);
    
    return max;

}

int gravarAluno(Aluno a){
      FILE *arq2;
      arq2 = fopen("alunos.txt","a");
    
      if (!arq2){
        printf("Falha ao abrir arquivo aluno para salvar novo registro.\n");
        fclose(arq2);
        return 0;
      }

      fprintf(arq2,"%d %d %s\n",a.cod_aluno, a.serie, a.nome_aluno);
      fclose(arq2);
      return 1;
}

int gravarNota(elemento e){ 
    FILE *arq;
    arq = fopen("notas.txt","a");

    if (!arq){
        printf("Falha ao abrir arquivo notas para salvar novo registro.\n");
        return 0;
    }
 
    fprintf(arq, "%d %d %.1f %.1f %.1f %.1f\n",e.aluno.cod_aluno, e.disciplina.cod_disciplina, e.nota1, e.nota2, e.nota3, e.nota_recuperacao);
    fclose(arq);

}

int cadAluno(){
  elemento e;

  Aluno a,b;
  b.cod_aluno = 1;
  while(b.cod_aluno != 0){
    printf("\nQual o codigo do aluno? "); 
    fflush(stdin); 
    scanf("%d", &a.cod_aluno);

    b = getAluno(a.cod_aluno);
    if(b.cod_aluno != 0){
        printf("codigo ja cadastrado!\n");
    }
  }

  printf("\nQual o nome do aluno? "); 
  fflush(stdin); 
  gets(a.nome_aluno);

  printf("\nQual a serie do aluno? "); 
  fflush(stdin); 
  scanf("%d", &a.serie);
  e.aluno = a;
  int m = gravarAluno(a);
  if(m == 0){
    return 0;
  }

  int i;
  for(i=1;i<=max_Disciplina();i++){
    Disciplina b = getDisciplina(i);
    printf("Diga se o aluno faz %s1 - sim\n2 - nao\nEscolha: ",b.nome_disciplina);
    int boo;
    scanf("%d",&boo);

    if(boo == 1){
      e.disciplina = b;
      printf("Digite a nota1: ");
      scanf("%f",&e.nota1);
      printf("Digite a nota2: ");
      scanf("%f",&e.nota2);
      printf("Digite a nota3: ");
      scanf("%f",&e.nota3);
      printf("Digite a nota de recuperacao: ");
      scanf("%f",&e.nota_recuperacao);

      gravarNota(e);
    }
  }
 return 0;
}




    