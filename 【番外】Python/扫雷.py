import random

class Minesweeper:
    def __init__(self, width=10, height=10, mines=10):
        self.width = width
        self.height = height
        self.mines = mines
        self.board = [[0 for _ in range(width)] for _ in range(height)]
        self.revealed = [[False for _ in range(width)] for _ in range(height)]
        self.place_mines()
        self.calculate_numbers()

    def place_mines(self):
        mines_placed = 0
        while mines_placed < self.mines:
            x = random.randint(0, self.width - 1)
            y = random.randint(0, self.height - 1)
            if self.board[y][x] != -1:
                self.board[y][x] = -1
                mines_placed += 1

    def calculate_numbers(self):
        for y in range(self.height):
            for x in range(self.width):
                if self.board[y][x] == -1:
                    continue
                count = 0
                for dy in [-1, 0, 1]:
                    for dx in [-1, 0, 1]:
                        if dy == 0 and dx == 0:
                            continue
                        ny, nx = y + dy, x + dx
                        if 0 <= ny < self.height and 0 <= nx < self.width and self.board[ny][nx] == -1:
                            count += 1
                self.board[y][x] = count

    def reveal(self, x, y):
        if not (0 <= x < self.width and 0 <= y < self.height):
            return
        if self.revealed[y][x]:
            return
        self.revealed[y][x] = True
        if self.board[y][x] == -1:
            print("游戏结束，你踩到地雷了！")
            self.print_board(True)
            return False
        elif self.board[y][x] == 0:
            for dy in [-1, 0, 1]:
                for dx in [-1, 0, 1]:
                    if dy == 0 and dx == 0:
                        continue
                    ny, nx = y + dy, x + dx
                    self.reveal(nx, ny)
        return True

    def print_board(self, show_all=False):
        for y in range(self.height):
            for x in range(self.width):
                if self.revealed[y][x] or show_all:
                    if self.board[y][x] == -1:
                        print('*', end=' ')
                    else:
                        print(self.board[y][x], end=' ')
                else:
                    print('#', end=' ')
            print()

    def play(self):
        while True:
            self.print_board()
            x = int(input(f"请输入X坐标 (0-{self.width-1}): "))
            y = int(input(f"请输入Y坐标 (0-{self.height-1}): "))
            if not self.reveal(x, y):
                break
            if all(self.revealed[y][x] or self.board[y][x] == -1 for y in range(self.height) for x in range(self.width)):
                self.print_board(True)
                print("恭喜你，你赢了！")
                break

if __name__ == "__main__":
    game = Minesweeper()
    game.play()
