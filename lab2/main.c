#include <stdio.h>
#include <stdlib.h>
#include "lib/stack_vector.h"

 
int main(){
	char *data = NULL; 
	data =(char *)malloc(1 * sizeof(char));
	Stack *stack = init_stack(3);
	char a = 'Z', b = 'X';
	push(stack, a);
	push(stack, b);
	print_stack(stack);

	char x = 'Y';
	push(stack, x);
	pop(stack, data);
	print_stack(stack);
	free_stack(stack);
	printf("data: %c\n", *data);
}
