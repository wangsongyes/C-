document.addEventListener('DOMContentLoaded', (event) => {
    const canvas = document.getElementById('gameCanvas');
    const ctx = canvas.getContext('2d');
    const blockSize = 20;
    const widthInBlocks = canvas.width / blockSize;
    const heightInBlocks = canvas.height / blockSize;
    let gameRunning = true;
    let score = 0;
    let currentBlock;
    let board;

    // 方块形状
    const shapes = [
        [[1, 1], [1, 1]], // 方块
        [[1, 1, 1, 1]], // I形
        [[1, 1, 0], [0, 1, 1]], // Z形
        [[0, 1, 1], [1, 1, 0]], // S形
        [[1, 1, 1], [0, 0, 1]], // L形
        [[1, 1, 1], [1, 0, 0]], // J形
        [[1, 1, 1], [0, 1, 0]] // T形
    ];

    // 初始化游戏
    function initGame() {
        board = Array.from({ length: heightInBlocks }, () => Array(widthInBlocks).fill(0));
        currentBlock = getRandomBlock();
        currentBlock.x = Math.floor((widthInBlocks - currentBlock.shape[0].length) / 2);
        currentBlock.y = 0;
    }

    // 获取随机方块
    function getRandomBlock() {
        const shape = shapes[Math.floor(Math.random() * shapes.length)];
        return {
            shape: shape,
            x: 0,
            y: 0,
            color: '#' + Math.floor(Math.random() * 16777215).toString(16)
        };
    }

    // 绘制方块
    function drawBlock(block) {
        ctx.fillStyle = block.color;
        block.shape.forEach((row, y) => {
            row.forEach((value, x) => {
                if (value) {
                    ctx.fillRect((block.x + x) * blockSize, (block.y + y) * blockSize, blockSize, blockSize);
                }
            });
        });
    }

    // 检查方块是否可以移动
    function canMove(block, dx, dy) {
        for (let y = 0; y < block.shape.length; y++) {
            for (let x = 0; x < block.shape[y].length; x++) {
                if (block.shape[y][x]) {
                    const newX = block.x + x + dx;
                    const newY = block.y + y + dy;
                    if (newX < 0 || newX >= widthInBlocks || newY >= heightInBlocks || (board[newY] && board[newY][newX])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // 旋转方块
    function rotateBlock(block) {
        const newShape = block.shape[0].map((_, index) => block.shape.map(row => row[index]).reverse());
        if (canMove({ ...block, shape: newShape }, 0, 0)) {
            block.shape = newShape;
        }
    }

    // 更新游戏状态
    function update() {
        if (canMove(currentBlock, 0, 1)) {
            currentBlock.y++;
        } else {
            // 固定方块到板上
            for (let y = 0; y < currentBlock.shape.length; y++) {
                for (let x = 0; x < currentBlock.shape[y].length; x++) {
                    if (currentBlock.shape[y][x]) {
                        board[currentBlock.y + y][currentBlock.x + x] = currentBlock.color;
                    }
                }
            }
            // 检查并消除行
            for (let y = heightInBlocks - 1; y >= 0; y--) {
                if (board[y].every(value => value)) {
                    board.splice(y, 1);
                    board.unshift(Array(widthInBlocks).fill(0));
                    score += 10;
                    updateScore(score);
                }
            }
            // 生成新方块
            currentBlock = getRandomBlock();
            currentBlock.x = Math.floor((widthInBlocks - currentBlock.shape[0].length) / 2);
            currentBlock.y = 0;
            if (!canMove(currentBlock, 0, 0)) {
                gameRunning = false;
            }
        }
    }

    // 绘制游戏画面
    function draw() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        drawBlock(currentBlock);
        board.forEach((row, y) => {
            row.forEach((value, x) => {
                if (value) {
                    ctx.fillStyle = value;
                    ctx.fillRect(x * blockSize, y * blockSize, blockSize, blockSize);
                }
            });
        });
    }

    // 监听键盘事件
    document.addEventListener('keydown', (event) => {
        if (!gameRunning) return;
        switch (event.key) {
            case 'ArrowLeft':
                if (canMove(currentBlock, -1, 0)) currentBlock.x--;
                break;
            case 'ArrowRight':
                if (canMove(currentBlock, 1, 0)) currentBlock.x++;
                break;
            case 'ArrowDown':
                if (canMove(currentBlock, 0, 1)) currentBlock.y++;
                break;
            case 'ArrowUp':
                rotateBlock(currentBlock);
                break;
        }
    });

    // 监听鼠标滚轮事件
    canvas.addEventListener('wheel', (event) => {
        event.preventDefault();
        if (event.deltaY < 0) {
            // 向上滚动，旋转方块
            rotateBlock(currentBlock);
        }
    });

    // 暂停按钮
    document.getElementById('pauseButton').addEventListener('click', () => {
        gameRunning = !gameRunning;
    });

    // 重新开始按钮
    document.getElementById('restartButton').addEventListener('click', () => {
        initGame();
        gameRunning = true;
        score = 0;
        updateScore(score);
    });

    // 更新得分
    function updateScore(newScore) {
        score = newScore;
        document.getElementById('score').textContent = `得分: ${score}`;
    }

    // 游戏循环
    function gameLoop() {
        if (gameRunning) {
            update();
            draw();
        }
        setTimeout(gameLoop, 500);
    }

    // 初始化游戏
    initGame();
    updateScore(score);
    gameLoop();
});
