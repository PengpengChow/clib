#ifndef __GARLIC_XTRING_H__
#define __GARLIC_XTRING_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NULRETURNUL(EXP) { if ((EXP) == NULL) return EXP;}
#define NULRETURNAG(EXP) { if ((EXP) == NULL) return -1;}

#define BLOCK_SIZE 1024

extern int replace_char(char*, char, char);
extern int replace_last_char(char*, char, char);
extern char* replace_char_all(char*, char, char);
extern int replace_char_index(char*, char, char, int);
extern int replace_char_last_index(char*, char, char, int);

extern char* replace_str_all(char*, char*, char*);

#endif
