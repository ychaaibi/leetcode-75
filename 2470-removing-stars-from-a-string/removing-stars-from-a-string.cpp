class Solution {
public:
    string removeStars(string s) {
        stack<int>  st;
        
        for ( int i=0; i<s.length(); i++ )
        {
            if ( s[i] != '*')
                st.push( s[i] );
            else if ( !st.empty() )
                st.pop();
        }
        
        string ans = string(st.size(), ' ');
        
        for ( int i=ans.size() - 1; i>=0; i-- )
        {
            ans[i] = st.top();
            st.pop();
        }
        
        
        return ( ans );
    }
};