class Solution {
public:
    vector<string>  tele;
    vector<string>  ans;

    void    dfs(string& digits, string& curr, int index )
    {
        if ( index == digits.size() )
        {
            ans.push_back( curr );
            return ;
        }

        for ( int i=0; i<tele[digits[index] - '2'].size(); i++ )
        {
            curr.push_back( tele[digits[index] - '2'][i] );
            dfs(digits, curr, index + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        tele = { string("abc"), string("def"), string("ghi"), string("jkl"), string("mno"), string("pqrs"), string("tuv"), string("wxyz") };

        if ( digits.empty() )
            return ( vector<string>() );
            
        string curr;

        dfs( digits, curr, 0 );

        return ( ans );    
    }
};