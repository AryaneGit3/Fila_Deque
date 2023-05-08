#include <stdio.h>
#include <stdlib.h>

/*Criar funções para:
Inserir no início
Remover no fim
Mostrar a lista invertida [do fim para o início]
Quantidade de elementos [length]*/

typedef int tdado;

typedef struct no{
	tdado dado;
	struct no *prox; 
	struct no *ant;
}tno;

typedef struct{
	tno *ini,*fim; // head e tail,  tno eh um nó da deque 
				   // ponteiros para os nós seguintes e anteriores
}tdeque;

//-------------------------------

void inicializa(tdeque *minhaDeque){ // inicializando estrutura 
	minhaDeque->ini = NULL; // quando nulos = deque vazia
	minhaDeque->fim = NULL;
}

//------------------------------

int addFirst(tdeque *minhaDeque, tdado novoDado) { // add no inicio 
	tno *novoNo = malloc(sizeof(tno)); // alocando espaço p/ novo no 
	if(novoNo == NULL) {
		return 0; // alocação bem-sucedida 
	}
	novoNo->dado = novoDado;
	novoNo->prox = minhaDeque->ini;
	novoNo->ant = NULL;
	if(minhaDeque->ini == NULL){ // verifica se a deque estava vazia antes da inserçao 
		minhaDeque->ini = novoNo; // inicio e fim passa valer novoNo
		minhaDeque->fim = novoNo;
	}
	else {
		minhaDeque->ini->ant = novoNo;
	}
	minhaDeque->ini = novoNo;
	return 1; // inserçao concluida
}

//------------------------------

int addLast(tdeque *minhaDeque, tdado novoDado){
	tno *novoNo = malloc(sizeof(tno)); // alocando espaço para novoNo
	if(novoNo==NULL){  // memoria ta cheia
	  return 0;
	}
	novoNo->dado = novoDado;
	novoNo->prox = NULL;
	novoNo->ant = minhaDeque->fim;
	if(minhaDeque->ini==NULL) { // testando se esta vazia
	  minhaDeque->ini = novoNo;
	  minhaDeque->fim = novoNo;
	}
	else{
	  minhaDeque->fim->prox = novoNo;
	}
	minhaDeque->fim = novoNo;    	
	return 1; 
}

//---------------------------------------------

tdado removeFirst(tdeque *minhaDeque){
	tdado retorno = minhaDeque->ini->dado; //pegando o dado armazenado no no
	tno *aux = minhaDeque->ini; //guardando o endereco para limpar a memoria
	minhaDeque->ini = minhaDeque->ini->prox; //removendo, deslocando o apontamento
	if(minhaDeque->ini == NULL) { //era o ultimo elemento
	   minhaDeque->fim = NULL;
	}
	else{
		minhaDeque->ini->ant = NULL;
	}  
	    // Alteracao da DEQUE,o anterior do inicio aponta para NULL
	free(aux); // limpando a memoria
	return retorno; // retorno o dado removido
}

//---------------------------------------------

tdado removeLast(tdeque *minhaDeque) {
	tdado retorno = minhaDeque->fim->dado;
	tno *aux = minhaDeque->fim;
	minhaDeque->fim = minhaDeque->fim->ant;
	if(minhaDeque->fim == NULL) {
		minhaDeque->ini == NULL;
	}
	else {
		minhaDeque->fim->prox = NULL;
	}
	free(aux);
	return retorno;
}

//----------------------

int isEmpty(tdeque minhaDeque){
	if(minhaDeque.ini == NULL) // se estiver vazio ini e fim ==NULL
	  return 1;
	else
	  return 0;  
}

//-----------------------------

void printList(tdeque minhaDeque){
	while(minhaDeque.ini != NULL){
		printf("%d - ",minhaDeque.ini->dado); // mostro o dado
		minhaDeque.ini = minhaDeque.ini->prox; // deslocando para o prox
	}// fim while
	printf("\n");
}

