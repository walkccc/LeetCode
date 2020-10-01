class RandomizedCollection:
    def __init__(self):
        self.vals = []
        self.dict = collections.defaultdict(list)

    def insert(self, val: int) -> bool:
        self.dict[val].append(len(self.vals))
        self.vals.append([val, len(self.dict[val]) - 1])
        return len(self.dict[val]) == 1

    def remove(self, val: int) -> bool:
        if val not in self.dict or self.dict[val] == []:
            return False
        index = self.dict[val][-1]
        self.dict[self.vals[-1][0]][self.vals[-1][1]] = index
        self.dict[val].pop()
        self.vals[index] = self.vals[-1]
        self.vals.pop()
        return True

    def getRandom(self) -> int:
        index = random.randint(0, len(self.vals) - 1)
        return self.vals[index][0]
