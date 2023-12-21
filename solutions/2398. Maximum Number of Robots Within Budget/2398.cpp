class Solution {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                    long long budget) {
    long long cost = 0;
    deque<int> maxQ;  // Stores `chargeTimes[i]`.

    int j = 0;  // window's range := [i..j], so k = i - j + 1
    for (int i = 0; i < chargeTimes.size(); ++i) {
      cost += runningCosts[i];
      while (!maxQ.empty() && maxQ.back() < chargeTimes[i])
        maxQ.pop_back();
      maxQ.push_back(chargeTimes[i]);
      if (maxQ.front() + (i - j + 1) * cost > budget) {
        if (maxQ.front() == chargeTimes[j])
          maxQ.pop_front();
        cost -= runningCosts[j++];
      }
    }

    return chargeTimes.size() - j;
  }
};
