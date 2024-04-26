class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int p1 = 0, p2 = costs.size() - 1;
        long long   ans = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>    pq;
        
        for ( int i=0; i<candidates and p1 <= p2; i++ )
        {
            if ( p1 != p2 )
            {
                pq.push( make_pair(costs[p1], p1++ ) );
                pq.push( make_pair(costs[p2], p2--) );
            }
            else
                pq.push( make_pair(costs[p1], p1++ ) );
        }

        while ( k-- )
        {
            auto curr = pq.top();

            pq.pop();
            ans += curr.first;

            if ( p1 > p2 )
                continue ;

            if ( curr.second < p1 )
                pq.push( make_pair( costs[p1], p1++ ) );
            else
                pq.push( make_pair( costs[p2], p2-- ) );

        }
        return ( ans );
    }
};