class Solution {
 public:
  int sumOfPowers(vector<int>& nums, int k) {
    const int n = nums.size();
    ranges::sort(nums);
    vector<vector<vector<vector<int>>>> mem(
        n + 1, vector<vector<vector<int>>>(
                   n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1))));
    return sumOfPowers(nums, 0, k, -1, -1, -1, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the sum of powers of all subsequences of nums[i..n) which
  // have length equal to k, where `lastPickedIndex` is the index of the last
  // picked number and nums[secondIndex] - nums[firstIndex] is the minimum power
  // so far.
  int sumOfPowers(const vector<int>& nums, int i, int k, int lastPickedIndex,
                  int firstIndex, int secondIndex,
                  vector<vector<vector<vector<int>>>>& mem) {
    if (k == 0)
      return nums[secondIndex] - nums[firstIndex];
    if (i == nums.size())
      return 0;
    const int a = hash(lastPickedIndex);
    const int b = hash(firstIndex);
    const int c = hash(secondIndex);
    if (mem[a][b][c][k] != -1)
      return mem[a][b][c][k];
    int newFirstIndex = firstIndex;
    int newSecondIndex = secondIndex;
    if (firstIndex == -1) {
      newFirstIndex = i;
    } else if (secondIndex == -1) {
      newSecondIndex = i;
    } else if (nums[i] - nums[lastPickedIndex] <
               nums[secondIndex] - nums[firstIndex]) {
      newFirstIndex = lastPickedIndex;
      newSecondIndex = i;
    }
    const int pick =
        sumOfPowers(nums, i + 1, k - 1, i, newFirstIndex, newSecondIndex, mem);
    const int skip = sumOfPowers(nums, i + 1, k, lastPickedIndex, firstIndex,
                                 secondIndex, mem);
    return mem[a][b][c][k] = (pick + skip) % kMod;
  }

  constexpr int hash(int x) {
    return x + 1;
  }
};
