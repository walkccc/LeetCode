class ExamRoom {
 public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (students.empty()) {
      students.push_back(0);
      map[0] = students.begin();
      return 0;
    }

    int prevStudent = -1;
    int maxDistToClosest = 0;
    int val = 0;              // the inserted value
    list<int>::iterator pos;  // the inserted position

    for (auto it = students.begin(); it != students.end(); ++it) {
      if (prevStudent == -1) {   // We haven't insert anything before.
        maxDistToClosest = *it;  // the distance between it and the begining
        pos = it;
      } else if ((*it - prevStudent) / 2 > maxDistToClosest) {
        maxDistToClosest = (*it - prevStudent) / 2;
        val = (*it + prevStudent) / 2;
        pos = it;
      }
      prevStudent = *it;
    }

    if (n - 1 - students.back() > maxDistToClosest) {
      pos = students.end();
      val = n - 1;
    }

    map[val] = students.insert(pos, val);
    return val;
  }

  void leave(int p) {
    students.erase(map[p]);
  }

 private:
  const int n;
  list<int> students;
  unordered_map<int, list<int>::iterator> map;  // {p: student iterator}
};
