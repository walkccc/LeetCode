class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    vector<int> mem(stoneValue.size(), INT_MIN);
    const int score = stoneGameIII(stoneValue, 0, mem);
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }

 private:
  // Returns the maximum relative score Alice can make from stoneValue[i..n).
  int stoneGameIII(const vector<int>& stoneValue, int i, vector<int>& mem) {
    if (i == stoneValue.size())
      return 0;
    if (mem[i] > INT_MIN)
      return mem[i];

    int sum = 0;
    for (int j = i; j < i + 3 && j < stoneValue.size(); ++j) {
      sum += stoneValue[j];
      mem[i] = max(mem[i], sum - stoneGameIII(stoneValue, j + 1, mem));
    }

    return mem[i];
  };
};
