class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    const int maxCandy = ranges::max(candies);

    for (const int candy : candies)
      ans.push_back(candy + extraCandies >= maxCandy);

    return ans;
  }
};
