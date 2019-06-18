var player;
var obstacles = [];

document.addEventListener('keydown', function (event) {
    if (event.keyCode == 32) {
        moveup();
        setTimeout(function () {
            stopMove();
        }, 20);
    } else {
        stopMove();
    }
});

document.addEventListener('mousedown', function (event) {
    moveup();
});

document.addEventListener('mouseup', function (event) {
    stopMove();
});

function startGame() {
    resizedWindow();
}

function resizedWindow() {
    myGameArea.start();
    resetGame();
}

function resetGame() {
    player = new component(30, 30, "red", 10, 120);
    obstacles = [];
}

function redraw() {
    var x, gap, minGap = player.height * 2,
        maxGap = minGap * 2,
        distanceTop = 50,
        distanceTopMin = minGap,
        distanceTopMax = window.innerHeight - minGap;

    for (i = 0; i < obstacles.length; i += 1) {
        if (player.crashWith(obstacles[i])) {
            myGameArea.stop();
            return;
        }
    }
    myGameArea.clear();
    myGameArea.draw();
    myGameArea.frameNo += 1;

    if (myGameArea.frameNo == 1 || everyinterval(150)) {
        x = myGameArea.canvas.width;

        gap = Math.floor(Math.random() * (maxGap - minGap + 1) + minGap);
        distanceTop = Math.floor(Math.random() * (distanceTopMax - distanceTopMin + 1) + distanceTopMin);
        obstacles.push(new component(10, distanceTop, "green", x, 0));
        obstacles.push(new component(10, window.innerHeight - gap + distanceTop, "green", x, gap + distanceTop));
    }
    for (i = 0; i < obstacles.length; i += 1) {
        obstacles[i].x += -1;
        obstacles[i].redraw();
    }
    player.newPos();

    player.redraw();
}


var myGameArea = {
    canvas: document.createElement("canvas"),
    start: function () {
        this.canvas.width = window.innerWidth;
        this.canvas.height = window.innerHeight;
        this.context = this.canvas.getContext("2d");
        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
        this.frameNo = 0;
        this.interval = setInterval(redraw, 20);
    },
    clear: function () {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    },
    stop: function () {
        clearInterval(this.interval);
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

function component(width, height, color, x, y) {
    this.width = width;
    this.height = height;
    this.x = x;
    this.y = y;
    this.speedX = 0;
    this.speedY = 0;

    this.gravity = 0.05;
    this.gravitySpeed = 0;

    this.redraw = function () {
            ctx = myGameArea.context;
            ctx.fillStyle = color;
            ctx.fillRect(this.x, this.y, this.width, this.height);
        },
        this.crashWith = function (otherobj) {
            var myleft = this.x;
            var myright = this.x + (this.width);
            var mytop = this.y;
            var mybottom = this.y + (this.height);
            var otherleft = otherobj.x;
            var otherright = otherobj.x + (otherobj.width);
            var othertop = otherobj.y;
            var otherbottom = otherobj.y + (otherobj.height);
            var crash = true;
            if ((mybottom < othertop) ||
                (mytop > otherbottom) ||
                (myright < otherleft) ||
                (myleft > otherright)) {
                crash = false;
            }
            return crash;
        },
        this.newPos = function () {
            this.gravitySpeed += this.gravity;
            this.x += this.speedX;
            this.y += this.speedY + this.gravitySpeed;
        }
}

function everyinterval(n) {
    if ((myGameArea.frameNo / n) % 1 == 0) {
        return true;
    }
    return false;
}

function moveup() {
    accelerate(-.2);
}

function stopMove() {
    accelerate(.05);
}

function accelerate(n) {
    player.gravity = n;
}