//Program to sort an array in ascending order//

#include <iostream>

void Bubble(int arr[], int n);
void Selection(int arr[], int n);
void Insertion(int arr[], int n);
void Print(int arr[], int n);

int main(){

while(1){

int size;
printf("Enter the number of elements in the array:");
scanf("%d", &size);
int arr[size];

printf("Enter the elements of the array: \n");
for(int i=0;i<size;i++){
	scanf("%d", &arr[i]);
}

printf("MENU: \n 1. Bubble Sort \n 2. Selection Sort \n 3. Insertion Sort \n 4. Exit\n");
int choice;
printf("Enter your choice: \n");
scanf("%d", &choice);

switch(choice){

		case 1:
		Bubble(arr, size);
		Print(arr, size);
		break;

		case 2:
		Selection(arr, size);
		Print(arr, size);
		break;

		case 3:
		Insertion(arr, size);
		Print(arr, size);
		break;

		case 4:
		printf("Exiting the program.");
		exit(0);

		default:
		printf("Invalid input.\n ");
		}
	}
}


void Bubble(int arr[], int n){

int temp;
for(int i = 0; i < (n + 1); i++ ){
	for(int j = i+1; j < n; j++){
		if(arr[i]>arr[j]){
			temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}

return;

}

void Selection(int arr[], int n){

for(int i =0; i<n; i++){
	int s = arr[i];
	int p = i;

	for(int j=i+1; j<n; j++){

		if(arr[j]<s){
			s = arr[j];
			p=j;
		arr[p]=arr[i];
		arr[i]=s;
			}
		}
	}
}

void Insertion(int arr[], int n){

for(int i = 1; i<n; i++){
	int e = arr[i];
	int p = i;

	while(p>0 && arr[p-1]>e){
		arr[p]=arr[p-1];
		p--;
		}
	arr[p]=e;
	}
}


void Print(int arr[], int n){
printf("The sorted array is: \n");
for(int i=0;i<n;i++){
	printf("%d ", arr[i]);
}

printf("\n \n");
return;
}

