$(document).ready(function () {
    $('#header').load("../../html/elements/header.html");
    $('#myNavbar').load("../../html/elements/navbar.html");
    $('#games').load("../../html/elements/games.html");
    $('#footer').load("../../html/elements/footer.html");

    $(window).scroll(function () {
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
        if (window.pageYOffset >= $('#headline').outerHeight(true)) {
            $('#myNavbar').addClass("sticky");
        } else {
            $('#myNavbar').removeClass("sticky");
        }
    };
})

/* Toggle between adding and removing the "responsive" class to topnav when the user clicks on the icon */
function navbar() {
    if ($('#myNavbar').hasClass("responsive")) {
        $('#myNavbar').removeClass("responsive");
    } else {
        $('#myNavbar').addClass("responsive");
    }
}