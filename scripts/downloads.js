// Looks if the animation is finished
function whichAnimationEvent() {
  var t,
    el = document.createElement("fakeelement");

  var animations = {
    animation: "animationend",
    OAnimation: "oAnimationEnd",
    MozAnimation: "animationend",
    WebkitAnimation: "webkitAnimationEnd",
  };

  for (t in animations) {
    if (el.style[t] !== undefined) {
      return animations[t];
    }
  }
}

var animationEvent = whichAnimationEvent();

jQuery(document).ready(function ($) {
  //When a image with the class animated-icon is clicked, it spins and then it gets resetted.
  $(".animated-icon").on("click", function (e) {
    $(this).addClass("rotateAni");
    $(this).one(animationEvent, function (event) {
      $(this).removeClass("rotateAni");
    });
  });
});
