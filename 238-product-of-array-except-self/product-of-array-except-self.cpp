class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans( nums.size(), 1);
        
        ans.back() = nums.back();
        
        for ( int i=nums.size() - 2; i>=0; i-- )
            ans[i] = ans[i + 1] * nums[i];
        
        int mult = 1;
        
        for ( int i=0; i<nums.size(); i++ )
            ans[i] = mult * ( ( i + 1 == nums.size() ) ? 1 : ans[i + 1] ), mult *= nums[i];
             
        return (ans);
    }
};