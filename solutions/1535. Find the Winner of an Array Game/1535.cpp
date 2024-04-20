class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int ans = arr[0];
    int wins = 0;

    for (int i = 1; i < arr.size() && wins < k; ++i)
      if (arr[i] > ans) {
        ans = arr[i];
        wins = 1;
      } else {
        ++wins;
      }

    return ans;
  }
};
