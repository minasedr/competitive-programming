class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        for row in matrix:
            prefix = 0
            for col in range(len(row)):
                prefix += row[col]
                row[col] = prefix
        self.matrix = matrix
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        aggr = 0
        for i in range(row1, row2+1):
            if col1:
                aggr += self.matrix[i][col2] - self.matrix[i][col1-1]
            else:
                aggr += self.matrix[i][col2]
        return aggr


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)