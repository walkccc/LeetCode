class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  void visit(string url) {
    if (++index < urls.size())
      urls[index] = url;
    else
      urls.push_back(url);
    lastIndex = index;
  }

  string back(int steps) {
    index = max(0, index - steps);
    return urls[index];
  }

  string forward(int steps) {
    index = min(lastIndex, index + steps);
    return urls[index];
  }

 private:
  vector<string> urls;
  int index = -1;
  int lastIndex = -1;
};
