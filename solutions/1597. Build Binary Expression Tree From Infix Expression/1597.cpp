class Solution {
 public:
  Node* expTree(string s) {
    stack<Node*> nodes;  // stores nodes (new Node(val))
    stack<char> ops;     // stores operators and parentheses

    for (const char c : s)
      if (isdigit(c)) {
        nodes.push(new Node(c));
      } else if (c == '(') {
        ops.push(c);
      } else if (c == ')') {
        while (ops.top() != '(')
          nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));
        ops.pop();  // remove '('
      } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        while (!ops.empty() && compare(ops.top(), c))
          nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));
        ops.push(c);
      }

    while (!ops.empty())
      nodes.push(buildNode(pop(ops), pop(nodes), pop(nodes)));

    return nodes.top();
  }

 private:
  Node* buildNode(char op, Node* right, Node* left) {
    return new Node(op, left, right);
  }

  // return true if op1 is a operator and priority(op1) >= priority(op2)
  bool compare(char op1, char op2) {
    if (op1 == '(' || op1 == ')') return false;
    return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
  }

  char pop(stack<char>& ops) {
    const char op = ops.top(); ops.pop();
    return op;
  }

  Node* pop(stack<Node*>& nodes) {
    Node* node = nodes.top(); nodes.pop();
    return node;
  }
};
