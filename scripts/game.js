function startGame() {
    resizedWindow();
    window.setInterval(redraw, 20);
}

function resizedWindow() {
    myGameArea.start();
    resetGame();
}

function resetGame() {
    player = new playerObject(30, 30, "red", 10, 120);
}

function redraw() {
    myGameArea.clear();
    myGameArea.draw();
    player.redraw();
}

var myGameArea = {
    canvas: document.createElement("canvas"),
    start: function () {
        this.canvas.width = window.innerWidth;
        this.canvas.height = window.innerHeight;
        this.context = this.canvas.getContext("2d");

        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
    },
    clear: function () {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    },
    draw: function () {
        this.context.moveTo(0, 0);
        this.context.lineTo(this.canvas.width, this.canvas.height);
        this.context.stroke();
        this.context.moveTo(this.canvas.width, 0);
        this.context.lineTo(0, this.canvas.height);
        this.context.stroke();
    }
}

function playerObject(width, height, color, x, y) {
    this.width = width;
    this.height = height;
    this.x = x;
    this.y = y;
    this.redraw = function () {
        ctx = myGameArea.context;
        ctx.fillStyle = color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
}