class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    const unordered_map<string, function<int(int, int)>> op{
        {"+", plus<int>()},
        {"-", minus<int>()},
        {"*", multiplies<int>()},
        {"/", divides<int>()}};

    for (const string& token : tokens)
      if (op.count(token)) {
        const int b = stack.top();
        stack.pop();
        const int a = stack.top();
        stack.pop();
        stack.push(op.at(token)(a, b));
      } else {
        stack.push(stoi(token));
      }

    return stack.top();
  }
};
