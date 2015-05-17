#include <garlic/list.h>

void list_init(LIST* list) {
	bzero(list, sizeof(LIST));
}

int list_size(LIST* list) {
	return list->size;
}

LNODE* list_rpush(LIST* list, void* pdata) {
	LNODE* pnode = NULL;

	pnode = calloc(1, sizeof(LNODE));
	pnode->pdata = pdata;

	if (list->head == NULL)
		list->head = pnode;

	if (list->tail != NULL)
		list->tail->pnext = pnode;
	list->tail = pnode;
	list->size ++;

	return pnode;
}

LNODE* list_lpush(LIST* list, void* pdata) {
	LNODE* pnode = NULL;

	pnode = calloc(1, sizeof(LNODE));
	pnode->pdata = pdata;

	if (list->tail == NULL)
		list->tail = pnode;

	pnode->pnext = list->head;
	list->head = pnode;
	list->size ++;

	return pnode;
}

void* list_rpop(LIST* list) {
	LNODE* node = NULL;
	void* pdata = NULL;
	node = list->head;

	if (list->tail == NULL)
		return NULL;

	if (node == list->tail) {
		pdata = node->pdata;
		free(node);
		list->head = list->tail = NULL;
		return pdata;
	}
	
	while (node->pnext != list->tail) {
		node = node->pnext;
	}
	pdata = node->pnext->pdata;
	list->tail = node;

	free(node->pnext);
	node->pnext = NULL;
	list->size --;
	return pdata;
} 

void* list_lpop(LIST* list) {
	void* pdata = NULL;
	LNODE* node = NULL;

	if (list->head == NULL) return NULL;

	if (list->head == list->tail) {
		node = list->head;
		pdata = node->pdata;
		free(node);
		list->head = list->tail = NULL;
		return pdata;
	}

	pdata = list->head->pdata;
	node = list->head;
	list->head = node->pnext;
	free(node);

	list->size --;

	return pdata;
}

void list_free(LIST* list, void (*node_free)(void*)) {
	LNODE* node = NULL;

	while (list->head != NULL) {
		node = list->head;
		list->head = node->pnext;

		if (node_free != NULL)
			(*node_free) (node->pdata);
		list->size --;

		free(node);
	}

	list->tail = list->head;
}

int list_isempty(LIST* list) {
	return list->size == 0 ? 1 : 0;
}

LNODE* list_insert(LIST* list, void* pdata, int pos) {
	LNODE* pnode = NULL;
	int i = 0;
	LNODE* p = NULL;
	LNODE* pre = NULL;

	if (pos == 0) {
		return list_lpush(list, pdata);
	}

	if (pos >= list->size) {
		return list_rpush(list, pdata);
	}

	pnode = calloc(1, sizeof(LNODE));
	pnode->pdata = pdata;

	if (list->head == NULL || list->tail == NULL) {
		list->head = list->tail = pnode;
		list->size ++;
		return pnode;
	}

	for (pre = p = list->head; p != list->tail && i <= pos; p = p->pnext, i ++) {
		pre = p;
	}

	pnode->pnext = pre->pnext;
	pre->pnext = pnode;
	list->size ++;

	return pnode;
}

void* list_getdata(LNODE* node) {
	if (node == NULL) return NULL;
	return node->pdata;
}

int list_locate(LIST* list, LNODE* node) {
	int i = 0;
	LNODE* p = NULL;

	if (node == NULL) return -1;

	for (i=0, p=list->head; p != NULL; p = p->pnext, i ++) {
		if (node == p) return i;
	}

	return -1;
}

LNODE* list_find(LIST* list, void* pdata, int (* comp)(void*, void*)) {
	LNODE* p = NULL;

	if (list == NULL) return NULL;

	for (p=list->head; p != NULL; p = p->pnext) {
		if (!(*comp)(p->pdata, pdata)) return p;
	}

	return NULL;
}

void* list_remove(LIST* list, int pos) {
	LNODE* p = NULL;
	LNODE* pre = NULL;
	void* pdata = NULL;
	int i = 0;

	if (list == NULL) return NULL;
	if (pos >= list->size - 1 || pos < 0) return NULL;

	if (pos == 0) return list_lpop(list);
	if (pos == list->size-1) return list_rpop(list);

	for (pre = p = list->head; p->pnext != list->tail && i <pos; p = p->pnext, i ++) {
    pre = p;
  }

	pre->pnext = p->pnext;
	pdata = p->pdata;

	free(p);

	return pdata;
}

void list_traver(LIST* list) {
	LNODE* p = NULL;
	int i = 0;
	p = list->head;
	
	while (p != NULL) {
		printf("%d: [%s]\n", i ++, (char*) p->pdata);
		p = p->pnext;
	}
}

/*
int main (int argc, char** argv) {
	LIST header;
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
*/
