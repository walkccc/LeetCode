struct T {
  int i;
  int j;
  int num;  // matrix[i][j]
};

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto compare = [&](const T& a, const T& b) { return a.num > b.num; };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);

    for (int i = 0; i < k && i < matrix.size(); ++i)
      pq.push({i, 0, matrix[i][0]});

    while (k-- > 1) {
      const auto [i, j, _] = pq.top();
      pq.pop();
      if (j + 1 < matrix[0].size())
        pq.push({i, j + 1, matrix[i][j + 1]});
    }

    return pq.top().num;
  }
};
