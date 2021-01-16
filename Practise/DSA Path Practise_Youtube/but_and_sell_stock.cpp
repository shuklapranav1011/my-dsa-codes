#include <bits/stdc++.h>
using namespace std;
 
int maxProfit(vector<int>& prices) {
        int base_price = prices[0];
        int base_price_index = 0;
        int sell_price = -1;
        int sell_price_index = -1;
        int profit = 0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] < base_price){
                base_price = prices[i];
                base_price_index = i;
                sell_price = -1;
                sell_price_index = -1;
            }
            else if(prices[i] >= sell_price){
                sell_price = prices[i];
                sell_price_index = i;
            }
            
            if(sell_price_index > base_price_index)
                profit = max(profit,sell_price-base_price);
        }
        return profit;
    }

int main(){
	vector <int> prices = {7,1,5,3,6,4};
	cout<<maxProfit(prices)<<endl;
}
