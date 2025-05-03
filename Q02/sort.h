// header file to sort arrays
#include <iostream>

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
