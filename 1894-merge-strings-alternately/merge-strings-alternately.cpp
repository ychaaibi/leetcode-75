class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans(word1.length() + word2.length(), ' ');
        for (int i=0,j=0; i<max(word1.length(), word2.length()); i++)
        {
            if (i < word1.length())
                ans[j++] = word1[i];
            if (i < word2.length())
                ans[j++] = word2[i];
        }
        return (ans);
    }
};