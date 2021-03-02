class SparseVector {
 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i])
        v.push_back({i, nums[i]});
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ans = 0;

    for (int i = 0, j = 0; i < v.size() && j < vec.v.size();)
      if (v[i].first == vec.v[j].first)
        ans += v[i++].second * vec.v[j++].second;
      else if (v[i].first < vec.v[j].first)
        ++i;
      else
        ++j;

    return ans;
  }

 private:
  vector<pair<int, int>> v;  //  [(index, num)]
};
