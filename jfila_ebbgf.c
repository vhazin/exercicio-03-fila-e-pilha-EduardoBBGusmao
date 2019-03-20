#include<stdio.h>
#include<stdlib.h>

/* Ainda não ta rodando no SPOJ */

typedef struct node {
	int valor;
	struct node* next;	
} Node;
void deletar();
void crialista();
int main() {
	int numentradas, input, num_del;
	scanf("%d", &numentradas);
	Node* lista = (Node*)malloc(sizeof(Node));
	
	scanf("%d", &input);
	
	lista -> valor = input;
	lista -> next = NULL;
	
	for (int i = 1; i < numentradas; i++ ) {
		scanf("%d", &input);
		crialista(lista, input);
	}


	scanf("%d", &num_del);
	for (int i = 0; i < num_del; ++i){
		scanf("%d", &input);
		deletar(lista, input, numentradas);		
	}


	Node* last = (Node*)malloc(sizeof(Node));
	last = lista;
    while (lista!= NULL){
       printf("%d ", lista ->valor);
       lista = lista ->next;
	}
	
}

void crialista(Node *lista, int input){
		
	Node *atual = (Node*)malloc(sizeof(Node));
	atual -> valor = input;
	atual -> next = NULL; 
	
	Node *last = (Node*)malloc(sizeof(Node));
	
	last = lista;
	while(last->next != NULL){
		last = last ->next;
	}
	last -> next = atual;

}
void deletar(Node* lista, int input, int numentradas){
	Node *deletado = (Node*)malloc(sizeof(Node));
	Node *anterior = (Node*)malloc(sizeof(Node));
	deletado = lista;
	for (int i = 0; i < numentradas; ++i){
		if(deletado -> valor == input)
			break;
		anterior = deletado;
		deletado = deletado -> next;
	}
	if(deletado -> valor == lista -> valor){
		anterior = deletado;
		deletado = deletado -> next;
		anterior -> valor = deletado -> valor;
		anterior -> next = deletado ->next;
		anterior = deletado;

	}
	else{
		if (deletado-> next == NULL){
			anterior -> next = NULL;
		} else{
			deletado = deletado -> next;
			anterior -> next = (deletado);
		}
	}
}
