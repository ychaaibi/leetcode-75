class Solution {
public:
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>  q;

        q.push( make_pair(entrance[0], entrance[1] ) );

        vector<vector<bool>> vis( maze.size(), vector<bool>( maze[0].size(), false) );

        vis[entrance[0]][entrance[1]] = true;

        int steps = 0;

        while ( !q.empty() )
        {
            int size = q.size();

            while ( size-- )
            {
                auto curr = q.front();

                q.pop();

                cout << curr.first << " " << curr.second << endl;
                if ( steps and 
                    (  curr.first + 1 == maze.size()
                    or curr.second + 1 == maze[0].size() 
                    or curr.first - 1 == -1
                    or curr.second - 1 == -1 ) )
                    return ( steps );
                
                for ( int i=0; i<4; i++ )
                {
                    if (  curr.first + dirs[i][0] == maze.size()
                        or curr.second + dirs[i][1]== maze[0].size()
                        or curr.first + dirs[i][0] == -1
                        or curr.second + dirs[i][1]== -1 )
                        continue ;

                    if ( vis[curr.first + dirs[i][0]][curr.second + dirs[i][1]] )
                        continue ;

                    if ( maze[curr.first + dirs[i][0]][curr.second + dirs[i][1]] != '.' )
                        continue ;

                    vis[curr.first + dirs[i][0]][curr.second + dirs[i][1]] = true;

                    q.push( make_pair( curr.first + dirs[i][0], curr.second + dirs[i][1] ) );
                }
            }
            cout << q.size() << endl;

            steps++;
        }
        return (-1);
    }
};