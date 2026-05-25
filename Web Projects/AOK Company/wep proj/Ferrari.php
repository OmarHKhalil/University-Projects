<?php
    include('header.php');
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="Picure/car-side-solid.svg" type="image/x-icon"> 
    <title>AOK Company Ferrari</title>

    <style>

@import url('https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100;0,300;0,400;0,500;0,700;0,900;1,100;1,300;1,400;1,500;1,700;1,900&display=swap');

*{
    margin: 0;
    padding: 0;
}

html{
    font-family: system-ui, -apple-system, "Roboto", sans-serif;
    box-sizing: border-box;
    scroll-behavior: smooth;
}

main a,main button,
footer a,footer button{
    all: unset;
    display: inline-block;
    transition: 0.2s;
    -webkit-transition: 0.2s;
    -moz-transition: 0.2s;
    -ms-transition: 0.2s;
    -o-transition: 0.2s;
}
button:active, a:active{
    scale: 0.9;
}

button:hover, a:hover{
    cursor: pointer;
}
button:disabled{
    opacity: 0.5;
    cursor: not-allowed;
    scale: 1;
}

li{
    list-style: none;
}


/*----------*/
.border{
    border: 4px solid red;
}
.flex{
    display: flex;
    align-items: center;
}

/*----------*/
:root{
    --w:  white;
    --bodyBG: #f6f6f6;
    --bodyFont: #2b3445;
    --blue: #9fceff;
    --icon:#40464d;
    --button:#1976d2;
    --footer:#212529;
    color:white
}
.dark{
    --bodyBG: black;
    --bodyFont:
}
body{
    
    background-color: var(--bodyBG);
    color: var(--bodyFont);
    width:100%;
}

        main{
    width:80%;
    margin: 0 auto;
}

@media (width < 600px) {
    main{
        width:98%;
        margin: 0;
    }
    main h1.head{
        margin: 2.3rem 0 2rem 0;
        font-size: 1.4rem ;
    }
    
}
@media (width < 420px) {
    #omar1{
        display: none;
    }
}
/* UP */
#omar1{
    position: sticky;
    left: 3%;
    top: 50%;
    width: 3%;
    height: 3.5%;
    font-size: large;
    border: 2px  rgb(255, 228, 74) solid;
    border-radius: 50px;
    padding: 10px;
    color: black;
    display: flex;
    justify-content: center;

}
#omar1:hover{
    scale: 0.95;
    background-color:rgb(202, 200, 200);
}
.fa-angles-up{
    margin-inline: auto;
}
/* ....................... */
/* main head */
main section.head{
    margin: 5.3rem 0 4rem 2%;
    color: black;
}
main section.head .nav{
    display: flex;
    gap: 0.4rem;
}
main .head i{
    margin: 10px 0 0 10px;
}
main section.head .menu:hover .submenu{
    display: block;
}
main .head .submenu li{
    padding: 10px;
}
main .head .submenu{
    display: none;
}
main .head a:hover{
    color: rgb(255, 228, 74);
}
/* ......... */
main section.products.flex{
    flex-wrap: wrap;
    justify-content: center;
    gap: 4rem 3rem;
}

main section.products.flex article{
    border:2px  rgb(255, 228, 74) solid;
    background-color: #eee;
    
    border-radius: 5px;
    -webkit-border-radius: 5px;
    -moz-border-radius: 5px;
    -ms-border-radius: 5px;
    -o-border-radius: 5px;
    /*box-shadow: gold 0px 2px 1px -1px, gold 0px 1px 1px 0px, gold 0px 1px 3px 0px;*/
    box-shadow: rgba(0, 0, 0, 0.2) 0px 2px 1px -1px, rgba(0, 0, 0, 0.14) 0px 1px 1px 0px, rgba(0, 0, 0, 0.12) 0px 1px 3px 0px;
    transition: 0.2s;
    transition: 0.2;
    -webkit-transition:0.2;
    -moz-transition:0.2;
    -ms-transition:0.2;
    -o-transition:0.2;
}
main section.products.flex article:hover{
    scale: 1.01;
}

