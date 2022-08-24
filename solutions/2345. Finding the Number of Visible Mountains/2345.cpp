class Solution {
 public:
  int visibleMountains(vector<vector<int>>& peaks) {
    const vector<pair<int, int>> A = deDuplicates(peaks);
    stack<int> stack;

    for (int i = 0; i < A.size(); ++i) {
      while (!stack.empty() && isHidden(A[stack.top()], A[i]))
        stack.pop();
      if (!stack.empty() && isHidden(A[i], A[stack.top()]))
        continue;
      stack.push(i);
    }

    return stack.size();
  }

 private:
  vector<pair<int, int>> deDuplicates(const vector<vector<int>>& peaks) {
    vector<pair<int, int>> A;
    unordered_map<pair<int, int>, int, pairHash> count;

    for (const auto& peak : peaks)
      ++count[{peak[0], peak[1]}];

    for (const auto& [k, v] : count)
      if (v == 1)
        A.push_back(k);

    sort(begin(A), end(A));
    return A;
  }

  bool isHidden(const pair<int, int>& peak1, const pair<int, int>& peak2) {
    const auto& [x1, y1] = peak1;
    const auto& [x2, y2] = peak2;
    return x1 - y1 >= x2 - y2 && x1 + y1 <= x2 + y2;
  }

  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
