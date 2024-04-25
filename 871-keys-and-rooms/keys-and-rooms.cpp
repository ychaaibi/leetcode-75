class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>    vis(rooms.size(), false);

        vis[0] = true;

        queue<int>  q;

        q.push( 0 );

        while ( !q.empty() )
        {
            int curr = q.front();

            q.pop();
            
            for ( int i=0; i<rooms[curr].size(); i++ )
            {
                if ( vis[rooms[curr][i]] )
                    continue ;

                q.push( rooms[curr][i] );
                vis[rooms[curr][i]] = true;
            }
        }

        for ( int i=0; i<vis.size(); i++ )
            if ( !vis[i] )
                return ( false );
        
        return ( true );
    }
};