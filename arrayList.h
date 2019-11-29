//#include <linux/kernel.h>
#include <linux/slab.h>

// Definition
struct arrayList
{
	int** data;
	int size;	// current size
	int capacity;	// current capacity. This will be increased by 2 times.
};

/* test */
inline int arrayList_test(struct arrayList* arrList);
void arrayList_Print(const struct arrayList* arrList);

/** Initialize arrayList */
void INIT_ARRAYLIST(struct arrayList* arrList);

/** Get Value from index */
inline int arrayList_GetValue(const struct arrayList* arrList, const int index);

/** Push new value to the list */
void arrayList_Push(struct arrayList* arrList, const int value);

/** Insert new value to the list */
void arrayList_Insert(struct arrayList* arrList, const int index, const int value);

/** Pop from the list */
int arrayList_Pop(struct arrayList* arrList);

/** Remove a value from the list */
void arrayList_Remove(struct arrayList* arrList, const int value);

/** Clear the list */
void arrayList_Clear(struct arrayList* arrList);

