class MyHashSet {
 public:
  MyHashSet() : set(1000001) {}

  void add(int key) {
    set[key] = true;
  }

  void remove(int key) {
    set[key] = false;
  }

  bool contains(int key) {
    return set[key];
  }

 private:
  vector<bool> set;
};