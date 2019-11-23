function navbarAnimations() {
  var navbar = document.getElementById("navbarLinks");

  if (navbar.classList.contains("navbarAniOpen")) {
    navbar.classList.remove("navbarAniOpen");
    navbar.classList.add("navbarAniClose");
  } else {
    navbar.classList.add("navbarAniOpen");
    navbar.classList.remove("navbarAniClose");
  }
}
