class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int ans = 0;

    ranges::sort(people);

    for (int i = 0, j = people.size() - 1; i <= j; ++ans) {
      const int remain = limit - people[j--];
      if (people[i] <= remain)
        ++i;
    }

    return ans;
  }
};
