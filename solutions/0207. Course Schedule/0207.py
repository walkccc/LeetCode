class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def hasCycle(course: int) -> bool:
            if state[course] == 1:
                return True
            if state[course] == 2:
                return False

            state[course] = 1
            for neighbor in graph[course]:
                if hasCycle(neighbor):
                    return True
            state[course] = 2

            return False

        graph = [[] for _ in range(numCourses)]
        state = [0] * numCourses

        for a, b in prerequisites:
            graph[b].append(a)

        for course in range(numCourses):
            if hasCycle(course):
                return False

        return True
