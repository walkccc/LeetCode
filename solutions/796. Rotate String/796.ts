function rotateString(s: string, goal: string): boolean {
    if (s.length === goal.length) {
        for (let i = 0; i < s.length; ++i) {
            const before = s.substr(0, i);
            const after = s.substr(i);
            if ((after + before) === goal) return true;
        }
    }
    return false;
}
