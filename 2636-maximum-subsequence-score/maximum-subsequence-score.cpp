class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, sum = 0;
        
        vector<pair<int,int>>                               small( nums2.size() );
        priority_queue<int, vector<int>, greater<int>>      pq;

        for ( int i=0; i<nums2.size(); i++ )
            small[i] = make_pair( nums2[i], i );
        
        sort(small.begin(), small.end());

        for ( int i=(int)nums1.size() - 1; i>=(int)nums1.size() - k; i-- )
        {
            sum += nums1[small[i].second];
            pq.push(nums1[small[i].second]);
        }

        ans = sum * small[nums1.size() - k].first;

        for ( int i=(int)nums1.size() - k - 1; i>=0; i-- )
        {
            sum = sum - pq.top() + nums1[small[i].second];

            pq.pop();
            pq.push( nums1[small[i].second] );

            ans = max(ans, sum * small[i].first);
        }

        return ( ans );
    }
};