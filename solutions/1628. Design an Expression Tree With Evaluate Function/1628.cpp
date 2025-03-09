/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
 public:
  virtual ~Node() {};
  virtual int evaluate() const = 0;

 protected:
  // define your fields here
};

class ExpNode : public Node {
 public:
  ExpNode(const string& val, ExpNode* left, ExpNode* right)
      : val(val), left(left), right(right) {}

  int evaluate() const override {
    return left == nullptr && right == nullptr
               ? stoi(val)
               : op.at(val)(left->evaluate(), right->evaluate());
  }

 private:
  static const inline unordered_map<string, function<long(long, long)>> op{
      {"+", std::plus<long>()},
      {"-", std::minus<long>()},
      {"*", std::multiplies<long>()},
      {"/", std::divides<long>()}};
  const string val;
  const ExpNode* const left;
  const ExpNode* const right;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
 public:
  Node* buildTree(vector<string>& postfix) {
    stack<ExpNode*> stack;

    for (const string& val : postfix)
      if (val == "+" || val == "-" || val == "*" || val == "/") {
        ExpNode* right = stack.top();
        stack.pop();
        ExpNode* left = stack.top();
        stack.pop();
        stack.push(new ExpNode(val, left, right));
      } else {
        stack.push(new ExpNode(val, nullptr, nullptr));
      }

    return stack.top();
  }
};
