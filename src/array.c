#include <garlic/array.h>

void array_sort_bubble(void* array[], int size, int (*comp)(void*, void*)) {
	int i = 0;
	void* p = NULL;

	for (; size > 1; size --) {
		for (i = 0; i<size-1; i ++) {
			if ((*comp)(array[i], array[i+1])>0) {
				p = array[i];
				array[i] = array[i+1];
				array[i+1] = p;
			}
		}
	}
}

void* array_max(void* array[], int size, int (*comp)(void*, void*)) {
	int half = 0;
	void* p1;
	void* p2;

	if (size == 0) return NULL;
printf("size[%d]\n", size);
	if (size == 1) return array[0];
	
	if (size == 2) {
		return (*comp)(array[0], array[1])>0 ? p1 : p2;
	}

	p1 = array_max(array, half, comp);
	p2 = array_max(array + half, size - half, comp);

	return (*comp)(p1, p2)>0 ? p1 : p2;
}
