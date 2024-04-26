class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp( grid.size(), vector<int>(grid.size(), INT_MAX) );

        dp.front() = grid.front();

        for ( int i=1; i<grid.size(); i++ )
        {
            for ( int j=0; j<grid[0].size(); j++ )
            {
                for ( int _j=0; _j<grid[0].size(); _j++ )
                {
                    if ( j == _j )
                        continue ;
                    dp[i][j] = min( dp[i][j], dp[i - 1][_j] + grid[i][j] );
                }
            }
        }


        int ans = INT_MAX;
        
        for ( int j=0; j<grid[0].size(); j++ )
            ans = min( ans, dp.back()[j] );

        return ( ans );
    }
};