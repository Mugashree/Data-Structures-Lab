//Program to remove prefixes to form distinct array


#include <cstdio>


int main(){


    printf("Enter the no. of test cases: \n");
    int t;
    scanf("%d", &t);


    while(t--){
        
        printf("Enter the no. of integers:\n");
        int n;
        scanf("%d", &n);
        int arr[n];
        int remove_count = 0;


        printf("Enter the elements: \n");
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }


        for(int i= 0; i < n; i++){
           for(int j = i +1; j<n; j++){
             if(arr[i] == arr[j]){
                remove_count = i + 1;
             }
        }
   }


    printf("Minimum prefix to remove : %d \n", remove_count);
}
}
