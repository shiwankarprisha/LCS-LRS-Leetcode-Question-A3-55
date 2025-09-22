//Program to find Longest Common Subsequence(LCS) with given two strings
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
//First we'll create a cost matrix to store length of LCS
//And create a b table to store the direction of movement
int cost[MAX][MAX];
char b[MAX][MAX];
void LCS(char *X, char *Y, int m, int n){
    for(int i = 0; i <= m; i++)
        cost[i][0] = 0;
    for(int j = 0; j <= n; j++)
        cost[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1]){
                cost[i][j] = cost[i-1][j-1] + 1;
                b[i][j] = 'd'; // diagonal
            }
            else if(cost[i-1][j] >= cost[i][j-1]){
                cost[i][j] = cost[i-1][j];
                b[i][j] = 'v'; // vertical
            }
            else{
                cost[i][j] = cost[i][j-1];
                b[i][j] = 'h'; // horizontal
            }
        }
    }
}
//Function to print the LCS
void printLCS(char b[MAX][MAX], char *X, int i, int j){
    if(i == 0 || j == 0)
        return; // base case

    if(b[i][j] == 'd'){ // diagonal (match)
        printLCS(b, X, i-1, j-1);
        printf("%c", X[i-1]);
    }
    else if(b[i][j] == 'v'){ // vertical
        printLCS(b, X, i-1, j);
    }
    else if(b[i][j] == 'h'){ // horizontal
        printLCS(b, X, i, j-1);
    }
}
int main(){
    char X[MAX], Y[MAX];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    LCS(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", cost[m][n]);
    printf("Longest Common Subsequence: ");
    printLCS(b, X, m, n);
    printf("\n");
    return 0;
}