class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int left=0;
        for(int right=1;right<prices.size();right++){
            if(prices[left]<prices[right]){
                int currentprice=prices[right]-prices[left];
                max_profit=max(max_profit,currentprice);
            }
            else{
                left=right;
            }
        }
        return max_profit;
    }
};