class Solution {
 public:
  int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    int ans = 0;
    using P = pair<int, int>;
    // (leftToRight + rightToLeft, i)
    priority_queue<P> leftBridgeQueue;
    priority_queue<P> rightBridgeQueue;
    // (time to be idle, i)
    priority_queue<P, vector<P>, greater<>> leftWorkers;
    priority_queue<P, vector<P>, greater<>> rightWorkers;

    for (int i = 0; i < k; ++i)
      leftBridgeQueue.emplace(
          /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i);

    while (n > 0 || !rightBridgeQueue.empty() || !rightWorkers.empty()) {
      // Idle left workers get on the left bridge.
      while (!leftWorkers.empty() && leftWorkers.top().first <= ans) {
        const int i = leftWorkers.top().second;
        leftWorkers.pop();
        leftBridgeQueue.emplace(
            /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i);
      }
      // Idle right workers get on the right bridge.
      while (!rightWorkers.empty() && rightWorkers.top().first <= ans) {
        const int i = rightWorkers.top().second;
        rightWorkers.pop();
        rightBridgeQueue.emplace(
            /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i);
      }

      if (!rightBridgeQueue.empty()) {
        // If the bridge is free, the worker waiting on the right side of the
        // bridge gets to cross the bridge. If more than one worker is waiting
        // on the right side, the one with the lowest efficiency crosses first.
        const int i = rightBridgeQueue.top().second;
        rightBridgeQueue.pop();
        ans += /*rightToLeft*/ time[i][2];
        leftWorkers.emplace(ans + /*putNew*/ time[i][3], i);
      } else if (!leftBridgeQueue.empty() && n > 0) {
        // If the bridge is free and no worker is waiting on the right side, and
        // at least one box remains at the old warehouse, the worker on the left
        // side of the river gets to cross the bridge. If more than one worker
        // is waiting on the left side, the one with the lowest efficiency
        // crosses first.
        const int i = leftBridgeQueue.top().second;
        leftBridgeQueue.pop();
        ans += /*leftToRight*/ time[i][0];
        rightWorkers.emplace(ans + /*pickOld*/ time[i][1], i);
        --n;
      } else {
        // Advance the time of the last crossing worker.
        ans = min(
            !leftWorkers.empty() && n > 0 ? leftWorkers.top().first : INT_MAX,
            !rightWorkers.empty() ? rightWorkers.top().first : INT_MAX);
      }
    }

    return ans;
  }
};
