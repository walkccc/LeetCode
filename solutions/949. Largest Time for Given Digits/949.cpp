class Solution {
 public:
  string largestTimeFromDigits(vector<int>& arr) {
    string ans;

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) {
          if (i == j || i == k || j == k)
            continue;
          const string hours = to_string(arr[i]) + to_string(arr[j]);
          const string minutes =
              to_string(arr[k]) + to_string(arr[6 - i - j - k]);
          if (hours < "24" && minutes < "60")
            ans = max(ans, hours + ':' + minutes);
        }

    return ans;
  }
};
