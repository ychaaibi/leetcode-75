class Solution {
public:
    int MOD = 1e9 + 7;

    int numTilings(int n) {
        vector<long long> dp(n + 4);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for ( int i=4; i<=n; i++ )
            dp[i] = ( ( dp[i - 1] * 2 ) % MOD + dp[i - 3] ) % MOD;
        
        return ( dp[n] );
    }
};
