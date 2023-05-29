import math
from collections import Counter

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        length = len(points)
        if length <= 2:
            return length       
        slopes = [[(0,0) for i in range(length)] for j in range(length)]
        mxm = 0 
        for i in range(length - 1):
            for j in range(i + 1, length):
                x, y = 0, 0
                #i want to keep the x positive at all times.
                if points[i][0] > points[j][0]:
                    x = points[i][0] - points[j][0]
                    y = points[i][1] - points[j][1]
                else:
                    x = points[j][0] - points[i][0]
                    y = points[j][1] - points[i][1]
                
                # vertical line, horizontal line, etc.
                if x == 0 and y != 0:
                    x = points[i][0]
                    y = None
                elif x != 0 and y == 0:
                    x = None
                    y = points[i][1]
                else:
                    divider = math.gcd(x, y)
                    x //= divider
                    y //= divider
                
                slopes[i][j] = (x, y)
                slopes[j][i] = (x, y)

            c = Counter(tuple(slopes[i]))
            #print(c, c.values(), max(c.values()))
            new_max = max(c.values()) + 1
            if new_max > mxm:
                mxm = new_max
        
        """
        for i in range(length):
            print(slopes[i])
        """
        return mxm