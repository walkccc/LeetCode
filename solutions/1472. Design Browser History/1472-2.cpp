class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  void visit(string url) {
    history.push(url);
    future = stack<string>();
  }

  string back(int steps) {
    while (history.size() > 1 && steps-- > 0)
      future.push(history.top()), history.pop();
    return history.top();
  }

  string forward(int steps) {
    while (!future.empty() && steps-- > 0)
      history.push(future.top()), future.pop();
    return history.top();
  }

 private:
  stack<string> history;
  stack<string> future;
};
