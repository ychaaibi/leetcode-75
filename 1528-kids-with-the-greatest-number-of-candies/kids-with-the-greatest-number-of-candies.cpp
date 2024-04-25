class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        
        for ( int i=0; i<candies.size(); i++ )
            mx = max(candies[i], mx);
        
        vector<bool> ans( candies.size(), false) ;
        
        for ( int i=0; i<candies.size(); i++ )
            ans[i] = ( (candies[i] + extraCandies) >= mx );
        
        return ( ans );
    }
};