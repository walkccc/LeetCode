class Solution {
 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    int ans = 0;
    int l = 0;
    int r = min(tasks.size(), workers.size());

    sort(begin(tasks), end(tasks));
    sort(begin(workers), end(workers));

    // can we finish k tasks?
    auto canComplete = [&](int k, int pillsLeft) {
      // k strongest workers
      map<int, int> sortedWorkers;
      for (int i = workers.size() - k; i < workers.size(); ++i)
        ++sortedWorkers[workers[i]];

      // out of the k smallest tasks
      // start from the biggest one
      for (int i = k - 1; i >= 0; --i) {
        // find the first worker that has strength >= tasks[i]
        auto it = sortedWorkers.lower_bound(tasks[i]);
        if (it != end(sortedWorkers)) {
          if (--(it->second) == 0)
            sortedWorkers.erase(it);
        } else if (pillsLeft > 0) {
          // find the first worker that has strength >= tasks[i] - strength
          it = sortedWorkers.lower_bound(tasks[i] - strength);
          if (it != end(sortedWorkers)) {
            if (--(it->second) == 0)
              sortedWorkers.erase(it);
            --pillsLeft;
          } else {
            return false;
          }
        } else {
          return false;
        }
      }

      return true;
    };

    while (l <= r) {
      const int m = (l + r) / 2;
      if (canComplete(m, pills)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }
};
