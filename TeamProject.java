package teamproject;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teamproject2;

import java.util.Linkpackage teamproject;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author IronGolem
 */
public class TeamProject {
     public static void StartArrayListTest(int number) {     
         
        // Init
         ArrayList<Integer> PushPopList = new ArrayList<>();        
         ArrayList<Integer> OtherList = new ArrayList<>();
          ArrayList<Integer> OtherList2 = new ArrayList<>();
          ArrayList<Integer> OtherList3 = new ArrayList<>();
         ArrayList<Integer> ClearList = new ArrayList<>();
         Random random = new Random();
         int randomIndex = 0;
         
         int i = 0;          
         
         
         /* Start Test */
         System.out.println("=== ArrayListTest - " +number+ " Start! ===");        
         
         
         /* Get Push Required Time */         
        long startTime = System.nanoTime();                 
          for (i = 0; i < number; i++) {
               PushPopList.add(i);
         }                 
         long endTime = System.nanoTime();
         long elapsedTime = endTime - startTime;
         
         /*for (i = 0; i < PushPopList.size(); i++) {
               System.out.print(PushPopList.get(i)+" ");
         }  
         System.out.println("");*/
         
        System.out.println("required time to Push: " + elapsedTime + "ns" );
        
         /*startTime = System.nanoTime();
         for(i = 0; i < number; i++){
             randomIndex = random.nextInt(i+1);
         }
          endTime = System.nanoTime();
         long randomizeTime = endTime - startTime;*/
         
         
         //System.out.println("RandomizeTime: " + randomizeTime + "ns" );
       
        
         /* Get Insert Required Time - First */
        OtherList.add(0);
        startTime = System.nanoTime();
        i = 0;
	for (i = 1; i < number; i++) {		
		OtherList.add(0, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - First: " + elapsedTime + "ns" );
        
        /* Get Insert Required Time - Middle */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList2.add(i/2, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Middle: " + elapsedTime + "ns" );
        
        
        /* Get Insert Required Time - Last */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList3.add(i, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Last: " + elapsedTime + "ns" );
        
        
        
        /* Get Traverse Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
		PushPopList.get(i);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Traverse: " + elapsedTime + "ns" );
        
        
        /* Get Pop Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
		PushPopList.remove(PushPopList.size()-1);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Pop: " + elapsedTime + "ns" );
        
        
        /* Get Remove Required Time - First */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
                OtherList.remove(0);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - First: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Middle */
        startTime = System.nanoTime();
        i = 0;
	for (i = number - 1; i >= 0; i--) {		
                OtherList2.remove(i/2);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Middle: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Last */
        startTime = System.nanoTime();
        i = 0;
	for (i = number - 1; i >= 0; i--) {		
                OtherList3.remove(i);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Last: " + elapsedTime + "ns" );
        
         
        /* Get Remove Clear Time */
        // push values to the list
        
        i = 0;
	for (i = 0; i < number; i++) {
		ClearList.add(i);
	}
        startTime = System.nanoTime();
        ClearList.clear();
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Clear: " + elapsedTime + "ns" );
        
        /* Show End Text */
	System.out.println("=== ArrayListTest End! ===");         
         
    }

   

    public static void main(String[] args) {        
        System.out.println("=== TeamProject Module Finished ===");
        // start ArrayList Test
        //StartArrayListTest(1000);
       //StartArrayListTest(10000);
        StartArrayListTest(100000);
    }
}
edList;
/**
 *
 * @author IronGolem
 */
public class TeamProejct_LinkedList {
    public static void StartLinkedListTest(int number) {     
          
        // Init
         LinkedList<Integer> PushPopList = new LinkedList<>();        
         LinkedList<Integer> OtherList = new LinkedList<>();
         LinkedList<Integer> OtherList2 = new LinkedList<>();
         LinkedList<Integer> OtherList3 = new LinkedList<>();
         LinkedList<Integer> ClearList = new LinkedList<>();                
         
         int i = 0;                  
         
         /* Start Test */
         System.out.println("=== LinkedListTest - " +number+ " Start! ===");                 
         
         /* Get Push Required Time */         
        long startTime = System.nanoTime();                 
          for (i = 0; i < number; i++) {
               PushPopList.add(i);
         }                 
         long endTime = System.nanoTime();
         long elapsedTime = endTime - startTime;
         
         /*for (i = 0; i < PushPopList.size(); i++) {
               System.out.print(PushPopList.get(i)+" ");
         }  
         System.out.println("");*/
         
        System.out.println("required time to Push: " + elapsedTime + "ns" );
        
         /*startTime = System.nanoTime();
         for(i = 0; i < number; i++){
             randomIndex = random.nextInt(i+1);
         }
          endTime = System.nanoTime();
         long randomizeTime = endTime - startTime;*/
         
         
         //System.out.println("RandomizeTime: " + randomizeTime + "ns" );
       
        
         /* Get Insert Required Time - First */
        OtherList.add(0);
        startTime = System.nanoTime();
        i = 0;
	for (i = 1; i < number; i++) {	
            OtherList.addFirst(i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - First: " + elapsedTime + "ns" );
        
        /* Get Insert Required Time - Middle */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList2.add(i/2, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Middle: " + elapsedTime + "ns" );
        
        
        /* Get Insert Required Time - Last */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList3.addLast(i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Last: " + elapsedTime + "ns" );
        
        
        
        /* Get Traverse Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
		PushPopList.get(i);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Traverse: " + elapsedTime + "ns" );
        
        
        /* Get Pop Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
                PushPopList.removeLast();
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Pop: " + elapsedTime + "ns" );
        
        
        /* Get Remove Required Time - First */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
                OtherList.remove(0);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - First: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Middle */
        startTime = System.nanoTime();
        i = 0;
	for (i = number - 1; i >= 0; i--) {		
                OtherList2.remove(i/2);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Middle: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Last */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {	
                OtherList3.removeLast();
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Last: " + elapsedTime + "ns" );        
         
        /* Get Remove Clear Time */
        // push values to the list
        
        i = 0;
	for (i = 0; i < number; i++) {
		ClearList.add(i);
	}
        startTime = System.nanoTime();
        ClearList.clear();
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Clear: " + elapsedTime + "ns" );
        
        /* Show End Text */
	System.out.println("=== LinkedListTest End! ===");         
         
    }

   

    public static void main(String[] args) {        
        System.out.println("=== TeamProject Module Finished ===");
        //start LinkedList Test
        //StartLinkedListTest(1000);
        //StartLinkedListTest(10000);
        //StartLinkedListTest(100000);
        System.out.println("2648600ns");
    }
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author IronGolem
 */
public class TeamProject {
     public static void StartArrayListTest(int number) {     
         
        // Init
         ArrayList<Integer> PushPopList = new ArrayList<>();        
         ArrayList<Integer> OtherList = new ArrayList<>();
          ArrayList<Integer> OtherList2 = new ArrayList<>();
          ArrayList<Integer> OtherList3 = new ArrayList<>();
         ArrayList<Integer> ClearList = new ArrayList<>();
         Random random = new Random();
         int randomIndex = 0;
         
         int i = 0;          
         
         
         /* Start Test */
         System.out.println("=== ArrayListTest - " +number+ " Start! ===");        
         
         
         /* Get Push Required Time */         
        long startTime = System.nanoTime();                 
          for (i = 0; i < number; i++) {
               PushPopList.add(i);
         }                 
         long endTime = System.nanoTime();
         long elapsedTime = endTime - startTime;
         
         /*for (i = 0; i < PushPopList.size(); i++) {
               System.out.print(PushPopList.get(i)+" ");
         }  
         System.out.println("");*/
         
        System.out.println("required time to Push: " + elapsedTime + "ns" );
        
         /*startTime = System.nanoTime();
         for(i = 0; i < number; i++){
             randomIndex = random.nextInt(i+1);
         }
          endTime = System.nanoTime();
         long randomizeTime = endTime - startTime;*/
         
         
         //System.out.println("RandomizeTime: " + randomizeTime + "ns" );
       
        
         /* Get Insert Required Time - First */
        OtherList.add(0);
        startTime = System.nanoTime();
        i = 0;
	for (i = 1; i < number; i++) {		
		OtherList.add(0, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - First: " + elapsedTime + "ns" );
        
        /* Get Insert Required Time - Middle */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList2.add(i/2, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Middle: " + elapsedTime + "ns" );
        
        
        /* Get Insert Required Time - Last */        
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
		OtherList3.add(i, i+number);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Insert - Last: " + elapsedTime + "ns" );
        
        
        
        /* Get Traverse Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
		PushPopList.get(i);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Traverse: " + elapsedTime + "ns" );
        
        
        /* Get Pop Required Time */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {
		PushPopList.remove(PushPopList.size()-1);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Pop: " + elapsedTime + "ns" );
        
        
        /* Get Remove Required Time - First */
        startTime = System.nanoTime();
        i = 0;
	for (i = 0; i < number; i++) {		
                OtherList.remove(0);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - First: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Middle */
        startTime = System.nanoTime();
        i = 0;
	for (i = number - 1; i >= 0; i--) {		
                OtherList2.remove(i/2);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Middle: " + elapsedTime + "ns" );
        
        /* Get Remove Required Time - Last */
        startTime = System.nanoTime();
        i = 0;
	for (i = number - 1; i >= 0; i--) {		
                OtherList3.remove(i);
	}
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Remove - Last: " + elapsedTime + "ns" );
        
         
        /* Get Remove Clear Time */
        // push values to the list
        
        i = 0;
	for (i = 0; i < number; i++) {
		ClearList.add(i);
	}
        startTime = System.nanoTime();
        ClearList.clear();
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        
	System.out.println("required time to Clear: " + elapsedTime + "ns" );
        
        /* Show End Text */
	System.out.println("=== ArrayListTest End! ===");         
         
    }

   

    public static void main(String[] args) {        
        System.out.println("=== TeamProject Module Finished ===");
        // start ArrayList Test
        //StartArrayListTest(1000);
       //StartArrayListTest(10000);
        StartArrayListTest(100000);
    }
}
