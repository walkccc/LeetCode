class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int ans = 0;

    sort(people.begin(), people.end());

    for (int i = 0, j = people.size() - 1; i <= j; ++ans) {
      const int remain = limit - people[j--];
      if (people[i] <= remain)
        ++i;
    }

    return ans;
  }
};
