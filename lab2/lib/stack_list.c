#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stack_list.h"



Stack *init_stack(){
	Stack *stack = (Stack *)malloc(1 * sizeof(Stack));

	if(stack == NULL) return NULL;
	return stack;
}


Node *add_node(char data){
	Node *node = (Node *)malloc(1 * sizeof(Node));

	if(node == NULL) return NULL; // null

	node->next = NULL;
	node->data = data;

	return node;
}


int push(Stack *stack, char data){
	Node *node = add_node(data);

	if(node == NULL) return errno; // null

	node->data = data;

	node->next = stack->top;
	stack->top = node;
	return 0;
}


int pop(Stack *stack){


	if(stack->top == NULL) return errno; // stack is empty

	if(stack->top->next != NULL){
		stack->top = stack->top->next;
		}
	else{
		stack->top = NULL; // last element
		}

		return 0; //success
		
}


int free_stack(Stack *stack){
	Node *node = stack->top;

	if(node == NULL) return errno; //stakc is empty
	
	Node *tmp = node;

	while(node != NULL){
		tmp = node->next;

		free(node);
		node = tmp;
	}
	return 0;
}


int print_stack(Stack *stack){
	printf("Stack:\t");

	Node *node = stack->top;
	if(node == NULL) return errno; //stack is empty
	while(node != NULL){
		printf("%c", node->data);
		node = node->next;
	}	

	printf("\n");
	return 0;
}
