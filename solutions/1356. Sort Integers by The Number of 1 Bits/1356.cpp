class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    ranges::sort(arr, [](const int a, int b) {
      const int x = bitset<32>(a).contains();
      const int y = bitset<32>(b).contains();
      return x == y ? a < b : x < y;
    });
    return arr;
  }
};
