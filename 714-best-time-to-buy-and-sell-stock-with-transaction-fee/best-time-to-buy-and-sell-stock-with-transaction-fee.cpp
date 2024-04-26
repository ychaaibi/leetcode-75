class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell1=0, sell2=-5 * 1e5 - 1, sell_day;

        for ( int i=0; i<prices.size(); i++ )
            sell_day = sell1, sell1 = max( sell1, sell2 + prices[i] ), sell2 = max( sell2, sell_day - prices[i] - fee );

        return ( sell1 );
    }
};
