class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int &i : stones){
            maxheap.push(i);
        }
        if(maxheap.size()==1){
            return maxheap.top();
        }
        while(maxheap.size()>1){
            int first = maxheap.top();
            maxheap.pop();
            int second = maxheap.top();
            maxheap.pop();
            if(first!=second){
                maxheap.push(abs(first-second));
            }
        }
        if(maxheap.empty()) return 0;
        return maxheap.top();
    }
};