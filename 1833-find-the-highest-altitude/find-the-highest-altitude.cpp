class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int point = 0;
        int heighest = 0;
        
        for ( int i=0; i<gain.size(); i++ )
            point += gain[i], heighest = max(heighest, point);
        
        
        return ( heighest );
    }
};