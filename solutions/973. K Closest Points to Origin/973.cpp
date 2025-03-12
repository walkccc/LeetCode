class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    auto compare = [&](const vector<int>& a, const vector<int>& b) {
      return squareDist(a) < squareDist(b);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(
        compare);

    for (const vector<int>& point : points) {
      maxHeap.push(point);
      if (maxHeap.size() > k)
        maxHeap.pop();
    }

    while (!maxHeap.empty())
      ans.push_back(maxHeap.top()), maxHeap.pop();

    return ans;
  };

 private:
  int squareDist(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
  }
};
