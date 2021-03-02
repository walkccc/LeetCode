class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  void visit(string url) {
    future = stack<string>();
    history.push(url);
  }

  string back(int steps) {
    while (steps-- > 0 && history.size() > 1)
      future.push(history.top()), history.pop();
    return history.top();
  }

  string forward(int steps) {
    while (steps-- > 0 && !future.empty())
      history.push(future.top()), future.pop();
    return history.top();
  }

 private:
  stack<string> history;
  stack<string> future;
};
