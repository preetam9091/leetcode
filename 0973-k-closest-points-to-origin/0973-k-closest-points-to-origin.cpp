class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       int n = points.size();
       vector<pair<int, int>> v(n);
       vector<vector<int>> answer;
       for(int i=0; i<n; i++){
        v[i].first = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
        v[i].second = i;
       } 
       sort(v.begin(), v.end());
       for(int i=0; i<k; i++){
            answer.push_back(points[v[i].second]);
       }
       return answer;
    }
};