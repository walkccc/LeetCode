struct Node {
  int key;
  int value;
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!keyToIterator.count(key))
      return -1;

    const auto& it = keyToIterator[key];
    cache.splice(begin(cache), cache, it);  // move it to front
    return it->value;
  }

  void put(int key, int value) {
    if (keyToIterator.count(key)) {  // no capacity issue, just update the value
      const auto& it = keyToIterator[key];
      cache.splice(begin(cache), cache, it);  // move it to front
      it->value = value;
      return;
    }

    if (cache.size() == capacity) {  // check the capacity
      const Node& lastNode = cache.back();
      keyToIterator.erase(lastNode.key);  // that's why we store key in `Node`
      cache.pop_back();
    }

    cache.push_front({key, value});
    keyToIterator[key] = begin(cache);
  }

 private:
  const int capacity;
  list<Node> cache;
  unordered_map<int, list<Node>::iterator> keyToIterator;
};
