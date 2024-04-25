class Solution {
public:
    int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int                 count = 0;

        for ( int i=0; i<grid.size(); i++ )
        {
            for ( int j=0; j<grid[0].size(); j++ ){
                if ( grid[i][j] == 2 )
                    q.push( make_pair(i, j));
                else if ( grid[i][j] == 1 )
                    count++;
            }
        }

        int minutes = 0;

        while ( !q.empty() )
        {
            int size = q.size();

            while ( size-- )
            {
                auto curr = q.front();

                q.pop();

                for ( int i=0; i<4; i++ )
                {
                    if ( curr.first + dirs[i][0] == grid.size()
                        or curr.first + dirs[i][0] == -1 
                        or curr.second + dirs[i][1] == grid[0].size()
                        or curr.second + dirs[i][1] == -1 )
                        continue ;

                    if ( !grid[curr.first + dirs[i][0]][curr.second + dirs[i][1]] )
                        continue ;

                    if ( grid[curr.first + dirs[i][0]][curr.second + dirs[i][1]] == 2 )
                        continue ;

                    grid[curr.first + dirs[i][0]][curr.second + dirs[i][1]] = 2;

                    count--;
                    q.push( make_pair( curr.first + dirs[i][0], curr.second + dirs[i][1]) );
                }
            }

            minutes += !q.empty();
        }

        if ( !count )
            return ( minutes );
        return ( -1 );
    }
};