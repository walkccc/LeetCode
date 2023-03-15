class MyHashSet {
 public:
  /** Initialize your data structure here. */
  MyHashSet() : set(1000001) {}

  void add(int key) {
    set[key] = true;
  }

  void remove(int key) {
    set[key] = false;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    return set[key];
  }

 private:
  vector<bool> set;
};
