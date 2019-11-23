function navbarAnimations() {
  var navbar = document.getElementById("navbarLinks");

  if (window.screen.width < 500) {
    if (navbar.classList.contains("navbarAniOpen")) {
      navbar.classList.remove("navbarAniOpen");
      navbar.classList.add("navbarAniClose");
    } else {
      navbar.classList.add("navbarAniOpen");
      navbar.classList.remove("navbarAniClose");
    }
  }
}
window.onresize = function(event) {
  var navbar = document.getElementById("navbarLinks");
  
  if (window.screen.width >= 500) {
    navbar.classList.remove("navbarAniOpen");
    navbar.classList.remove("navbarAniClose");
  }
};
