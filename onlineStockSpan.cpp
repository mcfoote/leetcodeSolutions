#include<stack>


using std::stack;
using std::pair;

class StockSpanner {
public:

    stack<pair<int, int>> stk;

    StockSpanner() {
        
    }
    
    int next(int price) {

        int count = 0;

        while(stk.empty() == false && stk.top().first <= price) {
            count += stk.top().second;
            stk.pop();
        }

        count++;
        stk.push({price, count});

        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */