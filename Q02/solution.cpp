// Program to search for element using header file

#include <iostream>
#include "sort.h"

int Linear( int arr[], int n, int m);
int Binary( int arr[], int n, int x);

int main(){


while(1){

int size;
int target;
printf("\nEnter the number of elements in the array:");
scanf("%d", &size);
int arr[size];

printf("Enter the elements of the array: \n");
for(int i=0;i<size;i++){
	scanf("%d", &arr[i]);
}

printf("Enter element to be searched: \n");
scanf("%d", &target);

printf("MENU: \n 1. Linear Search \n 2. Binary Search \n 3. Exit\n");
int choice;
printf("Enter your choice: \n");
scanf("%d", &choice);

switch(choice){

case 1:
if(Linear(arr, size, target)== 1){

	printf("The element %d is found in the given array\n", target);
}
else
	printf("The element %d is not found in the given array\n", target);
break;

case 2:
if(Binary(arr, size, target)== 1){
	printf("The element %d is found in the given array\n", target);
}
else{
	printf("The element %d is not found in the given array\n", target);}
break;

case 3:
printf("Exiting the program.");
exit(0);

default:
printf("Invalid input.\n ");
		}
	}
}


int Linear( int arr[], int n, int m){

for(int i =0; i<n; i++){
	if(arr[i] == m){
		return 1;
		}
	}
}

int Binary( int arr[], int n, int x){

Bubble(arr, n);

int f =0;
int l =0;
int u = n-1;
int m = (u+l)/2;

while(l<=u){
	m = (u+l)/2;
	if(arr[m]==x){
		f++;
	break;
}

else if(arr[m]>x){
	u = m-1;
}

else{ l = m;}
}

return f;
}
