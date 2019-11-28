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
	printk(KERN_EMERG "=== TeamProject Module Started ===\n");

	// start arrayList Test
	StartArrayListTest(1000);
	StartArrayListTest(10000);
	StartArrayListTest(100000);

	return 0;
}
void __exit simple_module_cleanup(void)
{
	printk("=== TeamProject Module Finished ===\n");
}


void StartArrayListTest(const int number)
{
	// Declare variable
        struct arrayList* newArrList = kmalloc(sizeof(struct arrayList), GFP_KERNEL);
	// Init arrayList
	INIT_ARRAYLIST(newArrList);

	/* Start Test */
	printk(KERN_EMERG "=== ArrayListTest - %d Start! ===\n", number);

	/* Get Add Required Time */
	ktime_t startTime = ktime_get();
        int i = 0;
        for (i = 0; i < number; i++)
        {
                arrayList_Add(newArrList, i);
        }

        printk(KERN_EMERG "required time to Add:\t%d ns\n", ktime_get() - startTime);


	/* Get Insert Required Time */
	startTime = ktime_get();
	i = 0;
	for (i = 0; i < number; i++)
	{
		int randomIndex = ktime_get() % number;	// [0 ~ number-1]
		arrayList_Insert(newArrList, randomIndex, (i + number));
	}

	printk(KERN_EMERG "required time to Insert:\t%d ns\n", ktime_get() - startTime);
	

	/* Get Traverse Required Time */
	startTime = ktime_get();
	for (i = 0; i < number; i++)
	{
		arrayList_GetValue(newArrList, i);
	}

	printk(KERN_EMERG "required time to Traverse:\t%d ns\n", ktime_get() - startTime);


	/* Get Delete Required Time */
	startTime = ktime_get();
        i = 0;
        for (i = 0; i < number; i++)
        {
                int randomIndex = ktime_get() % number; // [0 ~ number-1]
                arrayList_Delete(newArrList, randomIndex);
        }

        printk(KERN_EMERG "required time to Delete:\t%d ns\n", ktime_get() - startTime);


	/* Get Clear Required Time */
	startTime = ktime_get();
	arrayList_Clear(newArrList);
	printk(KERN_EMERG "required time to Delete:\t%d ns\n", ktime_get() - startTime);


	/* Show End Text */
	printk(KERN_EMERG "=== ArrayListTest End! ===\n");

	// test - print
	//arrayList_Print(newArrList);
	
	// Free arrayList
	kfree(newArrList->data);
	kfree(newArrList);
}


module_init(simple_module_init);
module_exit(simple_module_cleanup);

MODULE_LICENSE("GPL");
