#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include "arrayList.h"

spinlock_t lock;

void StartArrayListTest(const int number);

int __init simple_module_init(void)
{
	printk(KERN_EMERG "===== TeamProject Module Started =====\n");

	// start arrayList Test
	StartArrayListTest(1000);
	StartArrayListTest(10000);
	StartArrayListTest(100000);

	return 0;
}
void __exit simple_module_cleanup(void)
{
	printk("===== TeamProject Module Finished =====\n");
}


void StartArrayListTest(const int number)
{
	// Declare arrayLists
        struct arrayList* PushPopList = kmalloc(sizeof(struct arrayList), GFP_KERNEL);
	struct arrayList* OtherList = kmalloc(sizeof(struct arrayList), GFP_KERNEL); 
	struct arrayList* ClearList = kmalloc(sizeof(struct arrayList), GFP_KERNEL);

	int i = 0;	// To iterate
	ktime_t startTime = ktime_get();
	for (i = 0; i < number; i++)	// Get required time to randomize
	{
		ktime_t temp = ktime_get();
	}
	ktime_t randomizeTime = ktime_get() - startTime;

	// Init arrayList
	INIT_ARRAYLIST(PushPopList);
	INIT_ARRAYLIST(OtherList);
	INIT_ARRAYLIST(ClearList);

	/* Start Test */
	printk(KERN_EMERG "=== ArrayListTest - %d Start! ===\n", number);

	/* Get Push Required Time */
	startTime = ktime_get();
        for (i = 0; i < number; i++)
        {
                arrayList_Push(PushPopList, i);
        }

        printk(KERN_EMERG "Time - Push:\t%lld ns\n", ktime_get() - startTime);


	/* Get Insert Required Time */
	startTime = ktime_get();
	// Insert the first
	arrayList_Insert(OtherList, 0, number);
	// Insert others to prevent zero division. (Only allows if arrList->size > 0)
	for (i = 1; i < number; i++)
	{
		int randomIndex = ktime_get() % OtherList->size;	// [0 ~ number-1]
		arrayList_Insert(OtherList, randomIndex, (i + number));
	}

	// Print, but subtract the randomize time
	printk(KERN_EMERG "Time - Insert:\t%lld ns\n", ktime_get() - startTime - randomizeTime);


	/* Get Traverse Required Time */
	startTime = ktime_get();
	for (i = 0; i < number; i++)
	{
		arrayList_GetValue(PushPopList, i);
	}

	printk(KERN_EMERG "Time - Traverse:\t%lld ns\n", ktime_get() - startTime);


	/* Get Pop Required Time */
	startTime = ktime_get();
        for (i = 0; i < number; i++)
        {
                arrayList_Pop(PushPopList);
        }
        printk(KERN_EMERG "Time - Pop:\t%lld ns\n", ktime_get() - startTime);


	/* Get Remove Required Time */
	startTime = ktime_get();
        for (i = 1; i < number; i++)	// To prevent zero division. Only allows if arrList->size is greater than 0.
        {
                int randomIndex = ktime_get() % OtherList->size; // [0 ~ size-1]
		arrayList_Remove(OtherList, randomIndex);
	}
	arrayList_Remove(OtherList, 0);	// Remove the last

	// Print, but subtract the randomize time
        printk(KERN_EMERG "Time - Remove:\t%lld ns\n", ktime_get() - startTime - randomizeTime);
	

	/* Get Clear Required Time */
	// push values to the list
	for (i = 0; i < number; i++)
	{
		arrayList_Push(ClearList, i);
	}
	startTime = ktime_get();
	arrayList_Clear(ClearList);
	printk(KERN_EMERG "Time - Clear:\t%lld ns\n", ktime_get() - startTime);
	

	/* Show End Text */
	printk(KERN_EMERG "=== ArrayListTest End! ===\n");
	
	// Free arrayList
	kfree(PushPopList->data);
	kfree(OtherList->data);
	kfree(ClearList->data);
	kfree(PushPopList);
	kfree(OtherList);
	kfree(ClearList);
}


module_init(simple_module_init);
module_exit(simple_module_cleanup);

MODULE_LICENSE("GPL");
