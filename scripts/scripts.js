$(document).ready(function () {
    $('#header').load("../../../../html/header.html");
    $('#navbar').load("../../../../html/navbar.html");
    $('#footer').load("../../../../html/footer.html");

    $(window).scroll(function(){ 
        if ($(this).scrollTop() > 300) { 
            $('#returnToTop').addClass('show');
        } else { 
            $('#returnToTop').removeClass('show');
        } 
    });
});

document.addEventListener('DOMContentLoaded', function () {
    // When the user scrolls the page, execute myFunction 
    window.onscroll = function () {
        myFunction()
    };

    // Get the navbar
    var navbar = document.getElementById("navbar");

    // Get the offset position of the navbar
    var sticky = navbar.offsetTop;

    // Add the sticky class to the navbar when you reach its scroll position. Remove "sticky" when you leave the scroll position
    function myFunction() {
        if (window.pageYOffset >= 124) {
            navbar.classList.add("sticky")
        } else {
            navbar.classList.remove("sticky");
        }
    }
})