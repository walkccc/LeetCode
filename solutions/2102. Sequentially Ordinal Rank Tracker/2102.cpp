struct Location {
  string name;
  int score;
  Location(const string& name, int score) : name(move(name)), score(score) {}
};

class SORTracker {
 public:
  void add(const string& name, int score) {
    l.emplace(name, score);
    if (l.size() > k + 1) {
      const Location location = l.top();
      l.pop();
      r.emplace(location.name, location.score);
    }
  }

  string get() {
    const string name = l.top().name;
    if (!r.empty()) {
      const Location location = r.top();
      r.pop();
      l.emplace(location.name, location.score);
    }
    ++k;
    return name;
  }

 private:
  struct CompareLeftMinHeap {
    bool operator()(const Location& a, const Location& b) {
      return a.score == b.score ? a.name < b.name : a.score > b.score;
    }
  };

  struct CompareRightMaxHeap {
    bool operator()(const Location& a, const Location& b) {
      return a.score == b.score ? a.name > b.name : a.score < b.score;
    }
  };

  priority_queue<Location, vector<Location>, CompareLeftMinHeap> l;
  priority_queue<Location, vector<Location>, CompareRightMaxHeap> r;
  int k = 0;
};
