#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include "arrayList.h"


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
	struct arrayList* OtherList2 = kmalloc(sizeof(struct arrayList), GFP_KERNEL);
	struct arrayList* OtherList3 = kmalloc(sizeof(struct arrayList), GFP_KERNEL);
	struct arrayList* ClearList = kmalloc(sizeof(struct arrayList), GFP_KERNEL);

	int i = 0;	// To iterate
	ktime_t startTime;
	
	/* Get required time to randomize
	for (i = 0; i < number; i++)	// Get required time to randomize
	{
		ktime_t temp = ktime_get();
	}
	ktime_t randomizeTime = ktime_get() - startTime;
	*/

	// Init arrayList
	INIT_ARRAYLIST(PushPopList);
	INIT_ARRAYLIST(OtherList);
	INIT_ARRAYLIST(OtherList2);
	INIT_ARRAYLIST(OtherList3);
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


	/* Get Insert Required Time - First */
	startTime = ktime_get();
	// Insert the first
	arrayList_Insert(OtherList, 0, number);
	for (i = 1; i < number; i++)
	{
		arrayList_Insert(OtherList, 0, (i + number));
	}
	printk(KERN_EMERG "Time - Insert - First:\t%lld ns\n", ktime_get() - startTime);

	
	/* Get Insert Required Time - Middle */
        startTime = ktime_get();
        for (i = 0; i < number; i++)
        {
                arrayList_Insert(OtherList2, i/2, (i + number));
        }
        printk(KERN_EMERG "Time - Insert - Middle:\t%lld ns\n", ktime_get() - startTime);


	/* Get Insert Required Time - Last */
        startTime = ktime_get();
        for (i = 0; i < number; i++)
        {
                arrayList_Insert(OtherList3, i, (i + number));
        }
        printk(KERN_EMERG "Time - Insert - Last:\t%lld ns\n", ktime_get() - startTime);


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


	/* Get Remove Required Time - First */
	startTime = ktime_get();
        for (i = 1; i < number; i++)
        {
		arrayList_Remove(OtherList, 0);
	}
	arrayList_Remove(OtherList, 0);	// Remove the last
        printk(KERN_EMERG "Time - Remove - First:\t%lld ns\n", ktime_get() - startTime);
	

	/* Get Remove Required Time - Middle */
        startTime = ktime_get();
        for (i = number - 1; i >= 0; i--)
        {
                arrayList_Remove(OtherList2, i/2);
        }
        printk(KERN_EMERG "Time - Remove - Middle:\t%lld ns\n", ktime_get() - startTime);

	
	/* Get Remove Required Time - Last */
        startTime = ktime_get();
        for (i = number - 1; i >= 0; i--)
        {
                arrayList_Remove(OtherList2, i);
        }
        printk(KERN_EMERG "Time - Remove - Last:\t%lld ns\n", ktime_get() - startTime);


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
	kfree(OtherList2->data);
	kfree(OtherList3->data);
	kfree(ClearList->data);
	kfree(PushPopList);
	kfree(OtherList);
	kfree(OtherList2);
	kfree(OtherList3);
	kfree(ClearList);
}


module_init(simple_module_init);
module_exit(simple_module_cleanup);

MODULE_LICENSE("GPL");
