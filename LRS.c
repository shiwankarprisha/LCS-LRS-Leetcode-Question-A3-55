//Program to find Longest Repeating Subsequence(LRS) in a given string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
//First we'll create a cost matrix to store length of LRS
//And create a b table to store the direction of movement
int cost[MAX][MAX];
char b[MAX][MAX];
void LRS(char *X, int m){
    for(int i = 0; i <= m; i++)
        cost[i][0] = 0;
    for(int j = 0; j <= m; j++)
        cost[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(X[i-1] == X[j-1] && i != j){
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
//Function to print the LRS
void printLRS(char b[MAX][MAX], char *X, int i, int j){
    if(i == 0 || j == 0)
        return; // base case

    if(b[i][j] == 'd'){ // diagonal (match)
        printLRS(b, X, i-1, j-1);
        printf("%c", X[i-1]);
    }
    else if(b[i][j] == 'v'){ // vertical
        printLRS(b, X, i-1, j);
    }
    else if(b[i][j] == 'h'){ // horizontal
        printLRS(b, X, i, j-1);
    }
}
int main(){
    char X[MAX];
    printf("Enter the string: ");
    scanf("%s", X);
    int m = strlen(X);
    LRS(X, m);
    printf("Length of Longest Repeating Subsequence: %d\n", cost[m][m]);
    printf("Longest Repeating Subsequence: ");
    printLRS(b, X, m, m);
    return 0;
}