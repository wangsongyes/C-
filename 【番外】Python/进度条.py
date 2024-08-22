import time
count = 0
while count < 90:
    process = "■"*count + "□"*(90-count)
    count += 1
    time.sleep(0.5)
    print(process , end="\r")