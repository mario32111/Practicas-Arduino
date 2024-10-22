function moveCube() {
    const x = document.getElementById('x-coordinate').value;
    const y = document.getElementById('y-coordinate').value;
    const z = document.getElementById('z-coordinate').value;
    
    const cube = document.querySelector('.cube');
    cube.style.transform = `rotateX(${x}deg) rotateY(${y}deg) rotateZ(${z}deg)`;
}
