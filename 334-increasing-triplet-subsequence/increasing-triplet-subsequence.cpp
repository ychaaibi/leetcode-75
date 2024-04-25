class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=-1, j=-1, k=-1;
        
        for ( int p=0; p<nums.size(); p++ )
        {
            if ( i == -1 )
                i = p;
            else if ( nums[p] < nums[i] )
                i = p;
            else if ( nums[p] > nums[i] and j == -1 )
                j = p;
            else if ( nums[p] > nums[i] and j != -1 and nums[p] < nums[j] )
                j = p;
            else if ( j != -1 and nums[p] > nums[j] )
                return ( true );
        }
        return ( false );
    }
};