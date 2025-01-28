enum class Direction { kForward, kBackward };

class Solution {
 public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    int furthest = x + a + b;
    unordered_set<int> seenForward;
    unordered_set<int> seenBackward;

    for (const int pos : forbidden) {
      seenForward.insert(pos);
      seenBackward.insert(pos);
      furthest = max(furthest, pos + a + b);
    }

    // (direction, position)
    queue<pair<Direction, int>> q{{{Direction::kForward, 0}}};

    for (int ans = 0; !q.empty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [dir, pos] = q.front();
        q.pop();
        if (pos == x)
          return ans;
        const int forward = pos + a;
        const int backward = pos - b;
        if (forward <= furthest && seenForward.insert(forward).second)
          q.emplace(Direction::kForward, forward);
        // It cannot jump backward twice in a row.
        if (dir == Direction::kForward && backward >= 0 &&
            seenBackward.insert(backward).second)
          q.emplace(Direction::kBackward, backward);
      }

    return -1;
  }
};
