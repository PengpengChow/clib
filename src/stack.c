#include <garlic/stack.h>

void stack_init(STACK* stack) {
	list_init(stack);
}

int stack_size(STACK* stack) {
	return list_size(stack);
}

STACKNODE* stack_push(STACK* stack, void* pdata) {
	return list_lpush(stack, pdata);
}

void* stack_pop(STACK* stack) {
	return list_lpop(stack);
}

void* stack_top(STACK* stack) {
	return stack->head->pdata;
}

int stack_isempty(STACK* stack) {
	return list_isempty(stack);
}
