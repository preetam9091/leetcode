class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
    }
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
    }
    
    double findMedian() {
        if((maxheap.size()+minheap.size())%2==0){
            return (double)(maxheap.top()+minheap.top())/2;
        }else{
            return (double)maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */