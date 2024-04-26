class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int mn = points[0][0], mx = points[0][1];

        int ans = 1;

        for ( int i=1; i<points.size(); i++ )
        {
            if ( (points[i][0] >= mn and points[i][0] <= mx )
                or (points[i][1] >= mn and points[i][1] <= mx ) )
                mn = max(mn, points[i][0] ), mx = min(mx, points[i][1] );
            else
            {
                mn = points[i][0], mx = points[i][1];
                ans++;
            }
        }

        return ( ans );
    }
};