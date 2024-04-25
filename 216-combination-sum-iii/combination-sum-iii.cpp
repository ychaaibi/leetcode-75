class Solution {
public:
    vector<vector<int>> ans;

    void combination( vector<int>& curr, int index, int k, int n)
    {
        if ( k == 0 )
        {
            if ( !n )
                ans.push_back( curr );
            return ;
        }
        
        if ( n < 0 or index == 10 )
            return ;

        curr.push_back( index );
        combination( curr, index + 1, k - 1, n - index );
        curr.pop_back();
        combination( curr, index + 1, k, n);
    }

   vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;

        combination( curr, 1, k, n );
        return ( ans );
    }
};