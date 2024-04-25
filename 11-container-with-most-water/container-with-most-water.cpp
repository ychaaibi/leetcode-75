class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, p1 = 0, p2 = height.size() - 1;
        
        while ( p1 < p2 )
        {
            ans = max(min(height[p1], height[p2]) * ( p2 - p1 ), ans );
            
            if ( height[p1] < height[p2] )
                p1++;
            else
                p2--;
        }
        return ( ans );
    }
};