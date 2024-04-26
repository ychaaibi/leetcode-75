class StockSpanner {
public:
    stack<pair<int,int>>  val;

    StockSpanner() {

        
    }
    
    int next(int price) {
        int _val = 1;

        while ( val.size() and val.top().second <= price )
        {
            _val += val.top().first;
            val.pop();
        }
        
        val.push(make_pair(_val, price));

        return ( _val );
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */