class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glass = [[poured]]
        for row in range(0, query_row+1):
            prevrow = glass[row]
            currow = [0] * (len(prevrow) + 1)
            for i in range(0, len(prevrow)):
                if prevrow[i] > 1:
                    prevrow[i] -= 1
                    currow[i] += prevrow[i] / 2
                    currow[i+1] += prevrow[i] / 2
                    prevrow[i] = 1
            glass.append(currow)
          
            if i == query_row:
                return prevrow[query_glass]

        return 0