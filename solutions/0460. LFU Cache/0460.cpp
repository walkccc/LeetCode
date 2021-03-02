struct Node {
  int key;
  int value;
  int freq;
  list<int>::const_iterator it;
};

class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

  int get(int key) {
    if (!keyToNode.count(key))
      return -1;

    Node& node = keyToNode[key];
    touch(node);
    return node.value;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (keyToNode.count(key)) {
      Node& node = keyToNode[key];
      node.value = value;
      touch(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      // evict LRU key from the minFreq list
      const int keyToEvict = freqToList[minFreq].back();
      freqToList[minFreq].pop_back();
      keyToNode.erase(keyToEvict);
    }

    minFreq = 1;
    freqToList[1].push_front(key);
    keyToNode[key] = {key, value, 1, cbegin(freqToList[1])};
  }

 private:
  int capacity;
  int minFreq;
  unordered_map<int, Node> keyToNode;
  unordered_map<int, list<int>> freqToList;

  void touch(Node& node) {
    // update the node's frequency
    const int prevFreq = node.freq;
    const int newFreq = ++node.freq;

    // remove the iterator from prevFreq's list
    freqToList[prevFreq].erase(node.it);
    if (freqToList[prevFreq].empty()) {
      freqToList.erase(prevFreq);
      // update minFreq if needed
      if (prevFreq == minFreq)
        ++minFreq;
    }

    // insert the key to the front of newFreq's list
    freqToList[newFreq].push_front(node.key);
    node.it = cbegin(freqToList[newFreq]);
  }
};
