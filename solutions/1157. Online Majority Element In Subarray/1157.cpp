class MajorityChecker {
 public:
  MajorityChecker(vector<int>& arr) : A(arr) {
    for (int i = 0; i < A.size(); ++i)
      numToIndices[A[i]].push_back(i);
  }

  int query(int left, int right, int threshold) {
    for (int i = 0; i < kTimes; ++i) {
      const int num = A[rand() % A.size()];
      const vector<int>& indices = numToIndices[num];
      const auto lit = ranges::lower_bound(indices, left);
      const auto rit = ranges::upper_bound(indices, right);
      if (rit - lit >= threshold)
        return num;
    }

    return -1;
  }

 private:
  const vector<int> A;
  static constexpr int kTimes = 20;  // 2^kTimes >> A.size() = n
  unordered_map<int, vector<int>> numToIndices;
};
