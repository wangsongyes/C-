import random
import tkinter as tk
from tkinter import messagebox

# 定义奖品及其概率
prizes = {
    "菜篮子*2": 0.11646,
    "银币*66": 0.25,
    "欢乐豆*20": 0.20,
    "进阶丹": 0.20,
    "手气卡*2": 0.10,
    "招募令": 0.05,
    "雁翎甲": 0.05,
    "改名卡": 0.01,
    "菜篮子*99": 0.005,
    "谋高顺": 0.005,
    "史诗宝珠碎片": 0.01,
    "龙生九子-曹丕": 0.001,
    "龙生九子-曹植": 0.001,
    "雁翎*1000": 0.00025,
    "将魂*1000": 0.00018,
    "史诗宝珠*1":0.00012,
    "神鲁肃": 0.00002,
    "史诗宝珠*33": 0.00002,
    "曹髦": 0.00002
}

# 记录总抽奖次数
total_draws = 0

# 记录各奖品的累计次数
prize_counts = {prize: 0 for prize in prizes}

# 初始元宝数量
yuanbao = 0

def draw_prize():
    # 计算累积概率
    cumulative_probabilities = []
    cumulative_sum = 0
    for prob in prizes.values():
        cumulative_sum += prob
        cumulative_probabilities.append(cumulative_sum)
    
    # 生成一个随机数
    random_number = random.random()
    
    # 根据随机数确定奖品
    for i, cumulative_prob in enumerate(cumulative_probabilities):
        if random_number <= cumulative_prob:
            return list(prizes.keys())[i]

# 模拟抽奖
def simulate_draws(num_draws):
    results = {prize: 0 for prize in prizes}
    
    for _ in range(num_draws):
        prize = draw_prize()
        results[prize] += 1
    
    return results

# 更新主界面显示
def update_display():
    display_text = "奖品累计次数:\n"
    for prize, count in prize_counts.items():
        display_text += f"{prize}: {count}次\n"
    display_text += f"\n总抽奖次数: {total_draws}"
    text_area.delete(1.0, tk.END)
    text_area.insert(tk.END, display_text)
    yuanbao_label.config(text=f"元宝: {yuanbao}")

# 处理抽奖按钮点击事件
def on_draw_click():
    global total_draws
    try:
        num_draws = int(entry.get())
        if num_draws <= 0:
            raise ValueError("抽奖次数必须大于0")
    except ValueError as e:
        messagebox.showerror("输入错误", str(e))
        return
    
    results = simulate_draws(num_draws)
    total_draws += num_draws
    for prize, count in results.items():
        prize_counts[prize] += count
    
    update_display()

# 处理购买元宝按钮点击事件
def on_buy_click():
    global yuanbao
    try:
        amount = int(buy_entry.get())
        if amount <= 0:
            raise ValueError("购买数量必须大于0")
        yuanbao += amount
        update_display()
    except ValueError as e:
        messagebox.showerror("输入错误", str(e))
        return

# 创建主窗口
root = tk.Tk()
root.title("三国杀移动版抽奖模拟器")

# 创建并放置元宝显示标签和购买按钮
yuanbao_label = tk.Label(root, text=f"元宝: {yuanbao}")
yuanbao_label.pack(pady=10)

buy_button = tk.Button(root, text="购买", command=on_buy_click)
buy_button.pack(pady=10)

buy_entry = tk.Entry(root)
buy_entry.pack(pady=10)

# 创建并放置输入框和标签
label = tk.Label(root, text="请输入抽奖次数:")
label.pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

# 创建并放置抽奖按钮
draw_button = tk.Button(root, text="开始抽奖", command=on_draw_click)
draw_button.pack(pady=20)

# 创建并放置文本区域显示奖品累计次数
text_area = tk.Text(root, width=40, height=20)
text_area.pack(pady=20)

# 初始化显示
update_display()

# 运行主循环
root.mainloop()
