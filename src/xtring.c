#include <garlic/xtring.h>

void* memcopy(void* src, long size) {
	void* p = NULL;
	p = calloc(size, 1);
	memcpy(p, src, size);

	return p;
}

unsigned char** split_char_orig(unsigned char* src, unsigned char needle, int* num) {
	char* p = NULL;
	unsigned char** array = NULL;
	int size = 0;
	int n = 0;
	long src_len = 0;

	NULRETURNUL(src);

	src_len = strlen(src);
	size = (src_len > BLOCK_SIZE ? src_len : BLOCK_SIZE)*sizeof(char*);
	array = malloc(size);
	bzero(array, size);

	array[n ++] = src;
	for (p = src; *p != '\0'; p ++) {
		if (n*sizeof(char*) >= size) {
			size += BLOCK_SIZE*sizeof(char*);
			array = realloc(array, size);
		}
		if (*p == needle) {
			array[n ++] = p + 1;
			*p = '\0';
		}
	}

	*num  = n;
	return array;
}

void split_char_orig_free(unsigned char** array, int num) {
	int i = 0;

	for (i=0; i<num; i++)
		array[i] = NULL;

	free(array);
	array = NULL;
}

unsigned char** split_str_orig(unsigned char* src, char* needle, int* num) {
	char* p = NULL;
	unsigned char** array = NULL;
	int size = 0;
	int n = 0;
	long src_len = 0;

	NULRETURNUL(src);

	src_len = strlen(src);
	size = (src_len > BLOCK_SIZE ? src_len : BLOCK_SIZE)*sizeof(char*);
	array = malloc(size);
	bzero(array, size);

	array[n ++] = src;
	for (p = src; *p != '\0'; p ++) {
		if (n*sizeof(char*) >= size) {
			size += BLOCK_SIZE*sizeof(char*);
			array = realloc(array, size);
		}
		if (!strncmp(p, needle, strlen(needle))) {
			array[n ++] = p + strlen(needle);
			*p = '\0';
		}
	}

	*num  = n;
	return array;
}

void split_str_orig_free(unsigned char** array, int num) {
	int i = 0;

	for (i=0; i<num; i++)
		array[i] = NULL;

	free(array);
	array = NULL;
}

unsigned char** split_char_copy(unsigned char* src, unsigned char needle, int* num) {
	char* p = NULL;
	char* copy = NULL;
	unsigned char** array = NULL;
	int size = 0;
	int n = 0;
	long copy_len = 0;

	NULRETURNUL(src);

	copy = memcopy(src, strlen(src) + 1);

	copy_len = strlen(copy);
	size = (copy_len > BLOCK_SIZE ? copy_len : BLOCK_SIZE)*sizeof(char*);
	array = malloc(size);
	bzero(array, size);

	array[n ++] = copy;
	for (p = copy; *p != '\0'; p ++) {
		if (n*sizeof(char*) >= size) {
			size += BLOCK_SIZE*sizeof(char*);
			array = realloc(array, size);
		}
		if (*p == needle) {
			array[n ++] = p + 1;
			*p = '\0';
		}
	}

	*num  = n;
	return array;
}

void split_char_copy_free(unsigned char** array, int num) {
	int i = 0;

	if (array[0] != NULL) free(array[0]);
	for (i=0; i<num; i++)
		array[i] = NULL;

	free(array);
	array = NULL;
}

unsigned char** split_str_copy(unsigned char* src, char* needle, int* num) {
	char* p = NULL;
	char* copy = NULL;
	unsigned char** array = NULL;
	int size = 0;
	int n = 0;
	long copy_len = 0;

	NULRETURNUL(src);

	copy = memcopy(src, strlen(src) + 1);
	copy_len = strlen(copy);
	size = (copy_len > BLOCK_SIZE ? copy_len : BLOCK_SIZE)*sizeof(char*);
	array = malloc(size);
	bzero(array, size);

	array[n ++] = copy;
	for (p = copy; *p != '\0'; p ++) {
		if (n*sizeof(char*) >= size) {
			size += BLOCK_SIZE*sizeof(char*);
			array = realloc(array, size);
		}
		if (!strncmp(p, needle, strlen(needle))) {
			array[n ++] = p + strlen(needle);
			*p = '\0';
		}
	}

	*num  = n;
	return array;
}

