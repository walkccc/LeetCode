class Solution {
 public:
  int maximumBeauty(vector<int>& flowers) {
    int ans = INT_MIN;
    int prefix = 0;
    unordered_map<int, int> flowerToPrefix;

    for (const int flower : flowers) {
      if (const auto it = flowerToPrefix.find(flower);
          it != flowerToPrefix.cend())
        ans = max(ans, prefix - it->second + flower * 2);
      prefix += max(0, flower);
      if (!flowerToPrefix.contains(flower))
        flowerToPrefix[flower] = prefix;
    }

    return ans;
  }
};