main section.products.flex article img{
    width: 18.1rem;
    height: 13rem;
    border-radius: 5px 5px 0 0;
    -webkit-border-radius: 5px 5px 0 0;
    -moz-border-radius: 5px 5px 0 0;
    -ms-border-radius: 5px 5px 0 0;
    -o-border-radius: 5px 5px 0 0;
}

section div.content{
    background-color: #eee;
    
    width: 18.1rem;
    border-radius:0px 0px 5px 5px;
    -webkit-border-radius:0px 0px 5px 5px;
    -moz-border-radius:0px 0px 5px 5px;
    -ms-border-radius:0px 0px 5px 5px;
    -o-border-radius:0px 0px 5px 5px;
}

section div.content .title{
    padding: 0.7rem 0.4rem 0 0.4rem;
    text-transform: capitalize;
}


section  div.content .descrip{
    padding: 0 0.4rem;
    font-size: 0.8rem;
    margin: 0.4rem 0 0.6rem 0;
    line-height: 1.1rem;
    background-color: #eee;
}
section  div.content .price{
    margin-left: 0.88rem;
    font-size: 0.9rem;
    font-weight: bold;
    color: black;
}
section  div.content .add{
    margin-right: 0.88rem;
    background-color:  rgb(255, 228, 74);
    color:black;
    padding:6px 8px;
    font-size: 0.7rem;
    border-radius: 4px;
    -webkit-border-radius: 4px;
    -moz-border-radius: 4px;
    -ms-border-radius: 4px;
    -o-border-radius: 4px;
}
section  div.content .add .fa-solid{
    color: rgb(255, 228, 74);
    margin-right: 0.33rem;
    
}
section  div.content div{
    justify-content: space-between;
    margin-bottom: 0.7rem;
}


/* slider */
main .slider{
    margin-block: 4rem;
    margin-inline: auto;
    width: 90%;
    border-radius: 10px;
    -webkit-border-radius: 10px;
    -moz-border-radius: 10px;
    -ms-border-radius: 10px;
    -o-border-radius: 10px;
}
main .slider img{
    margin: auto;
    border: 2px  rgb(255, 228, 74) solid;
    border-radius: 10px;
    -webkit-border-radius: 10px;
    -moz-border-radius: 10px;
    -ms-border-radius: 10px;
    -o-border-radius: 10px;
}

body{
    background-color :rgb(240, 240, 240);
}



    </style>
