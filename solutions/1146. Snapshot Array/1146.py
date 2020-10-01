class SnapshotArray:
    def __init__(self, length: int):
        self.map = [[[0, 0]] for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        self.map[index].append([self.snap_id, val])

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        i = bisect.bisect(self.map[index], [snap_id + 1]) - 1
        return self.map[index][i][1]
