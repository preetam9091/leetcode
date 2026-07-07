class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        stack<pair<int , int>> st;
        for(int i=0; i<n; i++){
            int index = 0;
            if(st.empty()) st.push({i, heights[i]});
            else if(st.top().second<=heights[i]){
                st.push({i, heights[i]});
            }else{
                while(!st.empty() && st.top().second>heights[i]){
                    if(!st.empty() && st.top().second*(i-st.top().first)>maxarea){
                        maxarea = st.top().second*(i-st.top().first);
                    } index = st.top().first;
                    st.pop();
                }
                if(st.empty()){
                    st.push({0, heights[i]});
                }else{
                    st.push({index, heights[i]});
                }
            }
        }
        while(!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            maxarea = max(maxarea, height*(n-index));
        }
        return maxarea;
    }  
};