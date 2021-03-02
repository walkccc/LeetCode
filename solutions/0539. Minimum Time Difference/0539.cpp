class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    int ans = 24 * 60;
    int first = 24 * 60;
    vector<bool> bucket(24 * 60);

    for (const string& time : timePoints) {
      const int num = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
      first = min(first, num);
      if (bucket[num])
        return 0;
      bucket[num] = true;
    }

    int prev = first;

    for (int i = first + 1; i < bucket.size(); ++i)
      if (bucket[i]) {
        ans = min(ans, i - prev);
        prev = i;
      }

    return min(ans, 24 * 60 - prev + first);
  }
};
