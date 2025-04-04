class MajorityChecker {
 public:
  MajorityChecker(vector<int>& arr) : arr(arr) {
    for (int i = 0; i < arr.size(); ++i)
      numToIndices[arr[i]].push_back(i);
  }

  int query(int left, int right, int threshold) {
    for (int i = 0; i < kTimes; ++i) {
      const int randIndex = rand() % (right - left + 1) + left;
      const int num = arr[randIndex];
      const vector<int>& indices = numToIndices[num];
      const auto lit = ranges::lower_bound(indices, left);
      const auto rit = ranges::upper_bound(indices, right);
      if (rit - lit >= threshold)
        return num;
    }

    return -1;
  }

 private:
  const vector<int> arr;
  static constexpr int kTimes = 20;  // 2^kTimes >> |arr| = n
  unordered_map<int, vector<int>> numToIndices;
};
