#ifndef __GARLIC_XTRING_H__
#define __GARLIC_XTRING_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NULRETURNUL(EXP) { if ((EXP) == NULL) return NULL;}
#define NULRETURNAG(EXP) { if ((EXP) == NULL) return -1;}
#define NULRETURNV(EXP) { if ((EXP) == NULL) return; }

#define BLOCK_SIZE 1024

extern unsigned char** split_char_orig(unsigned char*, unsigned char, int*);
extern void split_char_orgi_free(unsigned char**, int);
extern unsigned char** split_str_orig(unsigned char*, char*, int*);
extern void split_str_free_orig(unsigned char**, int num);

extern unsigned char** split_char_copy(unsigned char*, unsigned char, int*);
extern void split_char_copy_free(unsigned char**, int num);
extern unsigned char** split_str_copy(unsigned char*, char*, int*);
extern void split_str_copy_free(unsigned char**, int);

extern char* rtrim(char*);
extern char* ltrim(char*);

extern char* str2upper(char*);
extern char* str2lower(char*);
extern char* strevcase(char*);

extern char* strrev(char* src);
extern int strcmp_rev(char*, char*);
extern int strncmp_rev(char*, char*, int);

extern int index_of_str(char*, char*);
extern int last_index_of_str(char*, char*);

extern int replace_char(char*, char, char);
extern int replace_last_char(char*, char, char);
extern char* replace_char_all(char*, char, char);
extern int replace_char_index(char*, char, char, int);
extern int replace_char_last_index(char*, char, char, int);

extern char* replace_str_all(char*, char*, char*);

#endif
