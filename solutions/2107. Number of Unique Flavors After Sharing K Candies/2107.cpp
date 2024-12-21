class Solution {
 public:
  int shareCandies(vector<int>& candies, int k) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int candy : candies)
      ++count[candy];

    int unique = count.size();

    for (int i = 0; i < candies.size(); ++i) {
      if (--count[candies[i]] == 0) {
        count.erase(candies[i]);
        --unique;
      }
      if (i >= k && ++count[candies[i - k]] == 1)
        ++unique;
      if (i >= k - 1)
        ans = max(ans, unique);
    }

    return ans;
  }
};
