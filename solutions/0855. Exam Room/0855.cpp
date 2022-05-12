class ExamRoom {
 public:
  ExamRoom(int N) : N(N) {}

  int seat() {
    if (students.empty()) {
      students.push_back(0);
      map[0] = begin(students);
      return 0;
    }

    int prevStudent = -1;
    int maxDistToClosest = 0;
    int val = 0;              // inserted val
    list<int>::iterator pos;  // inserted position

    for (auto it = begin(students); it != end(students); ++it) {
      if (prevStudent == -1) {   // doesn't insert before
        maxDistToClosest = *it;  // distance between it and the begining
        pos = it;
      } else if ((*it - prevStudent) / 2 > maxDistToClosest) {
        maxDistToClosest = (*it - prevStudent) / 2;
        val = (*it + prevStudent) / 2;
        pos = it;
      }
      prevStudent = *it;
    }

    if (N - 1 - students.back() > maxDistToClosest) {
      pos = end(students);
      val = N - 1;
    }

    map[val] = students.insert(pos, val);
    return val;
  }

  void leave(int p) {
    students.erase(map[p]);
  }

 private:
  int N;
  list<int> students;
  unordered_map<int, list<int>::iterator> map;  // {p: student iterator}
};
