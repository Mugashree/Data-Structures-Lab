//Program to calculate player score based on word uniqueness


#include <cstdio>
#include <cstring>


int main() {
    int t;
    printf("Enter the no. of test cases:\n");
    scanf("%d", &t);


    while (t--) {
        int n;
        printf("Enter the no. of words:\n");
        scanf("%d", &n);


        char player1[n][4];
        char player2[n][4];
        char player3[n][4];


        printf("Player 1:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player1[i]);
        }


        printf("Player 2:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player2[i]);
        }


        printf("Player 3:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player3[i]);
        }


        int match1[n] = {0}, match2[n] = {0}, match3[n] = {0};
        int points1[n] = {0}, points2[n] = {0}, points3[n] = {0};


        // Match and score for Player 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (strcmp(player1[i], player2[j]) == 0)
                    match1[i]++;
                if (strcmp(player1[i], player3[j]) == 0)
                    match1[i]++;
            }
            if (match1[i] == 0)
                points1[i] = 3;
            else if (match1[i] == 1)
                points1[i] = 1;
        }


        // Match and score for Player 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (strcmp(player2[i], player1[j]) == 0)
                    match2[i]++;
                if (strcmp(player2[i], player3[j]) == 0)
                    match2[i]++;
            }
            if (match2[i] == 0)
                points2[i] = 3;
            else if (match2[i] == 1)
                points2[i] = 1;
        }


        // Match and score for Player 3
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (strcmp(player3[i], player1[j]) == 0)
                    match3[i]++;
                if (strcmp(player3[i], player2[j]) == 0)
                    match3[i]++;
            }
            if (match3[i] == 0)
                points3[i] = 3;
            else if (match3[i] == 1)
                points3[i] = 1;
        }


        int score1 = 0, score2 = 0, score3 = 0;
        for (int i = 0; i < n; i++) {
            score1 += points1[i];
            score2 += points2[i];
            score3 += points3[i];
        }


        printf("Scores:\n");
        printf("Player 1: %d\n", score1);
        printf("Player 2: %d\n", score2);
        printf("Player 3: %d\n", score3);
    }


    return 0;
}
