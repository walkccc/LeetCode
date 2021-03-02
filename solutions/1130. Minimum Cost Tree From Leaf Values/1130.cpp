class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    int ans = 0;
    vector<int> maxStack{INT_MAX};

    for (int a : arr) {
      while (maxStack.back() <= a) {
        int mid = maxStack.back();
        maxStack.pop_back();
        ans += mid * min(maxStack.back(), a);
      }
      maxStack.push_back(a);
    }

    for (int i = 2; i < maxStack.size(); ++i)
      ans += maxStack[i] * maxStack[i - 1];

    return ans;
  }
};
