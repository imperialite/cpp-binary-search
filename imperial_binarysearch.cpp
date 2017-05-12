/*

BINARY SEARCH with random numbers of n, where n = 1000, 10000, 100000

Implemented in C++ by JOSEPH MARVIN R. IMPERIAL, BSCS 3A 
In compliance for the final project for Design and Analysis of Algorithm (DAA)
Date Submitted: March 27, 2017

Binary Search is a search algorithm that locates a given value by its position within a SORTED array. It is also known as
half-interval search or logarithmic search (cprogrammingcode.com)

*/

//HEADERS
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <ctime>

using namespace std;

void binarysearch(int array[],int,int,int);
void quick(int array[], int, int);

main()
{
	srand (time(NULL));	//seed
	int searchee,s,e,n,x;
	int *array;
	int start, stop; //clock variables
	
	cout << "Enter value to be searched: ";
	cin >> searchee;
	cout << endl;

	
	//N = 1000
		start = clock(); //starts the clock to measure speed
		cout << "N = 1000";
		cout << "\nLocating value within 1000 random numbers...\n";	
		n = 1000;
		s = 0;
		e = n-1;
		array = new int[n];

		// Fills the array with random numbers of range n
		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		
		//calls quicksort function
		quick(array, s ,e);
		
		//calls binary search function
		binarysearch(array, searchee, s, e);
		
		stop=clock(); //stops clock
		
		//calculates and displays time taken by program
		cout << "\nExecution time: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n\n";
		delete[]array;
	
	//N = 10000
		cout << "N = 10000";
		start = clock(); 
		cout << "\nLocating value within 10000 random numbers...\n";	
		n = 10000;
		s = 0;
		e = n-1;
		array = new int[n];

		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		quick(array, s ,e);
		binarysearch(array, searchee, s, e);
		stop=clock();
		cout << "\nExecution time: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n\n";
		delete[]array;
	
	//N = 100000
		cout << "N = 100000";
		start = clock(); 
		cout << "\nLocating value within 100000 random numbers...\n";	
		n = 100000;
		s = 0;
		e = n-1;
		array = new int[n];

		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		quick(array, s ,e);
		binarysearch(array, searchee, s, e);
		stop=clock();
		cout << "\nExecution time: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n\n";
		delete[]array;
	
}



//BINARY SEARCH FUNCTION
void binarysearch(int array[], int searchee, int s, int e){
	
	int median;
	
	while (s <= e)
	{
		// the median will be the middle value of the array, for breaking the array in half
		median = (s + e) / 2;
	
		//if value is at the middle of the array, break the search, display position
		if(array[median] == searchee)
		{
			cout<< "Found!" << endl;
			cout<< "Index Location: " << median+1;
			break;
		}
		
		//if value being searched is greater than the median, start value, s, will be median + 1 since value is greater than median
		else if(array[median] < searchee)
		{
			s = median + 1;
		}
		
		//if value being searched is less than the median, last value, e, will be median-1 since value is less than median
		else if(array[median] > searchee)
		{
			e = median - 1;
		}
	}
	
	// if the start value increments until it becomes greater than the last value, the search will stop, meaning the value is not within the array
	// it reached the point where the whole array is halved until the very last element, and the value is still not found
	if(s > e)
	{
		cout << "Value not found in array!";
	}

}

// QUICKSORT FUNCTION FOR SORTING THE ARRAY
void quick(int array[], int s, int e){
	
	int i,j,pivot;
	i = s;
	j = e;
	pivot = array[(s + e) / 2];	//the median will be the pivot
	
	//partition operation
	while (i <= j) {
		
		//loops and shifts forward until it gets an element which is greater than pivot, then stops
        while (array[i] < pivot){
        	i = i+1;
        }
        //loops and shifts backward until it gets an element which is less than pivot, then stops
	    while (array[j] > pivot){
	    	j = j-1;
	    }
	    if (i <= j) {
	    	// swaps the two values obtained so that elements less than pivot will go to left, and elements greater than pivot will go to the right
	    	swap(array[i],array[j]);
	    	//on to the next element
	        i = i+1;
	        j = j-1;
	    }
	}
	
	//recursion function that sorts the array section less than the pivot, the left part of the pivot
  	if (s < j){
  		//s becomes new start, j becomes new end
  		quick(array, s, j);	
  	}
  	
  	//recustion function that sorts the array section greater than the pivot, the right part of the pivot
  	if (i < e){
  		//i becomes new start, e becomes new end
  		quick(array, i, e);	
  	}
     
}