void split_str_copy_free(unsigned char** array, int num) {
	int i = 0;

	if (array[0] != NULL) free(array[0]);
	for (i=0; i<num; i++)
		array[i] = NULL;

	free(array);
	array = NULL;
}

char* rtrim(char* src) {
	char* p = NULL;
	NULRETURNUL(src);

	for (p = src + strlen(src) - 1; *p < '\x21'; p --)
		if (*p < 0x21) *p = '\0';

	return src;
}

char* ltrim(char* src) {
	char* p = NULL;
	NULRETURNUL(src);

	for (p = src; *p < '\x21'; p ++)
		*p = '\0';

	return p;
}

char* str2upper(char* src) {
	char* p = NULL;
	NULRETURNUL(src);

	for (p = src; *p != '\0'; p ++)
		*p = toupper(*p);

	return src;
}

char* str2lower(char* src) {
	char* p = NULL;
	NULRETURNUL(src);

	for (p = src; *p != '\0'; p ++)
		*p = tolower(*p);

	return src;
}

char* strevcase(char* src) {
	char* p = NULL;
	NULRETURNUL(src);

	for (p = src; *p != '\0'; p ++) {
		if (*p > 'A' && *p < 'Z')
			*p = tolower(*p);
		else *p = toupper(*p);
	}

	return src;
}

char* strrev(char* src) {
	char* bp = NULL;
	char* ep = NULL;
	char c;

	NULRETURNUL(src);

	for (bp = src, ep = src + strlen(src) - 1; ; bp ++, ep --) {
		if (bp >= ep) break;
		c = *bp;
		*bp = *ep;
		*ep = c;
	}

	return src;
}

int strcmp_rev(char* s1, char* s2) {
	char* p1;
	char* p2;
	int d = 0;

	p1 = s1, p2 = s2;

	for (p1 = s1 + strlen(s1), p2 = s2 + strlen(s2);
			p1 >= s1 && p2 >= s2; p1 --, p2 --) {
		d = *p1 - *p2;
		if (d != 0) return d > 0 ? 1 : -1;
	}

	if (strlen(s1) == strlen(s2)) return 0;
	if (strlen(s1) > strlen(s2)) return 1;
	return -1;
}

int strncmp_rev(char* s1, char* s2, int n) {
	char* p1;
	char* p2;
	int d = 0;
	int cnt = 0;

	p1 = s1, p2 = s2;

	for (cnt = 0, p1 = s1 + strlen(s1), p2 = s2 + strlen(s2);
			cnt < n && p1 >= s1 && p2 >= s2; p1 --, p2 --, cnt ++) {
		d = *p1 - *p2;
		if (d != 0) return d > 0 ? 1 : -1;
	}

	return 0;
}

int index_of_str(char* src, char* seed) {
	char* p = NULL;
	int seed_len = 0;
	NULRETURNAG(src);

	seed_len = strlen(seed);
	for (p = src; *p != '\0'; p ++) {
		if (!strncmp(p, seed, seed_len))
			return p - src;
	}

	return -1;
}

int last_index_of_str(char* src, char* seed) {
	char *p = NULL;
	int seed_len = 0;

	NULRETURNAG(src);
	seed_len = strlen(seed);
	
	for (p = src + strlen(src) - 1; p >= src; p --) {
		if (!strncmp(p, seed, seed_len)) return p - src;
	}

	return -1;
}

int replace_char(char* source, char oldChar, char newChar) {
	return replace_char_index(source, oldChar, newChar, 1);
}

int replace_char_last(char* source, char oldChar, char newChar) {
	return replace_char_last_index(source, oldChar, newChar, 1);
}

char* replace_char_all(char* source, char oldChar, char newChar) {
	char* p = NULL;

	NULRETURNUL(source);

	for (p = source; *p != '\0'; p ++)
		if (*p == oldChar) *p = newChar;

	return source;
}

