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
inline int arrayList_GetValue(const struct arrayList* arrList, const int index)
{
	// Exception
	if (!arrList
	    || index < 0 || index >= arrList->size) return -1;
	
	// return value
	return (*arrList->data)[index];
}

/** Push new value to the list */
void arrayList_Push(struct arrayList* arrList, const int value)
{
	// Exception
	if (!arrList) return;

	// Allocate new data pointer if the data pointer is NULL
        if (!(*arrList->data))
        {
                *arrList->data = (int*)kmalloc(sizeof(int), GFP_KERNEL);
        }

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


/** Insert new value to the list */
void arrayList_Insert(struct arrayList* arrList, const int index, const int value)
{
	// Exception
	if (!arrList || index < 0
	    || index > arrList->size) return;

	// Allocate new data pointer if the data pointer is NULL
	if (!(*arrList->data))
	{
		*arrList->data = (int*)kmalloc(sizeof(int), GFP_KERNEL);
	}

	// Initialize Variables
	bool bScaledUp = false;
	int* newData = *arrList->data;

	// Scale up if the capacity is less than size
	if (arrList->capacity <= arrList->size)
	{
		bScaledUp = true;
		arrList->capacity *= 2;
                *arrList->data = (int*)kmalloc(sizeof(int) * arrList->capacity, GFP_KERNEL);
	}
	
	// Adjust indices
	int i = arrList->size;
	while (i > index)
	{
		(*arrList->data)[i] = newData[i-1];
		i--;
	}

	// Insert the new value to the index
	(*arrList->data)[index] = value;

	// Increase size
	arrList->size++;

	// Copy rest if it scaled up
	if (bScaledUp == true)
	{
		i = index - 1;
		while (i >= 0)
		{
			(*arrList->data)[i] = newData[i];
			i--;
		}
	}
}


/** Pop from the list */
int arrayList_Pop(struct arrayList* arrList)
{
	// Exception
	if (!arrList || arrList->size < 1) return -1;

	// Pop from the array list
	int value = (*arrList->data)[arrList->size - 1];
	(*arrList->data)[arrList->size - 1] = NULL;
	
	// Resize the array list
	arrList->size--;

	// Clear the arrayList if empty
	if (arrList->size == 0)
	{
		kfree(*arrList->data);
		arrList->capacity = 1;
	}

	return value;
}


/** Remove a value by index from the list - Deprecated */
void arrayList_Remove(struct arrayList* arrList, const int index)
{
	// Exception
	if (!arrList || arrList->size < 1
	    || index < 0 || index >= arrList->size) return;

	/* Move indices to fill empty space */
	// Divide cases by the index
	if (index == 0)	// if the index is the first
	{
		// Delete the index and move pointer
		int* previous = *arrList->data;
		*arrList->data = *arrList->data + sizeof(int*);
		*previous = NULL;
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
		(*arrList->data)[arrList->size - 1] = NULL;
	}

	// Resize arrayList
	arrList->size--;

	// Clear the data pointer if empty
	if (arrList->size == 0)
	{
		kfree(*arrList->data);
		arrList->capacity = 1;
	}
}


/** Clear the list */
void arrayList_Clear(struct arrayList* arrList)
{
	// Exception
	if (!arrList || !(arrList->data)
	    || !(*arrList->data) || arrList->size < 1) return;
	
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
	arrList->capacity = 1;
}

