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
    const auto it = keyToNode.find(key);
    if (it == keyToNode.cend())
      return -1;

    Node& node = it->second;
    touch(node);
    return node.value;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (const auto it = keyToNode.find(key); it != keyToNode.cend()) {
      Node& node = it->second;
      node.value = value;
      touch(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      // Evict an LRU key from the `minFreq` list.
      const int keyToEvict = freqToList[minFreq].back();
      freqToList[minFreq].pop_back();
      keyToNode.erase(keyToEvict);
    }

    minFreq = 1;
    freqToList[1].push_front(key);
    keyToNode[key] = {key, value, 1, freqToList[1].cbegin()};
  }

 private:
  int capacity;
  int minFreq;
  unordered_map<int, Node> keyToNode;
  unordered_map<int, list<int>> freqToList;

  void touch(Node& node) {
    // Update the node's frequency.
    const int prevFreq = node.freq;
    const int newFreq = ++node.freq;

    // Remove the iterator from the `prevFreq`'s list
    freqToList[prevFreq].erase(node.it);
    if (freqToList[prevFreq].empty()) {
      freqToList.erase(prevFreq);
      // Update the `minFreq` if needed.
      if (prevFreq == minFreq)
        ++minFreq;
    }

    // Insert the key to the front of the `newFreq`'s list.
    freqToList[newFreq].push_front(node.key);
    node.it = freqToList[newFreq].cbegin();
  }
};
