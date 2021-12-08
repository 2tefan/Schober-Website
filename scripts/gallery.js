let modal
let captionText

$(document).ready(function () {
    const a_images = document.getElementById('gallery').childNodes;
    modal = document.getElementById("myModal");
    captionText = document.getElementById("caption");
    const span = document.getElementsByClassName("close")[0];

    span.addEventListener('click', hideModal);
    a_images.forEach((a_image) => {
        a_image.addEventListener('click', open)

        let image = a_image.childNodes[1];
        let caption = $(a_image).find(".title").text();

        if (image != undefined && caption != undefined) {
            image.alt = caption;
        }
    });
});

function showModal() {
    modal.style.display = "block";
}

function hideModal() {
    modal.style.display = "none";
}

function open() {
    let image = this.querySelector('img');
    let modalImage = modal.querySelector('img');

    modalImage.src = image.src;
    captionText.innerHTML = image.alt;
    showModal()
}
