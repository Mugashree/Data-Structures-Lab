// Program to find maximum blocks in first tower


#include <cstdlib>
#include <cstdio>
#include <stack>
using namespace std;




int main(){


int t;
printf("Enter the no. of test cases: \n");
scanf("%d", &t);


while(t--){


int n;
printf("Enter the no. of towers: \n");
scanf("%d", &n);


stack <int> towers;
int blocks[n];


for(int i = 0; i<n; i++){
printf("Tower %d :", i + 1);
scanf("%d", &blocks[i]);
towers.push(blocks[i]);
}


int tower1 = blocks[0];
for(int i = 1; i < n; i++){
while(blocks[i] > 0 && blocks[i] > tower1){
tower1++;
blocks[i]--;
}
}


printf("The maximum blocks in Tower 1 after transfers is: %d\n", tower1);
}


return 0;


}
