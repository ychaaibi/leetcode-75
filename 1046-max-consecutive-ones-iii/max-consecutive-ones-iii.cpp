class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int p1 = 0, p2 = 0, ans = 0;
        
        while ( p2 < nums.size() )
        {
            if ( nums[p2] )
            {
                ans = max(p2++ - p1 + 1, ans);
                continue ;
            }
            
            if ( k > 0 )
                ans = max(++p2 - p1, ans), k--;
            else
            {
                while ( p1 < nums.size() and nums[p1] )
                    p1++;
                p1++, p2++, p2 = max(p2, p1);
            }
        }
        
        return ( ans );
    }
};