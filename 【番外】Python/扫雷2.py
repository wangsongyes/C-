# import random
# import tkinter as tk
# from tkinter import messagebox
# import time

# class Minesweeper:
#     def __init__(self, master, width=10, height=10, mines=10):
#         self.master = master
#         self.width = width
#         self.height = height
#         self.mines = mines
#         self.board = [[0 for _ in range(width)] for _ in range(height)]
#         self.revealed = [[False for _ in range(width)] for _ in range(height)]
#         self.marked = [[False for _ in range(width)] for _ in range(height)]
#         self.buttons = [[None for _ in range(width)] for _ in range(height)]
#         self.place_mines()
#         self.calculate_numbers()
#         self.create_widgets()
#         self.start_time = None
#         self.elapsed_time = 0
#         self.timer_label = tk.Label(self.master, text="00:00", font=("Helvetica", 16))
#         self.timer_label.grid(row=self.height, column=0, columnspan=self.width)
#         self.update_timer()

#     def place_mines(self):
#         mines_placed = 0
#         while mines_placed < self.mines:
#             x = random.randint(0, self.width - 1)
#             y = random.randint(0, self.height - 1)
#             if self.board[y][x] != -1:
#                 self.board[y][x] = -1
#                 mines_placed += 1

#     def calculate_numbers(self):
#         for y in range(self.height):
#             for x in range(self.width):
#                 if self.board[y][x] == -1:
#                     continue
#                 count = 0
#                 for dy in [-1, 0, 1]:
#                     for dx in [-1, 0, 1]:
#                         if dy == 0 and dx == 0:
#                             continue
#                         ny, nx = y + dy, x + dx
#                         if 0 <= ny < self.height and 0 <= nx < self.width and self.board[ny][nx] == -1:
#                             count += 1
#                 self.board[y][x] = count

#     def create_widgets(self):
#         for y in range(self.height):
#             for x in range(self.width):
#                 button = tk.Button(self.master, width=2, height=1)
#                 button.grid(row=y, column=x)
#                 button.bind("<Button-1>", lambda event, x=x, y=y: self.reveal(x, y))
#                 button.bind("<Button-3>", lambda event, x=x, y=y: self.mark(x, y))
#                 self.buttons[y][x] = button

#     def reveal(self, x, y):
#         if self.start_time is None:
#             self.start_time = time.time()
#         if not (0 <= x < self.width and 0 <= y < self.height):
#             return
#         if self.revealed[y][x] or self.marked[y][x]:
#             return
#         self.revealed[y][x] = True
#         if self.board[y][x] == -1:
#             self.buttons[y][x].config(text='*', bg='red')
#             messagebox.showinfo("你踩雷了！", "菜")
#             self.master.quit()
#         else:
#             self.buttons[y][x].config(text=str(self.board[y][x]), bg='lightgrey')
#             if self.board[y][x] == 0:
#                 for dy in [-1, 0, 1]:
#                     for dx in [-1, 0, 1]:
#                         if dy == 0 and dx == 0:
#                             continue
#                         ny, nx = y + dy, x + dx
#                         self.reveal(nx, ny)
#         if all(self.revealed[y][x] or self.board[y][x] == -1 for y in range(self.height) for x in range(self.width)):
#             messagebox.showinfo("将军德才兼备", "大汉之栋梁也")
#             self.master.quit()

#     def mark(self, x, y):
#         if not (0 <= x < self.width and 0 <= y < self.height):
#             return
#         if self.revealed[y][x]:
#             return
#         if self.marked[y][x]:
#             self.marked[y][x] = False
#             self.buttons[y][x].config(text='')
#         else:
#             self.marked[y][x] = True
#             self.buttons[y][x].config(text='🚩')

#     def update_timer(self):
#         if self.start_time is not None:
#             self.elapsed_time = int(time.time() - self.start_time)
#         minutes, seconds = divmod(self.elapsed_time, 60)
#         self.timer_label.config(text=f"{minutes:02d}:{seconds:02d}")
#         self.master.after(1000, self.update_timer)

