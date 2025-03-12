class Solution {
 public:
  int findDerangement(int n) {
    vector<int> mem(n + 1);
    return findDerangement(n, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int findDerangement(int i, vector<int>& mem) {
    if (i == 0)
      return 1;
    if (i == 1)
      return 0;
    if (mem[i] > 0)
      return mem[i];
    return mem[i] = (i - 1L) *
                    (findDerangement(i - 1, mem) +  //
                     findDerangement(i - 2, mem)) %
                    kMod;
  }
};
