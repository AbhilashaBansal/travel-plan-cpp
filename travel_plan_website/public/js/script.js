window.onload = function (){
    let navbar = document.getElementById("navbar");
    let sticky = navbar.offsetTop;

    window.onscroll = function(){
        sticky_nav();
    }
    
    function sticky_nav() {
        if (window.pageYOffset > sticky) {
            navbar.classList.add("sticky");
        } 
        else {
            navbar.classList.remove("sticky");
        }
    }
};