int replace_char_index(char* source, char oldChar, char newChar, int index) {
	char* p = NULL;
	int counter = 0;

	NULRETURNAG(source);

	for (p = source; *p != '\0'; p++) {
		if (*p == oldChar) {
			counter ++;
			if (counter == index) {
				*p = newChar;
				return p - source;
			}
		}
	}

	return -1;
}

int replace_char_last_index(char* source, char oldChar, char newChar, int index) {
	char* p = NULL;
	int counter = 0;

	NULRETURNAG(source);

	for (p = source + strlen(source); p >= source; p--) {
		if (*p == oldChar) {
			counter ++;
			if (counter == index) {
				*p = newChar;
				return p - source;
			}
		}
	}

	return -1;
}

char* replace_str_all(char* source, char* seed, char* replace) {
	char* dest = NULL;
	char* p = 0;
	int n = 0;
	int counter = 0;
	int size = 0;
	int seed_len = 0;
	int replace_len = 0;

	NULRETURNUL(source);

	seed_len = strlen(seed);
	replace_len = strlen(replace);

	dest = calloc(1, BLOCK_SIZE);
	size = BLOCK_SIZE;

	for (p = source; *p != '\0'; p ++) {
		while ((counter + replace_len) >= size) {
			size += BLOCK_SIZE;
			dest = realloc(dest, size);
		}

		if (!strncmp(p, seed, seed_len)) {
			strcpy(dest + n, replace);

			counter += replace_len;
			p += seed_len - 1;
			n += replace_len;
		} else {
			dest[n ++] = *p;
			counter ++;
		}
	}
	
	return dest;
}

#if 0
int main(int argc, char** argv) {
	char src[1024] = {};
	int i = 0;
	int n = 0;

	char* s1 = "who";
	char* s2 = "1who";

	char** rst = NULL;

	rst = strcpy(src, "|||who|||are|||you|||U?1234|||");
	// rst = strcpy(src, "|a|abc||");

	rst = split_str_copy(src, "|", &n);
	for (i=0; i<n; i ++) {
		printf("splitc [%d]: [%s]\n", i, rst[i]);
	}

	/*
	rst = split_str_orig(src, "|||", &n);
	for (i=0; i<n; i ++) {
		printf("splitc [%d]: [%s]\n", i, rst[i]);
	}

	rst = strcpy(src, "who are you U?1234");
	rst = strcpy(src, "|a|abc||");

	rst = split_char(src, '|', &n);
	for (i=0; i<n; i ++) {
		printf("splitc [%d]: [%s]\n", i, rst[i]);
	}

	printf("last_index_of_str result[%d]\n", last_index_of_str(src, "123"));
	printf("index_of_str result[%d]\n", index_of_str(src, "1234"));
	printf("result: [%s]\n", replace_char_all(src, 'w', 'X'));
	printf("index: [%d]\n", replace_char_index(src, 'o', '-', 0));
	printf("result: [%s]\n", src);
	printf("index: [%d]\n", replace_char_last_index(src, 'o', 'O', 3));
	printf("result: [%s]\n", src);

	printf("result: [%s]\n", replace_str_all(src, "are", "ARE"));
	printf("src length: %ld\n", strlen(src));

	printf("s1[%s]\ns2[%s]\n", s1, s2);
	printf("result[%d]\n", strcmp_rev(s1, s2));

	printf("s1[%s]\ns2[%s]\n", s1, s2);
	printf("result[%d]\n", strncmp_rev(s1, s2, 3));

	printf("src[%s]\n", src);
	printf("strrev result[%s]\n", strrev(src));

	printf("str2upper result[%s]\n", str2upper(src));
	printf("str2upper result[%s]\n", str2lower(src));
	printf("strevcase result[%s]\n", strevcase(src));
	printf("rtrim result[%s]\n", rtrim(src));
	printf("rtrim(ltrim) result[%s]\n", rtrim(ltrim(src)));
	 */


	return 0;
}
#endif
