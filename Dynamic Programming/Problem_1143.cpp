//LONGEST COMMON SUBSEQUENCE
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //vector<vector<int>> L(m+1, vector<int>(n+1));
        int L[1001][1001];

    
        for(int i = 0; i<=m; i++){
            L[i][0]=0;
        }
        for(int j = 0; j<=n; j++){
            L[0][j]=0;
        }
        for(int i = 1 ; i<=m; i++){
            for(int j=1; j<=n; j++){
                if (text1[i-1]==text2[j-1]){
                    L[i][j] = L[i-1][j-1]+1;
                }
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
            
        }
        return L[m][n];
        
    }
};
