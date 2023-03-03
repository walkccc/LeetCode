class ExamRoom {
 public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (students.empty()) {
      students.push_back(0);
      map[0] = begin(students);
      return 0;
    }

    int prevStudent = -1;
    int maxDistToClosest = 0;
    int val = 0;              // Inserted val
    list<int>::iterator pos;  // Inserted position

    for (auto it = begin(students); it != end(students); ++it) {
      if (prevStudent == -1) {   // doesn't insert before
        maxDistToClosest = *it;  // Distance between it and the begining
        pos = it;
      } else if ((*it - prevStudent) / 2 > maxDistToClosest) {
        maxDistToClosest = (*it - prevStudent) / 2;
        val = (*it + prevStudent) / 2;
        pos = it;
      }
      prevStudent = *it;
    }

    if (n - 1 - students.back() > maxDistToClosest) {
      pos = end(students);
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
