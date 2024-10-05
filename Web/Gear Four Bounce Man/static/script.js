const accept = document.getElementById("accept");

document.body.addEventListener("touchstart", (e) => {
    document.body.innerHTML = "<div><h1>TOUCHING IS FORBIDDEN!</h1></div>";
});

let tx = 0;
let ty = 0;
let mx = 0;
let my = 0;

window.addEventListener("mousemove", function (e) {
    mx = e.clientX;
    my = e.clientY;
});

setInterval(() => {
    const rect = accept.getBoundingClientRect();
    const cx = rect.x + rect.width / 2;
    const cy = rect.y + rect.height / 2;
    const dx = mx - cx;
    const dy = my - cy;
    const d = Math.hypot(dx, dy);
    const mind = Math.max(rect.width, rect.height) + 10;
    const safe = Math.max(rect.width, rect.height) + 25;

    if (d < mind) {
        const diff = mind - d;
        if (d == 0) {
            tx -= diff;
        } else {
            tx -= (dx / d) * diff;
            ty -= (dy / d) * diff;
        }
    } else if (d > safe) {
        const v = 2;
        const offset = Math.hypot(tx, ty);
        const factor = Math.min(v / offset, 1);
        if (offset > 0) {
            tx -= tx * factor;
            ty -= ty * factor;
        }
    }

    accept.style.transform = `translate(${tx}px, ${ty}px)`;
}, 1);

let width = window.innerWidth;
let height = window.innerHeight;

setInterval(() => {
    if (window.innerHeight !== height || window.innerWidth !== width) {
        document.body.innerHTML = "<div><h1>NO CONSOLE ALLOWED</h1></div>";
        height = window.innerHeight;
        width = window.innerWidth;
    }
}, 10);
