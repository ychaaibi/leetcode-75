class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c = 0;
        
        if ( !flowerbed[0] and ( ( flowerbed.size() > 1 and !flowerbed[1] ) or flowerbed.size() == 1 ) )
            flowerbed[0] = 1, n--;
        
        for ( int i=0; i<flowerbed.size(); i++ )
        {
            if ( flowerbed[i] == 0 )
                c++;
            else
            {
                n -= max(0, ( c - 2 ) / 2 + ( c - 2 ) % 2 );
                c = 0;
            }
        }
        
        n -= max(0, ( c - 1 ) / 2 + ( c - 1 ) % 2 );
        return ( n <= 0 );
            
    }
};