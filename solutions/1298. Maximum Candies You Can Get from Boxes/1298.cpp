class Solution {
 public:
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    int ans = 0;
    queue<int> q;
    vector<bool> reachedClosedBoxes(status.size());

    auto pushBoxesIfPossible = [&status, &q,
                                &reachedClosedBoxes](const vector<int>& boxes) {
      for (const int box : boxes)
        if (status[box])
          q.push(box);
        else
          reachedClosedBoxes[box] = true;
    };

    pushBoxesIfPossible(initialBoxes);

    while (!q.empty()) {
      const int currBox = q.front();
      q.pop();

      // Add the candies.
      ans += candies[currBox];

      // Push `reachedClosedBoxes` by `key` obtained in this turn and change
      // their statuses.
      for (const int key : keys[currBox]) {
        if (!status[key] && reachedClosedBoxes[key])
          q.push(key);
        status[key] = 1;  // boxes[key] is now open.
      }

      // Push the boxes contained in the `currBox`.
      pushBoxesIfPossible(containedBoxes[currBox]);
    }

    return ans;
  }
};
