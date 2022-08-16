# BFS Approach using deque Time & Space = O(mn)
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        R = len(grid)
        C = len(grid[0])
        fresh, time = 0, 0
        q = deque()

        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    q.append([i, j])

        dirc = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        while q and fresh > 0:

            for i in range(len(q)):

                r, c = q.popleft()
                
                for dr, dc in dirc:

                    row, col = dr + r, dc + c
                    # if in bound and fresh make rotten
                    if (row < 0 or col < 0 or row == R or col == C or grid[row][col] != 1):
                        
                        continue
                        
                    grid[row][col] = 2 # mark grid[row][col] as rotten
                    
                    q.append([row, col]) # push newly rotten orange to queue
                    
                    fresh -= 1 # decrease the count of fresh oranges by 1
                    
            time += 1
            
        return time if fresh == 0 else -1
