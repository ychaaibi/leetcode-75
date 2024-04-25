class SmallestInfiniteSet {
public:
    vector<bool>        hash;
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        hash.resize(1001, true);

        for ( int i=1; i<=1000; i++ )
            pq.push( i );
    }
    
    int popSmallest() {
        int val = pq.top();

        hash[val] = false;
        pq.pop();

        return ( val );
    }
    
    void addBack(int num) {
        if ( !hash[num] )
        {
            hash[num] = true;
            pq.push( num );
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */