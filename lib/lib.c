#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(Stack *stack) {
  stack->top = 0;
}


void free_stack(Stack *stack){
    free(stack -> items);
}


void push(Stack *stack, char value, int max_size){
	if(is_full(stack, max_size)){
		printf("Стек переполнен\n");
		return;
	}
	stack->items[stack->top++] = value;
}


char pop(Stack *stack){
	if(is_empty(stack)){
		printf("Стек пуск\n");
		return 0;
	}
	return stack->items[stack->top--];
}


void print_stack(Stack *stack){
	if(!is_empty(stack)){
		for(int i = stack->top; i>0; i--){
			printf("%c\n", stack->items[i]);
		}
	}
	else{
		printf("Стек пуст\n");
		return;
	}
}


int is_empty(Stack *stack){
	if(!stack->top){
		return 1;
	}
	else{
		return 0;
	}
}

int is_full(Stack *stack, int max_size){
	if(stack->top == max_size){
		return 1;
	}
	else{
		return 0;
	}
}

void get_items(char *line){
	int size = 0;
	int item;
	printf("Введите инфиксное выражение: ");
	while( (item = getchar() ) != EOF ){
	
		line = (char *)realloc(line, (size+1)*sizeof(char));
		line[size++] = item;
	}
	line = (char *)realloc(line, (size+1)*sizeof(char));
	line[size] = '\0';
}
