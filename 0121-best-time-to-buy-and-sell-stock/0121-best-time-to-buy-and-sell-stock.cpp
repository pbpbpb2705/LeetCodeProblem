class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind = prices.size() - 2, maxSell = prices[prices.size() - 1], ans = 0;
        while (ind >= 0) {
            if (prices[ind] > maxSell) {
                maxSell = prices[ind];
            }
            else {
                ans = max(ans, maxSell - prices[ind]);
            }

            --ind;
        }

        return ans;
    }
};