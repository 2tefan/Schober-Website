var player;
var obstacles = [];

document.addEventListener('keydown', function (event) {
    if (event.keyCode == 32) {
        moveup();
    }
});
document.addEventListener('keyup', function (event) {
    if (event.keyCode == 32) {
        stopMove();
    }
});

document.addEventListener('mousedown', function (event) {
    moveup();
});

document.addEventListener('mouseup', function (event) {
    stopMove();
});

document.addEventListener('touchstart', function (event) {
    moveup();
});

document.addEventListener('touchcancel', function (event) {
    stopMove();
});

document.addEventListener('touchend', function (event) {
    stopMove();
});

function startGame() {
    resizedWindow();
}

function resizedWindow() {
    resetGame();
    myGameArea.stop();
    myGameArea.start();
}

function resetGame() {
    player = new component(30, 30, "red", 10, 120);
    obstacles = [];
    stopMove();
}

function redraw() {
    for (i = 0; i < obstacles.length; i += 1) {
        if (player.crashWith(obstacles[i])) {
            gameOver();
            return;
        }
    }
    if (player.y > window.innerHeight - player.height || player.y < 0) {
        gameOver();
        return;
    }
    myGameArea.clear();


    var x, gap, minGap = player.height * 2,
        maxGap = minGap * 2,
        distanceTop = 50,
        distanceTopMin = minGap,
        distanceTopMax = window.innerHeight - minGap;
    myGameArea.frameNo += 1;

    for (i = 0; i < obstacles.length; i += 1) {
        obstacles[i].x += -1;
        obstacles[i].redraw();
    }
    player.newPos();

    if (myGameArea.frameNo == 1) {
        gap = Math.floor(Math.random() * (maxGap - minGap + 1) + minGap);

        distanceTop = Math.floor(Math.random() * (distanceTopMax - distanceTopMin + 1) + distanceTopMin);
        obstacles.push(new component(25, distanceTop, "green", 200, 0));
        obstacles.push(new component(25, window.innerHeight - gap + distanceTop, "green", 200, gap + distanceTop));
    }

    while (obstacles[obstacles.length - 1].x < window.innerWidth) {
        gap = Math.floor(Math.random() * (maxGap - minGap + 1) + minGap);

        distanceTop = Math.floor(Math.random() * (distanceTopMax - distanceTopMin + 1) + distanceTopMin);
        obstacles.push(new component(25, distanceTop, "green", obstacles[obstacles.length - 1].x + 200, 0));
        obstacles.push(new component(25, window.innerHeight - gap + distanceTop, "green", obstacles[obstacles.length - 2].x + 200, gap + distanceTop));

    }
    while (obstacles[0].x < -obstacles[0].width) {
        console.log(obstacles[0].x);
        obstacles.shift();
        obstacles.shift();
    }



    player.redraw();

}

function gameOver() {

    var button = document.createElement("button");
    button.innerHTML = "Restart";
    button.classList.add("btn");
    button.id = "restartButton";

    // 2. Append somewhere
    document.body.insertBefore(button, document.body.firstChild);

    // 3. Add event handler
    button.addEventListener("click", function () {
        startGame();
        var elem = document.getElementById("restartButton");
        elem.remove();
    });

    myGameArea.stop();
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
    this.speedY = 0;

    this.gravity = 0.05;
    this.gravitySpeed = 0;

    this.redraw = function () {
        ctx = myGameArea.context;
        ctx.fillStyle = color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
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
    }
    this.newPos = function () {
        this.gravitySpeed += this.gravity;
        this.y += this.gravitySpeed;
    }
}

function everyinterval(n) {
    if ((myGameArea.frameNo / n) % 1 == 0) {
        return true;
    }
    return false;
}

function moveup() {
    accelerate(-0.2);
}

function stopMove() {
    accelerate(0.05);
}

function accelerate(n) {
    player.gravity = n;
}