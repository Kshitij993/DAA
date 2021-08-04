/*
	Written by: Kshitij Kumar Sharma                     Roll No: 1905514
	Question:
		Write a program to sort a given set of elements using the insertion sort. Additionally, determine the time required (in terms of steps) to sort the elements. 
		(Note: assume cost of any basic operation is 1, i.e., c1= c2 = ... = c8 = 1).
		1) Repeat the experiment for different values of n = 500, 1000, 5000, 10000
		2) For each of aforementioned case, consider arrays as sorted, random, and reverse-sorted. Provide the complexity in terms of step count

	Ideal of the Solution:
		First I will define a insertation sort function and then I will generate random array of different size and then I will check for 	all the three cases.
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

int insertationSort(int a[],int n)         //Insertation sort functation taking an array and its size as parameter
	{
    int i,j,temp,c=0;							//c is the step counter
    for(i=1;i<n;i++)
   	 {
        temp=a[i];								//storing the element into a temperary variable for finding it position
        c++;
        j=i-1;
        c++;
        while(temp<a[j])						//loop for finding the position
     	  		{
     	  		 c++;
             if(j==-1)
             {
                c++;
                break;
             }
             a[j+1]=a[j];						//swaping for creating position
             c++;
             j--;
             c++;
        		}
        a[j+1]=temp;							 	//Inserting the element at the position
        c++;
   	 }
    return c;										//returning the total step count
	}
	
int main()
	{
	 int n,i,j,k,c1,c2,c3;						//Variables for keeping different step counts
	 clock_t start, end;							//Variables for keeping start and end time
    double cpu_time_used;						//Variable for keeping cpu time used
	 for(i=0;i<4;i++)
	 	{
	 	cout<<endl;
	 	cout<<"Enter the size of the array : ";
	 	cin>>n;
	 	int a[n];
	 	srand(time(0));
	 	for(j=0;j<n;j++)
	 	 	a[j]=rand()%1000000;					//generating the random array
	 	cout<<"For n= "<<n<<endl;
	 	start=clock();								//keeping start time of the clock for random array
	 	c1=insertationSort(a,n);				//sorting
	 	end=clock();								//keeping end time of the clock for random array
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC; //calculating cpu time used for random array
	 	cout<<"Step count for random : "<<c1<<endl;
	 	//cout<<"time taken : "<<cpu_time_used<<endl;
	 	printf("Time taken for random : %fsec \n",cpu_time_used);
	 	sort(a,a+n);
	 	
	 	start=clock();								//keeping start time of the clock for sorted array
	 	c2=insertationSort(a,n);				//sorting
	 	end=clock();								//keeping end time of the clock for sorted array
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	//calculating cpu time used for sorted array
	 	cout<<"Step count for sorted : "<<c2<<endl;
	 	//cout<<"time taken : "<<cpu_time_used<<endl;
	 	printf("Time taken for sorted : %fsec \n",cpu_time_used);
	 	
	 	sort(a,a+n,greater<int>());
	 	start=clock();								//keeping start time of the clock for reverse sorted array
	 	c3=insertationSort(a,n);				//sorting
	 	end=clock();								////keeping end time of the clock for reverse sorted array
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	//calculating cpu time used for reverse sorted array
	 	cout<<"Step count for reverse sorted : "<<c3<<endl;
	 	//cout<<"time taken : "<<cpu_time_used<<endl;
	 	printf("Time taken for reverse sorted : %fsec \n",cpu_time_used);
	 	}	 	 
	}

