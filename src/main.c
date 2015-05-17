#include <garlic/stack.h>

int main(int argc, char** argv) {
	STACK stack;
	char buffer[1024] = {};
	char* pbuffer = NULL;
	LNODE* p = NULL;
	int i = 0;
	int n = 0;

	LIST list;
	list_init(&list);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 10);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 10);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 10);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 10);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 1);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 1);

printf("list size[%d]\n", list_size(&list));
	pbuffer = calloc(1, 50);
	n = 6;
	sprintf(pbuffer, "insert  %03d", n);
	list_insert(&list, pbuffer, n);

	list_traver(&list);

	/* p = list_find(&list, "hello 00-", strcmp);
	printf("lcaotion of [%s] is [%d]\n", list_getdata(p), list_locate(&list, p));


/*
	stack_init(&stack);

	for (i=0; i<10; i ++) {
		pbuffer = calloc(1, 50);
		sprintf(pbuffer, "hello %03d", i);
		stack_push(&stack, pbuffer);
	}
	list_traver(&stack);
printf("=========================================\n");

	stack_pop(&stack);
	stack_pop(&stack);
	stack_pop(&stack);
	stack_pop(&stack);
	stack_pop(&stack);

	list_traver(&stack);
*/


	return 0;
}
