class SparseVector {
 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i])
        indexToNum[i] = nums[i];
  }

  // Returns the dot product of the two sparse vectors.
  int dotProduct(SparseVector& vec) {
    if (indexToNum.size() < vec.indexToNum.size())
      return vec.dotProduct(*this);

    int ans = 0;

    for (const auto& [index, num] : vec.indexToNum)
      if (const auto it = indexToNum.find(index); it != indexToNum.cend())
        ans += num * it->second;

    return ans;
  }

 private:
  unordered_map<int, int> indexToNum;  // {index: num}
};
