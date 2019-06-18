function startGame() {
    window.setInterval(redraw,20);
}

var myGameArea = {
    canvas: document.createElement("canvas"),
    start: function () {
        this.canvas.width = window.innerWidth;
        this.canvas.height = window.innerHeight;
        this.context = this.canvas.getContext("2d");

        this.context.moveTo(0, 0);
        this.context.lineTo(this.canvas.width, this.canvas.height);
        this.context.stroke();

        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
    },
    clear: function () {
        this.canvas.getContext("2d").clearRect(0, 0, this.canvas.width, this.canvas.height);
    }
}

function redraw()
{
    myGameArea.clear();
    myGameArea.start();
}