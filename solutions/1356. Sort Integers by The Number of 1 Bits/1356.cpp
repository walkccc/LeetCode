class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(begin(arr), end(arr), [](const int a, int b) {
      const int x = bitset<32>(a).count();
      const int y = bitset<32>(b).count();
      return x == y ? a < b : x < y;
    });
    return arr;
  }
};
