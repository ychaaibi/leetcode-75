class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> >    dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i=0; i<text1.length(); i++)
        {
            for (int j=0; j<text2.length(); j++)
            {
                if (text1[i] == text2[j]) dp[i + 1][j + 1] = 1 + dp[i][j];
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return (dp[text1.length()][text2.length()]);
    }
};