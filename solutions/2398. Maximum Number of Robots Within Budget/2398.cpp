class Solution {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                    long long budget) {
    long long cost = 0;
    deque<int> q;  // max queue storing chargeTimes[i]

    int j = 0;  // window's range := [i..j], so k = i - j + 1
    for (int i = 0; i < chargeTimes.size(); ++i) {
      cost += runningCosts[i];
      while (!q.empty() && q.back() < chargeTimes[i])
        q.pop_back();
      q.push_back(chargeTimes[i]);
      if (q.front() + (i - j + 1) * cost > budget) {
        if (q.front() == chargeTimes[j])
          q.pop_front();
        cost -= runningCosts[j++];
      }
    }

    return chargeTimes.size() - j;
  }
};
