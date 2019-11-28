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
int arrayList_GetValue(const struct arrayList* arrList, const int index);

/** Add new value to the list */
void arrayList_Add(struct arrayList* arrList, const int value);

/** Delete a value from the list */
void arrayList_Delete_Deprecated(struct arrayList* arrList, const int value);

/** Clear the list */
void arrayList_Clear(struct arrayList* arrList);

