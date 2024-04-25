class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        
        int c1 = 0, c2 = 0;
        
        for ( int i=0; i<nums.size(); i++ )
        {
            if ( nums[i] )
                c2++;
            else
            {
                if ( c1 )
                    ans = max(c1 + c2, ans);
                
                c1 = c2, c2 = 0;
            }
        }

        if ( ans or c1 )
            ans = max(c1 + c2, ans );
        else if ( c2 == nums.size() )
            ans = max(0, c2 - 1);
        else
            ans = c2;
        
        
        return ( ans );
    }
};