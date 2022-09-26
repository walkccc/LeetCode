class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    for (int i = num.size() - 1; i >= 0; --i) {
      num[i] += k;
      k = num[i] / 10;
      num[i] %= 10;
    }

    while (k > 0) {
      num.insert(begin(num), k % 10);
      k /= 10;
    }

    return num;
  }
};