//-----------------------------

void printInvertida(tdeque minhaDeque){ // alterar
	while(minhaDeque.ini != NULL){
		printf("<- %x| %d [%x] | %x ->\n ",
		        minhaDeque.fim->ant, minhaDeque.fim->dado, minhaDeque.fim , minhaDeque.fim->prox); // mostro o dado
		minhaDeque.fim = minhaDeque.fim->ant; // deslocando para o anterior
	}// fim while
	printf("\n");
}

//-----------------------------

void mostraEndereco(tdeque minhaDeque){
	while(minhaDeque.ini != NULL){
		printf("<- %x| %d [%x] | %x ->\n ",
		        minhaDeque.ini->ant, minhaDeque.ini->dado, minhaDeque.ini , minhaDeque.ini->prox); // mostro o dado
				minhaDeque.ini = minhaDeque.ini->prox; // deslocando para o prox
	}// fim while
	printf("\n");
}

//-----------------------------

int length(tdeque minhaDeque) {
	int qtd = 0;
	while(minhaDeque.ini != NULL) {
		minhaDeque.ini = minhaDeque.ini->prox;
		qtd++;
	}
	return qtd;
}

//-----------------------------

int menu(){
	int op;
	printf("*** Estrutura de Dados I ***\n");
	printf("*** Fila Encadeada ***\n");
	printf("1-Adicionar no Fim (Inserir)\n");
	printf("2-Remover do Inicio  (Remover)\n");
	printf("3-Primeiro e ultimo da fila\n");
	printf("4-Mostrar a Fila Inversa\n");
	printf("5-Adicionar no inicio (Inserir)\n");
	printf("6-Remover do Fim (Remover)\n");
	printf("7-Mostrar o tamanho da lista\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}

//--------------------

int main(){
	int op;
	tdado novoDado;
	tdeque minhaDeque;
	inicializa(&minhaDeque);
	do{
		printf("Ini:%x  Fim:%x\n", minhaDeque.ini, minhaDeque.fim);
		//printList(minhaDeque);
		mostraEndereco(minhaDeque);
		op = menu();
		switch(op){
			case 1: 
				printf("Valor para inserir:");
				scanf("%d",&novoDado);
				if(addLast(&minhaDeque,novoDado)) { // ==1
				   printf("Valor inserido:)\n");
				}
				else{
				   printf("Fila cheia :(\n");   
				}
				break;
			case 2: 
				if(!isEmpty(minhaDeque)) {
				    novoDado = removeFirst(&minhaDeque);
				    printf("Removido: %d\n",novoDado);
				}// fim if
				else {
					printf("Fila vazia :(\n");
				}
			   break;
			case 3: 
				if(!isEmpty(minhaDeque)){
				      //printf("Inicio: %d\n",firstList(minhaDeque));
				      //printf("Fim: %d\n",lastList(minhaDeque));
			    }// fim if 
				else {
					printf("Fila vazia :(\n"); 
				}
				break;
			case 4: 
				if(!isEmpty(minhaDeque)) {
			 		printInvertida(minhaDeque);
			 	}
				break;
			case 5:
				printf("Valor para inserir: ");
				scanf("%d", &novoDado);
				if(addFirst(&minhaDeque, novoDado)) {
					printf("Valor inserido!\n");
				} 
				else {
					printf("Fila cheia :(\n");
				}
				break;
			case 6:
				if(!isEmpty(minhaDeque)) {
					novoDado = removeLast(&minhaDeque);
					printf("Removido: %d\n", novoDado);
				}
				else {
					printf("Fila vazia! :(\n");
				}
				break;
			case 7:
				int quant = length(minhaDeque);
				printf("O tamanho atual da lista eh: %d", qtd);
				break;
			case 0: 
				printf("Saindo...");  
				break;	
		}// fim switch
		getch();
		system("cls"); 
	}while(op!=0);
}// fim main
