class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp( nums.size( ) );

        if ( nums.size() == 1 )
            return ( nums[0] );

        dp[0] = nums[0], dp[1] = nums[1];

        for ( int i=2; i<nums.size(); i++ )
        {
            dp[i] = nums[i];

            for ( int j=i - 2; j>=0; j-- )
                dp[i] = max( dp[i], nums[i] + dp[j] );
        }


        return ( max( dp[dp.size() - 1], dp[dp.size() - 2] ) );
    }
};