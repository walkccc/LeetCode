class SparseVector {
 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i])
        indexToNum[i] = nums[i];
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    if (indexToNum.size() < vec.indexToNum.size())
      return vec.dotProduct(*this);

    int ans = 0;

    for (const auto& [index, num] : vec.indexToNum)
      if (indexToNum.count(index))
        ans += num * indexToNum[index];

    return ans;
  }

 private:
  unordered_map<int, int> indexToNum;  // {index: num}
};
