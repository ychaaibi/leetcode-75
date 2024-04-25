class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>  count;
        unordered_map<int,int>  hash;
        
        for ( int i=0; i<arr.size(); i++ )
            hash[arr[i]]++;
        
        
        for ( auto& [k, v] : hash )
        {
            count[v]++;
            if ( count[v] > 1 )
                return ( false );
        }
        
        return ( true );
    }
};