class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>  st;
        
        for ( int i=0; i<asteroids.size(); i++ )
        {
            if ( asteroids[i] > 0 )
                st.push( asteroids[i] );
            else
            {
                while ( !st.empty() and st.top() > 0 and abs(st.top()) < abs(asteroids[i]) )
                    st.pop();

                if ( st.empty() or st.top() < 0 )
                    st.push( asteroids[i] );
                else if ( abs(st.top()) == abs( asteroids[i] ) )
                    st.pop();
                
            }
        }
        
        vector<int> ans(st.size());
        
        for ( int i=ans.size() - 1; i>=0; i-- )
        {
            ans[i] = st.top();
            st.pop();
        }
        
        return ( ans );
    }
};