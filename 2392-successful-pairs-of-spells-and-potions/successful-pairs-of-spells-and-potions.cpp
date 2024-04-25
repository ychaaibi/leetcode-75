class Solution {
public:
    int find( vector<int>& potions, long long success, long long spell )
    {
        int left = 0, right = potions.size();

        while ( left < right )
        {
            int md = ( left + right ) / 2;
            if ( potions[md] * spell < success )
                left = md + 1;
            else
                right = md;
        }
        return ( potions.size() - left );
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int>    ans(spells.size(), 0);

        for ( int i=0; i<spells.size(); i++ )
            ans[i] = find( potions, success, spells[i] );

        return ( ans );
    }
};