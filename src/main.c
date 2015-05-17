#include <garlic/stack.h>

int comp(char* s1, char* s2) {
	return strcmp(s1, s2) > 0 ? -1 : 1;
}

int comp_int(int* i1, int* i2) {
	return *i1 - *i2;
}

int main(int argc, char** argv) {
	int i = 0;
	int n = 0;

	int* array[10] = {};

printf("before:\n");
	for (i = 0; i < 10; i ++) {
		int * p = calloc(1, sizeof(int));
		*p = rand()%10;
		array[i] =  p;
		printf("%02d: [%d]\n", i, *(array[i]));
	}

printf("max[%d]\n", array_max(array, 10, comp_int));
	/* array_sort_bubble(array, 10, comp_int);

printf("after:\n"); */
	for (i = 0; i < 10; i ++) {
		printf("%02d: [%d]\n", i, *(array[i]));
	}

#if 0
	STACK stack;
	char buffer[1024] = {};
	char* pbuffer = NULL;
	LNODE* p = NULL;

	LIST list;
	list_init(&list);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 10);

	pbuffer = calloc(1, 50);
	sprintf(pbuffer, "hello %03d", i ++);
	list_insert(&list, pbuffer, 0);

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

	pbuffer = calloc(1, 50);
	n = 3;
	sprintf(pbuffer, "insert  %03d", n);
	list_insert(&list, pbuffer, n);

printf("before:\n");
	list_traver(&list);

	list_sort_bubble(&list, comp);

printf("\nafter:\n");
	list_traver(&list);

	/* p = list_find(&list, "hello 00-", strcmp);
	printf("lcaotion of [%s] is [%d]\n", list_getdata(p), list_locate(&list, p));


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


#endif
	return 0;
}
