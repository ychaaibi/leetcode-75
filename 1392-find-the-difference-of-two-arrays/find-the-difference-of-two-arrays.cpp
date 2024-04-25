class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        
        ans[0].reserve(nums1.size());
        ans[1].reserve(nums2.size());
        
        unordered_set<int> hash1, hash2;
        
        for ( int i=0; i<nums1.size(); i++ )
            hash1.insert(nums1[i]);
        
        for ( int i=0; i<nums2.size(); i++ )
            hash2.insert(nums2[i]);

        for ( auto& k : hash1 )
            if ( hash2.find(k) == hash2.end() )
                ans[0].push_back( k );
        
        for ( auto& k : hash2 )
            if ( hash1.find(k) == hash1.end() )
                ans[1].push_back( k );
        
        return ( ans );
    }
};