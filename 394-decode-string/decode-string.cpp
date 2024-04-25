class Solution {
public:
    
    string decodeString(string s) {
        stack<char> st;
        
        for ( int i=0; i<s.length(); i++ )
        {
            if ( s[i] != ']' )
                st.push( s[i] );
            else
            {
                string curr;
                
                curr.reserve(1000);
                
                while ( st.top() != '[')
                {
                    curr.push_back( st.top() );
                    st.pop();
                }
                
                reverse(curr.begin(), curr.end());
                st.pop();
                
                int num = 0, mult = 1;

                while ( !st.empty() and isdigit( st.top() ) )
                {
                    num += ( ( st.top() - '0' ) * mult );
                    mult *= 10;
                    st.pop();
                }
                
                for ( int k=0; k<num; k++ )
                    for ( int j=0; j<curr.length(); j++ )
                        st.push( curr[j] );
            }
        }
        
        
        string ans( st.size(), ' ' );
        
        for ( int i=ans.size() - 1; i>=0; i-- )
        {
            ans[i] = st.top();
            st.pop();
        }
        
        return ( ans );
    }
};