class Solution {
public:
    map<string,vector<pair<string,double> > >   div;

    double  Bfs(string maqam, string bast)
    {
        queue<pair<string,double> >    q;
        set<string>                 vis;

        q.push(make_pair(bast, 1.000));
        vis.insert(bast);
        while (!q.empty())
        {
            double  res = q.front().second;
            bast = q.front().first;
            q.pop();

            if ( div.find( bast ) == div.end() )
                break ;

            for (int i=0; i<div[bast].size(); i++)
            {
                if (vis.find(div[bast][i].first) != vis.end()) continue ;

                if (div[bast][i].first == maqam)
                    return (res * div[bast][i].second);
                vis.insert(div[bast][i].first);
                q.push(make_pair(div[bast][i].first, res * div[bast][i].second));
            }
        }
        return (-1.000);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i=0; i<equations.size(); i++)
        {
            if (div.find(equations[i][1]) == div.end())
                div[equations[i][1]] = vector<pair<string,double> >();
            if (div.find(equations[i][0]) == div.end())
                div[equations[i][0]] = vector<pair<string,double> >();
            div[equations[i][1]].push_back(make_pair(equations[i][0],1 / values[i]));
            div[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
        }

        vector<double>   ans(queries.size(), -1.000 );

        for (int i=0; i<queries.size(); i++)
        {
            if (queries[i][0] == queries[i][1])
            {
                if (div.find(queries[i][0]) != div.end())
                    ans[i] = 1.000;
                else
                    ans[i] = -1.000;
            }
            else
                ans[i] = Bfs(queries[i][1], queries[i][0]);
        }
        return (ans);
    }
};