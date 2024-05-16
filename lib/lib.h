#ifndef LIB_H
#define LIB_H

typedef struct stack {
  char *items;
  int top;
} Stack;


int is_full(Stack *stack, int max_size);
int is_empty(Stack *stack);

void init(Stack *stack);
void push(Stack *stack, char value, int max_size);
char pop(Stack *stack);
void print_stack(Stack *stack);
void get_items(char *line);

void free_stack(Stack *stack);

#endif
