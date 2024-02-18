class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int ans = 1;
    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[i - 1]) {
        increasing = decreasing + 1;
        decreasing = 1;
      } else if (arr[i] < arr[i - 1]) {
        decreasing = increasing + 1;
        increasing = 1;
      } else {
        increasing = 1;
        decreasing = 1;
      }
      ans = max({ans, increasing, decreasing});
    }

    return ans;
  }
};
