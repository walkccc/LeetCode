struct T {
  int size;
  int right;
  T(int size, int right) : size(size), right(right) {}
};

class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    vector<int> ans(queries.size(), -1);
    auto compare = [](const T& a, const T& b) { return a.size > b.size; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    vector<vector<int>> qs;

    for (int i = 0; i < queries.size(); ++i)
      qs.push_back({queries[i], i});

    ranges::sort(intervals);
    ranges::sort(qs);

    int i = 0;  // intervals' index
    for (const vector<int>& q : qs) {
      while (i < intervals.size() && intervals[i][0] <= q[0]) {
        minHeap.emplace(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]);
        ++i;
      }
      while (!minHeap.empty() && minHeap.top().right < q[0])
        minHeap.pop();
      if (!minHeap.empty())
        ans[q[1]] = minHeap.top().size;
    }

    return ans;
  }
};
