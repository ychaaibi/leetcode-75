class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = 0;
        
        for ( int i=0; i<nums.size(); i++ )
            right += nums[i];
        
        for ( int i=0; i<nums.size(); i++ )
        {
            if ( left == right - nums[i] )
                return ( i );
            left += nums[i], right -= nums[i];
        }
        
        return ( -1 );
    }
};