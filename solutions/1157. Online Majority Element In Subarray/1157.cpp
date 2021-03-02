class MajorityChecker {
 public:
  MajorityChecker(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
      map[arr[i]].push_back(i);
  }

  int query(int left, int right, int threshold) {
    for (auto& [num, indices] : map) {
      if (indices.size() < threshold)
        continue;
      auto it1 = lower_bound(indices.begin(), indices.end(), left);
      auto it2 = upper_bound(indices.begin(), indices.end(), right);
      if (it2 - it1 >= threshold)
        return num;
    }

    return -1;
  }

 private:
  unordered_map<int, vector<int>> map;
};
