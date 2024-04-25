class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>   c;
        unordered_map<string,int>   r;
        
        for ( int i=0; i<grid.size(); i++ )
        {
            string curr;
            
            curr.reserve(grid.size() * 5);
            
            for ( int j=0; j<grid.size(); j++ )
            {
                curr += to_string(grid[i][j]);
                curr += ";";
            }
            
            r[curr]++;
        }
        
        for ( int j=0; j<grid.size(); j++ )
        {
            string curr;
            
            for ( int i=0; i<grid.size(); i++ )
            {
                curr += to_string(grid[i][j]);
                curr += ";";
            }
            
            c[curr]++;
        }
        
        int ans = 0;
        
        for ( auto& [k, v] : r )
        {
            auto search = c.find(k);
            
            if ( search == c.end() )
                continue ;
            
            ans += v * search->second;
        }
        
        return ( ans );
    }
};