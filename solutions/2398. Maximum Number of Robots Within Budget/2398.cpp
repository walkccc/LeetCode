class Solution {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                    long long budget) {
    long long cost = 0;
    deque<int> dq;  // max queue storing chargeTimes[i]

    int j = 0;  // window's range := [i..j], so k = i - j + 1
    for (int i = 0; i < chargeTimes.size(); ++i) {
      cost += runningCosts[i];
      while (!dq.empty() && dq.back() < chargeTimes[i])
        dq.pop_back();
      dq.push_back(chargeTimes[i]);
      if (dq.front() + (i - j + 1) * cost > budget) {
        if (dq.front() == chargeTimes[j])
          dq.pop_front();
        cost -= runningCosts[j++];
      }
    }

    return chargeTimes.size() - j;
  }
};
