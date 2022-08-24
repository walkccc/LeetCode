class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>> kp;
        priority_queue<vector<int>> pq;
        for(int i=0;i<p.size();i++){
            int d = p[i][0]*p[i][0] + p[i][1]*p[i][1];
            pq.push({-1*d,p[i][0],p[i][1]});
        }
        for(int i=0;i<k;i++) {
            vector<int> t = pq.top();pq.pop();
            kp.push_back({t[1],t[2]});
        }
        
        return kp;
    }
};
