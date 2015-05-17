#ifndef __GARLIC_STACK_H__
#define __GARLIC_STACK_H__

#include <garlic/list.h>

typedef LIST STACK;
typedef LNODE STACKNODE;

extern void stack_init(STACK*);
extern STACKNODE* stack_push(STACK*, void*);
extern void* stack_pop(STACK*);
extern void* stack_top(STACK*);
extern int stack_isempty(STACK*);

#endif
