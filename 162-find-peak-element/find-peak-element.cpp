class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0, right=nums.size() - 1;

        while ( left < right )
        {
            int md = ( left + right ) / 2;

            if ( ( md == nums.size() - 1 or nums[md] > nums[md + 1] )
                and ( md == 0 or nums[md] > nums[md - 1] ) )
                return ( md );
            else if ( !md or nums[md] > nums[md - 1] )
                left = md + 1;
            else
                right = md;
        }

        return ( left );
    }
};