class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> pair(n);
        stack<double> st;
        for(int i=0; i<n; i++){
            pair[i].first = target-position[i];
            pair[i].second = (double)pair[i].first/speed[i];
        }
        sort(pair.begin(), pair.end());
        double val = pair[0].second;
        for(auto& p : pair){
            st.push(p.second);
            if(st.size()>=2 && st.top()<=val){
                n--;
            }else{
                val = p.second;
            }
        }return n;
    }
};