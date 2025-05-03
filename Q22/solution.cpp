// Program to implement game of finding strength difference


#include <cstdio>


int main() {
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);


    while (t--) {
        int n;
        printf("Enter the number of participants: ");
        scanf("%d", &n);


        int strengths[n];
        printf("Enter the strengths of the participants, separated by spaces: ");
        for (int i = 0; i < n; ++i) {
            scanf("%d", &strengths[i]);
        }


        int max1 = -1, max2 = -1;
        for (int i = 0; i < n; ++i) {
            if (strengths[i] > max1) {
                max2 = max1;
                max1 = strengths[i];
            } else if (strengths[i] > max2 && strengths[i] != max1) {
                max2 = strengths[i];
            }
        }
        if (max2 == -1){
            max2 = max1;
        }


        printf("Output: ");
        for (int i = 0; i < n; ++i) {
            if (strengths[i] == max1 && max1 == max2) {
                printf("%d ", strengths[i] - max2);
            }
            else if (strengths[i] == max1) {
                printf("%d ", strengths[i] - max2);
            } else {
                printf("%d ", strengths[i] - max1);
            }
        }
        printf("\n");
    }


    return 0;
}
