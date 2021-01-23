typedef struct nodo* ptr_nodo;
struct nodo{
				elemento elem;
				ptr_nodo prox;
};

typedef struct {
				ptr_nodo lista;
				int tamanho;
			} lista_encadeada;

typedef lista_encadeada tipo_lista;


/* ImplementaÃ§Ãµes */

int tamanho(lista_encadeada le) {
	return le.tamanho;
}


int obter_elemento(lista_encadeada le, int i, elemento *e) {
	int j; 
	ptr_nodo pnodo;

	if ((i <= le.tamanho) && (i > 0)) {
		pnodo = le.lista;
		for(j=2;j<=i;j++)
			pnodo = pnodo->prox;
		*e = pnodo->elem;
      	return 1;
	}
	else {
		*e = VL_NULO;
      return 0;
	}
}


void inicializa_lista(lista_encadeada *le) {
	le->tamanho = 0;
	le->lista = NULL;
}


int incluir_elemento(lista_encadeada *le, int i, elemento e) {
	int j; 
    ptr_nodo pnodo_incluido, pnodo_anterior;

  	if ((i <= le->tamanho+1) && (i > 0)) {
      pnodo_incluido = (ptr_nodo)malloc(sizeof(struct nodo));
    	if (pnodo_incluido == NULL)
			return 0;   /* FALTA MEMÃ“RIA */
    	else {
       		pnodo_incluido->elem = e;
       		if (i == 1) {
       			pnodo_incluido->prox = le->lista;
          		le->lista = pnodo_incluido;
       		}
       		else {
          		pnodo_anterior = le->lista;
               		for (j=2; j<i; j++)
				pnodo_anterior = pnodo_anterior->prox;
          		pnodo_incluido->prox = pnodo_anterior->prox;
          		pnodo_anterior->prox = pnodo_incluido;
				}
       		le->tamanho++;
       		return 1;
    	}
   }
  else
    	return 0;    /* POSIÃ‡ÃƒO INVÃLIDA */
}


int alterar_elemento(lista_encadeada *le, int i, elemento e) {
	int j; ptr_nodo pnodo;
  	if ((i <= le->tamanho) && (i > 0)) {
     	pnodo = le->lista;
		for (j=2; j<=i;j++)
			pnodo = pnodo->prox;
      	pnodo->elem = e;
      	return 1;
	}
  	else
    		return 0; /* POSIÃ‡ÃƒO INVÃLIDA */
}


int excluir_elemento(lista_encadeada *le, int i) {
	 int j; ptr_nodo pnodo_excluido, pnodo_anterior;
  	if ((i <= le->tamanho) && (i > 0)) {
    		if (i == 1) {
       			pnodo_excluido = le->lista;
       			le->lista = pnodo_excluido->prox;
		}
    		else {
       			pnodo_anterior = le->lista;
               		for (j=2;j<i; j++)
			pnodo_anterior =  pnodo_anterior->prox;
       			pnodo_excluido = pnodo_anterior->prox;
       			pnodo_anterior->prox = pnodo_excluido->prox;
		}
    		free(pnodo_excluido);
    		le->tamanho = le->tamanho - 1;
    		return 1;
	}
  	else
    		return 0; /* POSIÃ‡ÃƒO INVÃLIDA */
}

int inverte(tipo_lista *l){
    if(l->tamanho == 0){
        printf("Lista vazia!\n");
        return 1;
    }

    elemento *v = malloc(sizeof(elemento));
    tipo_lista temporaria;
    inicializa_lista(&temporaria);
    int i = 0;
    for(i = 1; i<= l->tamanho; i++){
        obter_elemento(*l,(l->tamanho+1)-i,v); //pegar o ultimo
        incluir_elemento(&temporaria,i,*v);
    }

    free(l->lista);
    l->lista = temporaria.lista;
}

int tamanho_quantidade_nodos(lista_encadeada le){
	int j = 0;
	
	if(le.lista == NULL)
		return j;

	
	while(le.lista != NULL){
		le.lista = le.lista->prox;
		j++;
	}
	return j;
}

