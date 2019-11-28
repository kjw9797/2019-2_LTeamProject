#include "arrayList.h"


/** test */
inline int arrayList_test(struct arrayList* arrList)
{
	if (arrList) return 1;
	else return -1;
}
void arrayList_Print(const struct arrayList* arrList)
{
	// Exception
	if (!arrList || arrList->size < 1) return;

	// Print arrayList
	int iterator = 0;
	while (iterator < arrList->size)
	{
		printk(KERN_EMERG "index: %d / value: %d / address: %d\n", iterator, arrayList_GetValue(arrList, iterator), &arrList->data[iterator]);
		iterator++;
	}
}


/** Initialize arrayList */
void INIT_ARRAYLIST(struct arrayList* arrList)
{
	// Allocate new int variable as 0
	arrList->data = (int**)kmalloc(sizeof(int), GFP_KERNEL);
	//*arrList->data = 0;
	*arrList->data = (int*)kmalloc(sizeof(int), GFP_KERNEL);
	**arrList->data = 0;
	// Initialize variables
	arrList->size = 0;
	arrList->capacity = 1;
}

/** Get Value from index */
int arrayList_GetValue(const struct arrayList* arrList, const int index)
{
	// Exception
	if (!arrList
	    || index < 0 || index >= arrList->size) return -1;
	
	// return value
	return (*arrList->data)[index];
}

/** Add new value to the list */
void arrayList_Add(struct arrayList* arrList, const int value)
{
	// Exception
	if (!arrList) return;

	// Incrase capacity if it is less than size
	if (arrList->capacity <= arrList->size)
	{
		arrList->capacity *= 2;
		
		// Declare new pointer
        	int* newData = *arrList->data;

		// Reallocate arrList's data
       		*arrList->data = (int*)kmalloc(sizeof(int) * arrList->capacity, GFP_KERNEL);
        	// Copy data
        	int i = 0;
        	while (i < arrList->size)
        	{
                	(*arrList->data)[i]= newData[i];
                	i++;
        	}

		// Free previous pointer
		kfree(newData);
	}

	// Add a new value to arrayList
	(*arrList->data)[arrList->size] = value;

	// Increase size
	arrList->size++;
}


/** Delete a value by index from the list - Deprecated */
void arrayList_Delete_Deprecated(struct arrayList* arrList, const int index)
{
	// Exception
	if (!arrList || arrList->size == 0
	    || index < 0 || index >= arrList->size) return;

	/* Move indices to fill empty space */
	// Divide cases by the index
	if (index == 0)	// if the index is the first
	{
		// Delete the index and move pointer
		int* previous = *arrList->data;
		*arrList->data = *arrList->data + sizeof(int);
		kfree(previous);
	}
	else
	{
		// Move indices
		int i = index;
		while (i < arrList->size - 1)
		{
			(*arrList->data)[i] = (*arrList->data)[i+1];
			i++;
		}

		// Resize arrayList
		(*arrList->data)[arrList->size] = NULL;
		arrList->size--;
	}
}


/** Clear the list */
void arrayList_Clear(struct arrayList* arrList)
{
	// Exception
	if (!arrList) return;
	
	// Clear the list from the last index
	int i = arrList->size - 1;
	while (i >= 0)
	{
		(*arrList->data)[i] = NULL;
		i--;
	}

	// Free pointer
	kfree(*arrList->data);	// Remain the main data pointer(**) to ensure the arrayList can add value later.
	
	// Resize arrayList
	arrList->size = 0;
}

