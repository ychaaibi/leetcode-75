class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        
        double ans;
        
        for ( int i=0; i<k; i++ )
            sum += nums[i];
        
        ans = (double)sum / k;
        
        for ( int i=k; i<nums.size(); i++ )
        {
            sum = sum + nums[i] - nums[i - k];
            ans = max(ans, (double)sum / k);
        }
        
        return ( ans );
    }
};