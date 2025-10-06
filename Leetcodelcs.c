int longestCommonSubsequence(char* text1, char* text2){
    int n = strlen(text1);
    int m = strlen(text2);
    // Always keep dp for the shorter string to save memory
    if(m > n){
        char* tmp = text1; 
        text1 = text2; 
        text2 = tmp;
        int t = n; 
        n = m; 
        m = t;
    }
    int* prev = (int*)calloc(m + 1, sizeof(int));
    int* curr = (int*)calloc(m + 1, sizeof(int));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = (prev[j] > curr[j - 1]) ? prev[j] : curr[j - 1];
        }
        // Swap rows
        int* temp = prev;
        prev = curr;
        curr = temp;
    }
    int result = prev[m];
    free(prev);
    free(curr);
    return result;

}
