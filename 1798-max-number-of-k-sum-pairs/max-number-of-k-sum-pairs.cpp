class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>  mp;
        
        for ( int i=0; i<nums.size(); i++ )
            mp[nums[i]]++;
        
        int         ans = 0;
        
        for ( auto& [num,count] : mp )
        {
            auto next = mp.find(k - num);
            
            if ( next == mp.end() )
                continue ;
            
            if ( k - num != num )
            {
                int ops = min(count, next->second);
                
                ans += ops;
                
                count -= ops;
                next->second -= ops;
            }
            else
            {
                ans += (count / 2);
                count = count % 2;
            }
        }
        
        return ( ans );
    }
};