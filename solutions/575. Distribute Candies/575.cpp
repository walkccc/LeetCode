class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    bitset<200001> bitset;

    for (const int candy : candies)
      bitset.set(candy + 100000);

    return min(candies.size() / 2, bitset.count());
  }
};
