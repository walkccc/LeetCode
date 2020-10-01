class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> ans;
    auto squareDistance = [](const vector<int>& p) {
      return p[0] * p[0] + p[1] * p[1];
    };
    auto compare = [&](const vector<int>& a, const vector<int>& b) {
      return squareDistance(a) < squareDistance(b);  // max-heap
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

    for (const vector<int>& point : points) {
      pq.push(point);
      if (pq.size() > K)
        pq.pop();
    }

    while (!pq.empty())
      ans.push_back(pq.top()), pq.pop();

    return ans;
  };
};