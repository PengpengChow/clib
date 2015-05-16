#include <garlic/xtring.h>

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

int main(int argc, char** argv) {
	char src[1024] = {};

	char* s1 = "who";
	char* s2 = "1who";

	strcpy(src, "who");

	/* printf("result: [%s]\n", replace_char_all(src, 'w', 'X'));
	printf("index: [%d]\n", replace_char_index(src, 'o', '-', 0));
	printf("result: [%s]\n", src);
	printf("index: [%d]\n", replace_char_last_index(src, 'o', 'O', 3));
	printf("result: [%s]\n", src);

	printf("result: [%s]\n", replace_str_all(src, "are", "ARE"));
	printf("src length: %ld\n", strlen(src));

	printf("s1[%s]\ns2[%s]\n", s1, s2);
	printf("result[%d]\n", strcmp_rev(s1, s2)); */

	printf("s1[%s]\ns2[%s]\n", s1, s2);
	printf("result[%d]\n", strncmp_rev(s1, s2, 3));
}
