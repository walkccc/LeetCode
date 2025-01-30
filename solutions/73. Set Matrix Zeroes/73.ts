function setZeroes(matrix: number[][]): void {
    const zeroRows = new Set<number>();
    const zeroCols = new Set<number>();

    for (let row = 0; row < matrix.length; ++row) {
        for (let col = 0; col < matrix[row].length; ++col) {
            if (matrix[row][col] === 0) {
                zeroRows.add(row);
                zeroCols.add(col);
            }
        }
    }

    for (let row = 0; row < matrix.length; ++row) {
        for (let col = 0; col < matrix[row].length; ++col) {
            if (zeroCols.has(col) || zeroRows.has(row)) {
                matrix[row][col] = 0;
            }
        }
    }
}
