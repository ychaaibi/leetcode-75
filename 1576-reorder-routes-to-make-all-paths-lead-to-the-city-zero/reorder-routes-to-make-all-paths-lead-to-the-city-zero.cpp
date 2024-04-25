class Solution {
public:
    int ans = 0;

    void    dfs( int node, vector<vector<pair<int,int>>>& graph, vector<bool>& vis )
    {
        vis[node] = true;

        for ( int i=0; i < graph[node].size(); i++ )
        {
            if ( vis[graph[node][i].first] )
                continue ;

            vis[graph[node][i].first] = true;
            ans += graph[node][i].second;
            dfs( graph[node][i].first, graph, vis );
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph( n );

        for ( int i=0; i<connections.size(); i++ )
        {
            graph[connections[i][0]].push_back( make_pair( connections[i][1], 1) );
            graph[connections[i][1]].push_back( make_pair( connections[i][0], 0) );
        }

        vector<bool> vis(n, false);

        dfs( 0, graph, vis );

        return ( ans );
    }
};