# if __name__ == "__main__":
#     root = tk.Tk()
#     root.title("扫雷")
#     game = Minesweeper(root)
#     root.mainloop()



import random
import tkinter as tk
from tkinter import messagebox
import time
import json

class Minesweeper:
    def __init__(self, master, width=10, height=10, mines=10):
        self.master = master
        self.width = width
        self.height = height
        self.mines = mines
        self.board = [[0 for _ in range(width)] for _ in range(height)]
        self.revealed = [[False for _ in range(width)] for _ in range(height)]
        self.marked = [[False for _ in range(width)] for _ in range(height)]
        self.buttons = [[None for _ in range(width)] for _ in range(height)]
        self.place_mines()
        self.calculate_numbers()
        self.create_widgets()
        self.start_time = None
        self.elapsed_time = 0
        self.timer_label = tk.Label(self.master, text="00:00", font=("Helvetica", 16))
        self.timer_label.grid(row=self.height, column=0, columnspan=self.width)
        self.update_timer()

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

    def create_widgets(self):
        for y in range(self.height):
            for x in range(self.width):
                button = tk.Button(self.master, width=2, height=1)
                button.grid(row=y, column=x)
                button.bind("<Button-1>", lambda event, x=x, y=y: self.reveal(x, y))
                button.bind("<Button-3>", lambda event, x=x, y=y: self.mark(x, y))
                self.buttons[y][x] = button

    def reveal(self, x, y):
        if self.start_time is None:
            self.start_time = time.time()
        if not (0 <= x < self.width and 0 <= y < self.height):
            return
        if self.revealed[y][x] or self.marked[y][x]:
            return
        self.revealed[y][x] = True
        if self.board[y][x] == -1:
            self.buttons[y][x].config(text='*', bg='red')
            messagebox.showinfo("你踩雷了！", "菜")
            self.record_time()
            self.master.quit()
        else:
            self.buttons[y][x].config(text=str(self.board[y][x]), bg='lightgrey')
            if self.board[y][x] == 0:
                for dy in [-1, 0, 1]:
                    for dx in [-1, 0, 1]:
                        if dy == 0 and dx == 0:
                            continue
                        ny, nx = y + dy, x + dx
                        self.reveal(nx, ny)
        if all(self.revealed[y][x] or self.board[y][x] == -1 for y in range(self.height) for x in range(self.width)):
            messagebox.showinfo("将军德才兼备", "大汉之栋梁也")
            self.record_time()
            self.master.quit()

    def mark(self, x, y):
        if not (0 <= x < self.width and 0 <= y < self.height):
            return
        if self.revealed[y][x]:
            return
        if self.marked[y][x]:
            self.marked[y][x] = False
            self.buttons[y][x].config(text='')
        else:
            self.marked[y][x] = True
            self.buttons[y][x].config(text='🚩')

    def update_timer(self):
        if self.start_time is not None:
            self.elapsed_time = int(time.time() - self.start_time)
        minutes, seconds = divmod(self.elapsed_time, 60)
        self.timer_label.config(text=f"{minutes:02d}:{seconds:02d}")
        self.master.after(1000, self.update_timer)

    def record_time(self):
        if self.start_time is not None:
            self.elapsed_time = int(time.time() - self.start_time)
            minutes, seconds = divmod(self.elapsed_time, 60)
            time_str = f"{minutes:02d}:{seconds:02d}"
            self.update_leaderboard(time_str)

    def update_leaderboard(self, time_str):
        try:
            with open("leaderboard.json", "r") as file:
                leaderboard = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            leaderboard = []

        leaderboard.append(time_str)
        leaderboard.sort(key=lambda x: sum(int(t) * 60 ** i for i, t in enumerate(reversed(x.split(":")))))
        if len(leaderboard) > 10:
            leaderboard = leaderboard[:10]

        with open("leaderboard.json", "w") as file:
            json.dump(leaderboard, file)

        messagebox.showinfo("排行榜更新", f"你的用时: {time_str}\n排行榜:\n" + "\n".join(leaderboard))

if __name__ == "__main__":
    root = tk.Tk()
    root.title("扫雷")
    game = Minesweeper(root)
    root.mainloop()
