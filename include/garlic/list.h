#ifndef __GARLIC_LIST_H__
#define __GARLIC_LIST_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct list_node {
	struct list_node* pnext;
	void* pdata;
};

typedef struct list_node LNODE;

struct list {
	LNODE* head;
	LNODE* tail;
	int size;
};
typedef struct list LIST;

extern void list_init(LIST*);
extern int list_size(LIST*);
extern void* list_getdata(LNODE*);

extern LNODE* list_rpush(LIST*, void*);
extern LNODE* list_lpush(LIST*, void*);
extern void* list_rpop(LIST*);
extern void* list_lpop(LIST*);
extern void list_free(LIST*, void (*)(void*));
extern int list_isempty(LIST*);
extern int list_locate(LIST*, LNODE*);
extern LNODE* list_find(LIST*, void* pdata, int (*)(void*, void*));

extern LNODE* list_insert(LIST*, void*, int);
extern void* list_remove(LIST*, int);

#endif
