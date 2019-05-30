$(document).ready(function () {
    $('#header').load("header.html");
    $('#footer').load("footer.html");
});

$(window).scroll(function(){
    if ($(window).scrollTop() >= 300) {
        $('navbar').addClass('fixed-header');
        $('navbar div').addClass('visible-title');
    }
    else {
        $('navbar').removeClass('fixed-header');
        $('navbar div').removeClass('visible-title');
    }
});
