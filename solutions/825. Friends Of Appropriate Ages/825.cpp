class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int age : ages)
      ++count[age];

    for (const auto& [ageA, countA] : count)
      for (const auto& [ageB, countB] : count)
        if (request(ageA, ageB))
          if (ageA == ageB)
            ans += countA * (countB - 1);
          else
            ans += countA * countB;

    return ans;
  }

 private:
  bool request(int ageA, int ageB) {
    return !(ageB <= 0.5 * ageA + 7 || ageB > ageA || ageB > 100 && ageA < 100);
  }
};
