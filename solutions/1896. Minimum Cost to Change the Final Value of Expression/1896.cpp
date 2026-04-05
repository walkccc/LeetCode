class Solution {
 public:
  int minOperationsToFlip(string expression) {
    // [(the expression, the cost to toggle the expression)]
    stack<pair<char, int>> stack;
    pair<char, int> lastPair;

    for (const char e : expression) {
      if (e == '(' || e == '&' || e == '|') {
        // These aren't expressions, so the cost is meaningless.
        stack.push({e, 0});
        continue;
      }
      if (e == ')') {
        lastPair = stack.top();
        stack.pop();
        stack.pop();  // Pop '('.
      } else {        // e == '0' || e == '1'
        // Store the '0' or '1'. The cost to change their values is just 1,
        // whether it's changing '0' to '1' or '1' to '0'.
        lastPair = {e, 1};
      }
      if (!stack.empty() &&
          (stack.top().first == '&' || stack.top().first == '|')) {
        const char op = stack.top().first;
        stack.pop();
        const auto [a, costA] = stack.top();
        stack.pop();
        const auto [b, costB] = lastPair;
        // Determine the cost to toggle op(a, b).
        if (op == '&') {
          if (a == '0' && b == '0')
            // Change '&' to '|' and a|b to '1'.
            lastPair = {'0', 1 + min(costA, costB)};
          else if (a == '0' && b == '1')
            // Change '&' to '|'.
            lastPair = {'0', 1};
          else if (a == '1' && b == '0')
            // Change '&' to '|'.
            lastPair = {'0', 1};
          else  // a == '1' and b == '1'
            // Change a|b to '0'.
            lastPair = {'1', min(costA, costB)};
        } else {  // op == '|'
          if (a == '0' && b == '0')
            // Change a|b to '1'.
            lastPair = {'0', min(costA, costB)};
          else if (a == '0' && b == '1')
            // Change '|' to '&'.
            lastPair = {'1', 1};
          else if (a == '1' && b == '0')
            // Change '|' to '&'.
            lastPair = {'1', 1};
          else  // a == '1' and b == '1'
            // Change '|' to '&' and a|b to '0'.
            lastPair = {'1', 1 + min(costA, costB)};
        }
      }
      stack.push(lastPair);
    }

    return stack.top().second;
  }
};
