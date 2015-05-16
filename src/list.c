#include <garlic/list.h>

void list_init(LHEADER* header) {
	bzero(header, sizeof(LHEADER));
}

LNODE* list_rpush(LHEADER* header, void* pdata) {
	LNODE* pnode = NULL;

	pnode = calloc(1, sizeof(LNODE));
	pnode->pdata = pdata;

	if (header->head == NULL)
		header->head = pnode;

	if (header->tail != NULL)
		header->tail->pnext = pnode;
	header->tail = pnode;

	return pnode;
}

LNODE* list_lpush(LHEADER* header, void* pdata) {
	LNODE* pnode = NULL;

	pnode = calloc(1, sizeof(LNODE));
	pnode->pdata = pdata;

	if (header->tail == NULL)
		header->tail = pnode;

	pnode->pnext = header->head;
	header->head = pnode;

	return pnode;
}

void* list_rpop(LHEADER* header) {
	LNODE* node = NULL;
	void* pdata = NULL;
	node = header->head;

	if (header->tail == NULL)
		return NULL;

	if (node == header->tail) {
		pdata = node->pdata;
		free(node);
		header->head = header->tail = NULL;
		return pdata;
	}
	
	while (node->pnext != header->tail) {
		node = node->pnext;
	}
	pdata = node->pnext->pdata;
	header->tail = node;

	free(node->pnext);
	node->pnext = NULL;
	return pdata;
} 

void* list_lpop(LHEADER* header) {
	void* pdata = NULL;
	LNODE* node = NULL;

	if (header->head == NULL) return NULL;

	if (header->head == header->tail) {
		node = header->head;
		pdata = node->pdata;
		free(node);
		header->head = header->tail = NULL;
		return pdata;
	}

	pdata = header->head->pdata;
	node = header->head;
	header->head = node->pnext;
	free(node);

	return pdata;
}

void list_free(LHEADER* header, void (*node_free)(void*)) {
	LNODE* node = NULL;

	while (header->head != NULL) {
		node = header->head;
		header->head = node->pnext;

		if (node_free != NULL)
			(*node_free) (node->pdata);

		free(node);
	}

	header->tail = header->head;
}

void list_traver(LHEADER* header) {
	LNODE* p = NULL;
	int i = 0;
	p = header->head;
	
	while (p != NULL) {
		printf("%d: [%s]\n", i ++, (char*) p->pdata);
		p = p->pnext;
	}
}

int main (int argc, char** argv) {
	LHEADER header;
	int i = 0;
	list_init(&header);

	char* p = NULL;

	for (i=0; i<10; i ++) {
		p = calloc(20, 1);
		sprintf(p, "this is %03d", i);
		list_rpush(&header, p);
	}

	p = calloc(20, 1);
	sprintf(p, "this is %03d", i ++);
	list_lpush(&header, p);

	p = calloc(20, 1);
	sprintf(p, "this is %03d", i ++);
	list_lpush(&header, p);

	p = calloc(20, 1);
	sprintf(p, "this is %03d", i ++);
	list_lpush(&header, p);

	p = calloc(20, 1);
	sprintf(p, "this is %03d", i ++);
	list_lpush(&header, p);

	printf("rpop[%s]\n", list_rpop(&header));
	printf("lpop[%s]\n", list_lpop(&header));

	list_free(&header, free);

	p = calloc(20, 1);
	sprintf(p, "this is %03d", i ++);
	list_lpush(&header, p);

	list_traver(&header);

	return 0;
}
