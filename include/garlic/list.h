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

struct list_header {
	LNODE* head;
	LNODE* tail;
};
typedef struct list_header LHEADER;

extern void list_init(LHEADER*);
extern LNODE* list_rpush(LHEADER*, void*);
extern LNODE* list_lpush(LHEADER*, void*);
extern void* list_rpop(LHEADER*);
extern void* list_lpop(LHEADER*);
extern void list_free(LHEADER*, void (*)(void*));

#endif
