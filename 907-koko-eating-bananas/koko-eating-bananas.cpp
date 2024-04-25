class Solution {
public:
    int need( vector<int>& piles, int k )
    {
        int hours = 0;

        for ( int i=0; i<piles.size(); i++ )
            hours += ( piles[i] / k ) + !!(piles[i] % k);

        return ( hours );
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int right=piles[0], left = 1;

        for ( int i=0; i<piles.size(); i++ )
            right = max( right, piles[i] );
        
        while ( left < right )
        {
            int md = (left + right) / 2;

            if ( need( piles, md) > h )
                left = md + 1;
            else
                right = md;
        }

        return ( left );
    }
};