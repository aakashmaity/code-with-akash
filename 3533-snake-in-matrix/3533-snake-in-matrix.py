class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        row = 0
        col = 0
        for item in commands:
            if item == "RIGHT":
                col += 1
            elif item == "LEFT":
                col -= 1
            elif item == "UP":
                row -= 1
            else:
                row += 1
        return (row * n) + col