</head>
<body id="omar" >
    <a id="omar1" href="#omar"><img src="picure/icon/check-double-solid.svg" alt="not found" height="25px" width="25px"></i></a>

    <main class="" style="margin-top: 10rem;">
        <section class="head">
            <ul class="nav">
                <li><img src="picure/icon/check-double-solid.svg" height="20px" width="20px" alt="not found"></li>
                <li class="menu"><h1 >Ferrari</h1>
                <ul class="submenu">
                    <li><a href="Mercedes.php">Merceds-Benz</a></li>
                    <li><a href="BMW.php">BMW</a></li>
                    <li><a href="Ferrari.php">Ferrari</a></li>
                </ul></li>
            </ul>
        </section>

        <section class="products flex">
            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/1.jpg" alt="Not Found "></a>
                <div class="content">
                    <h1 class="title">Ferrari 1</h1>
                    <p class="descrip">A four-door sports coupe that combines elegance and performance at a reasonable cost</p>
                    <div class="flex">
                        <p class="price">$300000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>
            
            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/2.jpg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari 2</h1>
                    <p class="descrip">A four-door sports coupe that combines elegance and performance at a reasonable cost</p>
                    <div class="flex">
                        <p class="price">$250000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/3.jpg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari 3</h1>
                    <p class="descrip">A luxurious, high-performance sports car from the famous AMG division</p>
                    <div class="flex">
                        <p class="price">$180000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/4.webp" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari 4</h1>
                    <p class="descrip">An SUV that combines secularism and luxury,it is verry good</p>
                    <div class="flex">
                        <p class="price">$120700</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/5.jpeg" alt="Not Found" ></a>
                <div class="content">
                    <h1 class="title">Ferrari GTC4</h1>
                    <p class="descrip">A small car, but it comes with the high-tech features that Mercedes is known for</p>
                    <div class="flex">
                        <p class="price">$155000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/6.jpeg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari 288 GTO</h1>
                    <p class="descrip">It is considered a symbol of luxury and advanced technology in its time.</p>
                    <div class="flex">
                        <p class="price">$190000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>
        </section>
        <div class="slider">
            <img src="Picure/a3.jpg" alt="Image 1" height="150px" width="80%">
            <img src="Picure/a1.jpg" alt="Image 2" height="150px" width="80%">
            <img src="Picure/a5.jpg" alt="Image 3" height="150px" width="80%">
        </div> 
        <section class="products flex">

        <?php
    include('connect.php');
    $result = mysqli_query($omar,"SELECT * FROM products WHERE type='fer'");
    $z = '<img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">';
    while ($row = mysqli_fetch_array($result)) {
        echo"
        <article class='a'>
                <a href='product-details.html'><img src='$row[image]' alt='Not Found'></a>
                <div class='content'>
                    <h1 class='title'>$row[name]</h1>
                    <p class='descrip'>$row[descripe]</p>
                    <div class='flex'>
                        <p class='price'>$$row[price]</p>
                        <button class='add'>$z
                            Add to Cart</button>
                    </div>
                </div>
            </article>";
    }
    ?>
            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/7.jpeg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari F458</h1>
                    <p class="descrip">A large SUV that offers luxury equivalent to the S-Class, but in an SUV design</p>
                    <div class="flex">
                        <p class="price">$140000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/8.jpeg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari XX</h1>
                    <p class="descrip">It is known for its high off-road capability, iconic design and luxury</p>
                    <div class="flex">
                        <p class="price">$200000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/9.jpeg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">La Ferrari</h1>
                    <p class="descrip">It is popular among business people with its classic design and upscale features.</p>
                    <div class="flex">
                        <p class="price">$160000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>
            
            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/10.jpg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari F430</h1>
                    <p class="descrip">Known for its power, excellent comfort, advanced technology and a wide choice.</p>
                    <div class="flex">
                        <p class="price">$150000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <article class="a">
                <a href="product-details.html"><img src="Picure/ferrari/11.jpeg" alt="Not Found"></a>
                <div class="content">
                    <h1 class="title">Ferrari Spider</h1>
                    <p class="descrip">A four-door sports coupe that combines elegance and performance at a reasonable cost</p>
                    <div class="flex">
                        <p class="price">$170000</p>
                        <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                            Add to Cart</button>
                    </div>
                </div>
            </article>

            <section class="products flex">
                <article class="a">
                    <a href="product-details.html"><img src="Picure/ferrari/12.jpeg" alt="Not Found"></a>
                    <div class="content">
                        <h1 class="title">Ferrari F8</h1>
                        <p class="descrip">A small car, but it comes with the high-tech features that Mercedes is known for</p>
                        <div class="flex">
                            <p class="price">$180000</p>
                            <button class="add"><img class="" src="picure/icon/cart-shopping-solid.svg"  alt="not found" style="width: 15px; height:15px">
                                Add to Cart</button>
                        </div>
                    </div>
                </article>

        </section>    
    </main>

    <script>
        var sliderImages = document.querySelectorAll('.slider img');
        var currentImageIndex = 0;
        function changeImage() {
            // Hide all images
            for (var i = 0; i < sliderImages.length; i++) {
                sliderImages[i].style.display = 'none';
            }
            // Display the current image
            sliderImages[currentImageIndex].style.display = 'block';
            // Move to the next image
            currentImageIndex++;
            if (currentImageIndex >= sliderImages.length) {
                currentImageIndex = 0;
            }
            // Change image every 3 seconds
            setTimeout(changeImage, 2000);
        }
        // Start the image slider
        changeImage();


        //الانتقال بين صفحات المنتجات
        document.getElementById('carselect').onchange=function(){
            var x=document.getElementById('carselect');
            var y=x.value;
            window.location.href=y;    
        }
    </script>
</body>
</html>

<?php
    include('footer.php');
?>