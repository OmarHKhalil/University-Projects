<?php
    include("header.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="picure/icon/car-side-solid.svg" type="image/x-icon">
    <title>AOK Company all products</title>
</head>
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

main a,main button{
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
    background-color: gray;
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

nav{
            margin-top: -238px;
            margin-left: -10px;
        }
        nav p {
            margin: 0;
        }

    </style>
<body>
    <main style="margin-block: 15rem 5rem;">
        <section class="products flex">
        <?php
    include('connect.php');
    $result = mysqli_query($omar,"SELECT * FROM products");
    while ($row = mysqli_fetch_array($result)) {
        echo"
        <article class='a'>
                <a href='product-details.html'><img src='$row[image]' alt='Not Found'></a>
                <div class='content'>
                    <h1 class='title'>$row[name]</h1>
                    <p class='descrip'>$row[descripe]</p>
                    <div class='flex'>
                        <p class='price'>$$row[price]</p>
                        <button class='add'> <a href= 'delete.php? id=$row[id]'> Delete </a> </button>
                        <button class='add'> <a href= 'update.php? id=$row[id]'> Update </a> </button>
                    </div>
                </div>
            </article>";
    }
    ?>
        </section>
    </main>
    
</body>
</html>


<?php
    include('footer.php');

?>