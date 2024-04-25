class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis( n, false );

        int ans = 0;
        for ( int i=0; i<n; i++ )
        {
            if ( vis[i] )
                continue ;
            ans++;


            queue<int>  q;

            q.push( i );
            vis[i] = true;

            while ( !q.empty() )
            {
                int curr = q.front();

                q.pop();
                for ( int c=0; c<n; c++ )
                {
                    if ( !isConnected[c][curr] or vis[c] )
                        continue ;
                
                    vis[c] = true;
                    q.push( c );
                }
            }
        }

        return ( ans );
    }
};