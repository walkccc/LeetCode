class FrontMiddleBackQueue {
 public:
  void pushFront(int val) {
    frontQueue.push_front(val);
    moveFrontToBackIfNeeded();
  }

  void pushMiddle(int val) {
    if (| frontQueue | == | backQueue |)
      backQueue.push_front(val);
    else
      frontQueue.push_back(val);
  }

  void pushBack(int val) {
    backQueue.push_back(val);
    moveBackToFrontIfNeeded();
  }

  int popFront() {
    if (!frontQueue.empty()) {
      const int x = frontQueue.front();
      frontQueue.pop_front();
      moveBackToFrontIfNeeded();
      return x;
    }
    if (!backQueue.empty()) {
      const int x = backQueue.front();
      backQueue.pop_front();
      moveFrontToBackIfNeeded();
      return x;
    }
    return -1;
  }

  int popMiddle() {
    if (frontQueue.empty() && backQueue.empty())
      return -1;
    if (frontQueue.size() + 1 == backQueue.size()) {
      const int x = backQueue.front();
      backQueue.pop_front();
      return x;
    } else {  // |frontQueue| == |backQueue|
      const int x = frontQueue.back();
      frontQueue.pop_back();
      return x;
    }
  }

  int popBack() {
    if (backQueue.empty())
      return -1;
    const int x = backQueue.back();
    backQueue.pop_back();
    moveFrontToBackIfNeeded();
    return x;
  }

 private:
  // |frontQueue| = |backQueue| or
  // |frontQueue| = |backQueue| - 1
  deque<int> frontQueue;
  deque<int> backQueue;

  void moveFrontToBackIfNeeded() {
    if (frontQueue.size() - 1 == backQueue.size()) {
      const int x = frontQueue.back();
      frontQueue.pop_back();
      backQueue.push_front(x);
    }
  }

  void moveBackToFrontIfNeeded() {
    if (frontQueue.size() + 2 == backQueue.size()) {
      const int x = backQueue.front();
      backQueue.pop_front();
      frontQueue.push_back(x);
    }
  }
};
