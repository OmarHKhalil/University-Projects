<?php
 include('connection.php');
 session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    
if (isset($_SESSION['email'])) {
    if(isset($_POST["m"])){
        header('location:Mercedes.php');
    }
    else if(isset($_POST["b"])){
        header('location:BMW.php');
    }else if(isset($_POST["f"])){
        header('location:Ferrari.php');
    }
}
 else if(!isset($_SESSION['email'])){
    header('location:index.php');
}

    if (isset($_POST["bg"]) && isset($_POST["yt"]) && isset($_POST["num"])){
        $bogo = $_POST["bg"];
        $yote = $_POST["yt"];
        $r = $_POST["num"];
        $star;
        $gender;
        $ins;
        if( $bogo=="b"){
            $gender="img/boy 1.png";
            if($r=="5"){
            $star="img/5 stars.jpg";
            $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
            mysqli_query($conn,$ins);
        }
            else if($r=="4"){
            $star="img/4 stars.jpg";
            $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
            mysqli_query($conn,$ins);
            }
            else if($r=="3"){
            $star="img/3 stars.jpg";
            $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
            mysqli_query($conn,$ins);
            }
            else if($r=="2"){
            $star="img/2 stars.jpg";
            $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
            mysqli_query($conn,$ins);
        }
            else if($r==1){
            $star="img/1 star.jpg";
            $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
            mysqli_query($conn,$ins);
        }
        }
        else{
                $gender="img/girl 1.jpg";

                if($r=="5"){
                $star="img/5 stars.jpg";
                $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
                mysqli_query($conn,$ins);}
                else if($r=="4"){
                $star="img/4 stars.jpg";
                $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
                mysqli_query($conn,$ins);}
                else if($r=="3"){
                $star="img/3 stars.jpg";
                $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
                mysqli_query($conn,$ins);}
                else if($r=="2"){
                $star="img/2 stars.jpg";
                $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
                mysqli_query($conn,$ins);}
                else if ($r=="1"){
                $star="img/1 star.jpg";
                $ins="INSERT INTO rate (rateimg,personimg,txt)VALUES('$star','$gender','$yote')";
                mysqli_query($conn,$ins);}
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <LINK rel="icon" type="image/png" href="img/123.png">
    <title>AOK</title>
    <style>
        *{box-sizing: border-box;
padding: 0;
margin: 0;
}
#di nav{
    width: 100%;
    height: 17vh;
    background-color: white;
    font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
    color: black;  
    position: relative;
    z-index: 2;
    border-bottom: solid 2px gold;
    box-shadow: solid 2px black;
    position: fixed;
    border-bottom-left-radius: 50px;
    border-bottom-right-radius:50px ;
 }
#ul1{
    width: 600px;
    display: flex;
    justify-content: flex-end;
    align-items: end;
    list-style-type:none;  
}
ul li{
    width: 100px;
}
/* تكبير عرض اليست التي */
ul #lli{
width: 125px;
}
ul li button{
width: 80px;
height: 40px;
border-color: gold;
border-radius: 40px;
font-weight: bold;
text-align: center;
cursor: pointer;
}
ul li button:hover{
    background-color:rgb(202, 200, 200);
}
/* -------------------------------------- */
.slider {
    width: 600px;
    height: 400px;
    overflow: hidden;
    position: relative;
}

.slider-img {
    width: 100%;
    height: 100%;
    object-fit: cover;
}

.slider-prev,
.slider-next {
    position: absolute;
    top: 50%;
    transform: translateY(-50%);
    font-size: 24px;
    color: #fff;
    background-color: rgba(0, 0, 0, 0.5);
    padding: 8px 12px;
    cursor:pointer;
}

.slider-prev {
    left: 10px;
}

.slider-next {
    right: 10px;
}
/* ------------------------------------- */
.containr{
    width: 98vw;
    height: 1030px;
    /* border: solid 3px red; */
    display: grid;
    grid-template-columns: 50px 29% 50px 29% 50px 29% 50px;
    grid-template-rows:100px 30px 100px 30px  ;
}
.item-1{
    /* width: 20vw; */
    /* height: 60px; */
    border: solid 3px gold;
    background-color: white;
    font-weight: bold;
    grid-column-start:2 ;
    grid-column-end: 2;
    grid-row-start:1 ;
    grid-row-end:1 ;
    padding: 2px;
    text-align: center;
    border-radius: 20px;
    /* position:absolute;
    top: auto; */
}

.item-2{
    /* width: 20vw;
    height: 400px; */
    border: solid 3px gold;
    font-weight: bold;
    grid-column-start:4 ;
    grid-column-end: 4;
    grid-row-start:1 ;
    grid-row-end:1 ;
    padding: 2px;
    text-align: center;
    border-radius: 20px;
    background-color: white;
}
.item-3{
    background-color: white;
    /* width: 20vw;
    height: 400px; */
    border: solid 3px gold;
    font-weight: bold;
    grid-column-start:6 ;
    grid-column-end: 6;
    grid-row-start:1 ;
    grid-row-end:1 ;
    padding: 2px;
    text-align: center;
    border-radius: 20px;
}

.item-4{
    height: 350px;
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:2 ;
    grid-column-end: 2;
    grid-row-start:3 ;
    grid-row-end:3 ;
    margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
    padding: 5px 5px 5px 5px;
}
.item-4:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
  }
  .item-5{
    height: 350px;
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:4 ;
    grid-column-end: 4;
    grid-row-start:3 ;
    grid-row-end:3 ;
    margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
     padding: 5px 5px 5px 5px;

}
.item-5:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
}
.item-6{
    height: 350px;
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:6 ;
    grid-column-end: 6;
    grid-row-start:3 ;
    grid-row-end:3 ;
    margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
    padding: 5px 5px 5px 5px;
}
.item-6:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
  }
.item-7{
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:2 ;
    grid-column-end: 2;
    grid-row-start:6 ;
    grid-row-end:6 ;
    margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
    padding: 5px 5px 5px 5px;
    height: 350px;
}
.item-7:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
}
.item-8{
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:4 ;
    grid-column-end: 4;
    grid-row-start:6 ;
    grid-row-end:6 ;
    margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
    padding: 5px 5px 5px 5px;
    height: 350px;
}
.item-8:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
}
.item-9{
    height: 350px;
    width: 400px;
    border: solid 2px gold;
    border-radius: 10px;
    grid-column-start:6 ;
    grid-column-end: 6;
    grid-row-start:6 ;
    grid-row-end:6 ;margin: auto;
    text-align: center;
    background-color: white;
    /* box-shadow: 1px 1px 1px 1px black; */
    overflow: hidden;
    padding: 5px 5px 5px 5px;
}
.item-9:hover{
    transform: scale(1.1);
    box-shadow: 2px 2px gold;
}
img{ border-radius: 10px;}
/* Scrolbar */ 

  ::-webkit-scrollbar{
    width: 7px;
    
}
::-webkit-scrollbar-track{
    background-color: white;
    border-radius: 50px;
}
::-webkit-scrollbar-thumb{
    background-color: rgb(251, 226, 84);
    border-radius: 50px;
} 
/* ------------------------------------------------------- */
    #scroll-to-top {
      position: fixed;
      bottom: 20px;
      right: 20px;
      display: none; /* Initially hidden */
      z-index: 100;
      /* background-color: #4CAF50; Green */
      color: white;
      padding: 10px 15px;
      border-radius:50%;
      border-color: gold;
      cursor: pointer;
      transition: opacity 0.3s ease-in-out, transform 0.3s ease-in-out; /* Add transitions */
    }

    #scroll-to-top.show {
      display: block;
      
      opacity: 1;
      transform: translateY(-5px); /* Translate for bounce effect */
    }
    #scroll-to-top img{
        height: 30px;
        border-radius: 50px;
    }
    /* ---------------------- */
    footer{
        text-align: center;
        background-color: white;
        color: black;
        font-size: 17px;
        padding-block: 1rem;
        margin-top: 3rem;
        box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        border-top: 1px solid  gold;
        border-radius: 50px 50px 0 0;
        -webkit-border-radius: 50px 50px 0 0;
        -moz-border-radius: 50px 50px 0 0;
        -ms-border-radius: 50px 50px 0 0;
        -o-border-radius: 50px 50px 0 0;
        line-height: 2rem;
    }
    footer span{
        color: rgb(255, 228, 74);
        text-transform: capitalize;
    }
    footer .managed{
        display: flex;
        justify-content: space-between;
    }
    footer a{
        display: block;
        padding: 10px;
    }
    footer .icon{
        display: flex;
        justify-content: center;
        gap: 2rem;
        margin: 2rem 0;
    }
    </style>

</head>
<body style="background-color: rgb(240, 240, 240);z-index: 1;">
    <div style="width: 99vw;height: 100vh;">
        
    <!-- navbar -->
    <div id="di">
        <nav id="na">
            <br> 
            <img src="img/123.png" alt="logo" height="60px" style="z-index: 1;transform: translate(100px,10px);">
            <h2 style="transform: translate(200px,-50px);">Welcome To <br>&#160&#160&#160&#160&#160<span style="color: gold;">AOK</span></h2>
            <ul id="ul1" style="transform: translate(900px,-90px);">
                <div style="display:flex;">
                <div style="transform: translate(-250px,-35px);">
                <li style="height: 55px;"><a href="index.php"><button id="a1">log in</button></a></li>
                <li style="height: 55px;"><a href="signup.php"><button id="a1">Sign up</button></a></li> 
                </div>
                <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post" style="display: flex;">
                <li><a href="Mercedes.php"><button name="m">Mercedes</button></a></li>
                <li><a href="BMW.php"><button name="b">BMW</button></a></li>
                <li><a href="Ferrari.php"><button name="f">Ferrari</button></a></li>
                </form>
                <li id="li3"><a href="#gallery" class="c"><button id="a1">Gallery</button></a></li>
                <li id="li2"><a href="#sercics"class="c"><button id="a1">Service</button></a></li>
                <li ><a href="#lastnews" class="c"><button id="a1">Last News</button></a></li>
                <li id="li1"><a href="#about" class="c"><button id="a1">About Us</button></a></li>
                <li ><a href="term.php" class="c"><button id="a1">Term</button></a></li>
                </div>
            </ul>
        </nav>
    </div>
<br>

<!-- ---------------------- slider -->

<br><br><br><br><br>
<section style="display: flex;justify-content: space-between;">
<div class="slider" style="width: 40vw;height: 55vh; ; border: solid 2px gold;overflow: hidden;background-color: white;margin-left: 50px;border-radius: 15px;margin-top: 120px;">
    <img src="img/bmw-logo-machine-embroidery-design-615-750x750.jpg" alt="" class="slider-img">
    <img src="img/ferrari.jpg" alt="" class="slider-img">
    <img src="img/emblem.jpg" alt="" class="slider-img">
    <div class="slider-prev" onclick="changeSlide(-1)">&#10094;
    </div>
    <div class="slider-next" onclick="changeSlide(1)">&#10095;
    </div>
</div>
<br>
<br>
<div style="border: solid 2px gold;width: 42vw;height: 55vh; margin-right: 50px;padding-top: 15px;padding-left: 30px;padding-right: 30px;padding-bottom: 15px ;background-color: white;overflow: auto;margin-top: 120px;">
    <h2 style="text-align: center; font-weight:bold;color:gold;">Top Rate</h2>
    <ol style="list-style-type: none;">
    <?php
      $sel="SELECT * FROM rate";
      $sel=mysqli_query($conn,$sel);
      if (mysqli_num_rows($sel) > 0){
        while ($row = mysqli_fetch_assoc($sel)){
            $g=$row["personimg"];
            $s=$row["rateimg"];
            $yote=$row["txt"];
            echo"<li style='height: 100px;'><img src='$g'alt='' style='height: 40px; border-radius: 50px;width: 40px;z-index: 1;'>&#160<img src='$s'alt='' style='height: 40px;'><br>$yote";
        }
      }
        //$sql="DELETE * FROM rate";
        //mysqli_query($conn,$sql);
      mysqli_close($conn);
    ?>

        <li style="height: 100px;"><img src="img/boy 1.png" alt="" style="height: 40px; border-radius: 50px;width: 40px;">&#160<img src="img/5 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nam eius est earum optio possimus ullam recusandae quasi nihil harum architecto expedita rerum eum accusamus totam cum, dicta officia, nesciunt perspiciatis.</li><br>
        <li style="height: 100px;"><img src="img/girl 1.jpg" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/5 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime officia deserunt ex at? Culpa eum hic voluptates quasi vel eius dolore quo, sed ducimus exercitationem, repudiandae eaque ipsam dolores necessitatibus!</li><br>
        <li style="height: 100px;"><img src="img/boy 2.png" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/5 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur adipisicing elit. Id, aliquid. Voluptatibus rerum inventore quia mollitia sunt deserunt dolor libero amet, natus a nemo incidunt, tenetur iusto nisi minima accusamus. Excepturi.</li><br>
        <li style="height: 100px;"> <img src="img/girl 2.jpg" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/4 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit, amet consectetur adipisicing elit. Esse voluptate ea quia reiciendis cupiditate tenetur nam aut aperiam quas nobis voluptatem quos minus cum, commodi in porro optio tempore libero?</li><br>
        <li style="height: 100px;"><img src="img/boy 1.png" alt="" style="height: 40px; border-radius: 50px;width: 40px;">&#160<img src="img/4 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nam eius est earum optio possimus ullam recusandae quasi nihil harum architecto expedita rerum eum accusamus totam cum, dicta officia, nesciunt perspiciatis.</li><br>
        <li style="height: 100px;"><img src="img/girl 1.jpg" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/4 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime officia deserunt ex at? Culpa eum hic voluptates quasi vel eius dolore quo, sed ducimus exercitationem, repudiandae eaque ipsam dolores necessitatibus!</li><br>
        <li style="height: 100px;"><img src="img/boy 2.png" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/3 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur adipisicing elit. Id, aliquid. Voluptatibus rerum inventore quia mollitia sunt deserunt dolor libero amet, natus a nemo incidunt, tenetur iusto nisi minima accusamus. Excepturi.</li><br>
        <li style="height: 100px;"> <img src="img/girl 2.jpg" alt="" style="height: 40px;border-radius: 50px;width: 40px;">&#160<img src="img/3 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit, amet consectetur adipisicing elit. Esse voluptate ea quia reiciendis cupiditate tenetur nam aut aperiam quas nobis voluptatem quos minus cum, commodi in porro optio tempore libero?</li><br>
        <li style="height: 100px;"><img src="img/boy 1.png" alt="" style="height: 40px; border-radius: 50px;width: 40px;">&#160<img src="img/3 stars.jpg" alt="" style="height: 40px;"><br>Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nam eius est earum optio possimus ullam recusandae quasi nihil harum architecto expedita rerum eum accusamus totam cum, dicta officia, nesciunt perspiciatis.</li><br>
    </ol>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">

    <label for="">Write your Rate:</label><br> <textarea name="yt" id="" rows="3"  style="border: solid 2px gold; width:fit-content"></textarea> <br><br><br><br><select name="bg" id="" style="border: solid 2px gold;">
    <option value="">Boy or Girl</option>
    <option value="b">Boy</option>
    <option value="g">Girl</option>
    </select>
    &#160;&#160;&#160;&#160;&#160;<label for="">How many stars:</label><select name="num" id="" style="border: solid 2px gold;">
    <option value=""></option>
    <option value="5">5</option>
    <option value="4">4</option>
    <option value="3">3</option>
    <option value="2">2</option>
    <option value="1">1</option>
    </select>
<br><br><br><br><br>
<input type="submit" value="Submit" style="transform: translateX(16vw);border:solid 2px gold;font-size:30px; border-radius:50px;">
    </form>
</div>
</section>
<br><br>
<button id="scroll-to-top"><img src="img/scrollbuten.png" alt=""></button>

    

<!-- ////////////// -->
</div>
<!-- ///////////// -->
<!-- ---------------------- -->
<!-- ////////////// -->
<div style="width: 99vw;">
<!-- ///////////////// -->
<br><br><br>
<!-- ///////////////////////////// -->
<div id="gallery">
    <br><br>
<!-- ////////////////////////////////////// -->
    <h2 style="text-align: center;color:  rgb(0, 0, 0); transform: translateY(110px);">The Most beatiful and luxurious Cars</h2>
    <div class="containr" style="margin-top: 150px;">
    <br>
    
<!-- /////////////////// -->
        <div class="item-1"><h3 style="margin-top: 25px;">Mercedes</h3></div>
        <div class="item-2"><h3 style="margin-top: 25px;"> BMW</h3></div>
        <div class="item-3"><h3 style="margin-top: 25px;">Ferrari</h3></div>
    <!-- ///////////////////////////// -->
    
        <div class="item-4"><a href="img/cars/marcedes benz s class.jpg" target="_blank"><img src="img/cars/marcedes benz s class.jpg" alt=""></a>
        <p style="font-size: 20px;"><br>Mersedes benz-s-class</p>
        <br>
        </div>
        <div class="item-5"><a href="img/cars/X6.jpg" target="_blank"><img src="img/cars/X6.jpg" alt=""></a>
        <p style="font-size: 20px;"><br>BMW M6</p>
        <br>
        </div>
         <div class="item-6"><a href="img/cars/gf.jpg" target="_blank"><img src="img/cars/gf.jpg" alt=""></a>
        <p style="font-size: 20px;"><br>Ferrari 254EE</p>
        <br>
        </div>

        <div class="item-7"><a href="img/cars/g class.jpg" target="_blank"><img src="img/cars/g class.jpg" alt=""></a>
        <p style="font-size: 20px;"><br>Mercedes G class</p><br>
        </div>
        <div class="item-8"><a href="img/cars/X5.jpg" target="_blank"><img src="img/cars/X5.jpg" alt=""></a>
        <p style="font-size: 20px;"><br>BMW X5</p>
        </div>
        <div class="item-9"><a href="img/cars/Screenshot (112).png" target="_blank"><img src="img/cars/Screenshot (112).png" alt=""></a>
        <p style="font-size: 20px;"><br>Ferrari f40</p><br>
        </div>

    </div>
<!-- //////////////// -->
    </div>

<!-- /////////////// -->
</div>
<!-- ////////////// service-->
<div id="sercics">
<h1  style="color:gold; text-align: center;transform: translateY(160px);">Our Services</h1>
<br><br>
<p style="text-align: center; font-weight: bold;font-size: 20px;transform: translateY(160px);">We offer you many services ,including buing cars either old cars or new cars .</p>
<br>
<section style="display: flex;justify-content: space-between;transform: translateY(160px); ">
    <div style="width: 40vw; padding: 20px; font-family: 'Times New Roman', Times, serif; font-size: 20px;">
         <dl>
             <dt>Mercedes</dt>
            <dd>We deal whith Mercedes and we have many garages ,for examole Las Vegas garage ,vina garage ,London garage ,Damascus garage,and Dubai garage.</dd>
            <br><br>
            <dt>BMW</dt>
            <dd>We deal whith BMW and we have many garages ,for examole Las Vegas garage ,vina garage ,London garage ,Damascus garage,and Dubai garage.</dd>
            <br><br>
            <dt>Ferrari</dt>
            <dd>We deal whith Ferrari and we have many garages ,for examole Las Vegas garage ,vina garage ,London garage ,Damascus garage,and Dubai garage.</dd>
        </dl>
        <br><br><br><br>
        <div style="display: flex; justify-content: space-evenly; width: 50vw;transform: translateY(-80px);">
            <img src="img/bmwgar.jpg" alt="" class="imgl" style="border: solid 2px gold;border-radius: 10px;">
            <img src="img/ferrre.jpg" alt="" class="imgl"style="border: solid 2px gold;border-radius: 10px;" >
        </div>
    </div>
    <div style="width: 40vw;overflow: hidden;height: 76vh; margin-right: 20px;border: solid 2px gold;border-radius: 10px;"><img src="img/Certified-Pre-Owned-Mercedes-Benz-1024x683.jpg" alt="">
    </div>
</section>
<br><br><br>
</div>
<br><br><br>
<!-- last news -->
<p id="lastnews" style="transform: translateY(-130px);"></p>
<br>
<div style="border: solid 2px gold; height: 550px;width: 92vw; border-radius: 10px;margin-left: 50px;overflow: auto;padding-left: 30px;padding-top: 10px;padding: bottom 10px;background-color: white;">
    <h2 style="text-align: center; color:gold;">Last News</h2>
    <ol  style="padding: 20px;">
    <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add BMW X5 Model 2024</p><a href="img/cars/xx55.jpg" style="margin-left: 600px;"><img src="img/cars/xx55.jpg" alt="" style="height:100px;width:200px; "></a></li><br><br>
        <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add Ferrari 254EE Model 2024</p><a href="img/cars/ff44.jpg" style="margin-left: 600px;"><img src="img/cars/ff44.jpg" alt="" style="height:100px; width:200px;"></a></li><br><br>
        <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add Ferrari f40 Model 2024</p><a href="img/cars/photo1716917261.jpeg" style="margin-left: 600px;"><img src="img/cars/photo1716917261.jpeg" alt="" style="height:100px;width:200px;"></a></li><br><br>
        <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add Mercedes G class Model 2024</p><a href="img/cars/gg.jpg" style="margin-left: 600px;"><img src="img/cars/gg.jpg" alt="" style="height:100px;width:200px;"></a></li><br><br>
        <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add BMW M6 Model 2024</p><a href="img/cars/xx66.jpg" style="margin-left: 600px;"><img src="img/cars/xx66.jpg" alt="" style="height:100px;width:200px; "></a></li><br><br>
        <li style="height: 90px;font-size:30px;display:flex;"><p style="display: inline;width:600px;">we add Mersedes benz-s-class Model 2024 </p>  <a href="img/cars/ss.jpg" style="margin-left: 600px;"><img src="img/cars/ss.jpg" alt="" style="height:100px;width:200px;"></a></li><br><br>

    </ol>
</div>
<br><br>
<!-- ////////////////////////about us -->
<p id="about" style="transform: translateY(-140px);"></p>
<h1  style="color:gold;align-items: center;text-align: center;font-weight: bold;">About Us</h1>
<br><br>
<section id="sec" style="display: flex;justify-content:center;">

    <div id="di2" style=" width: 40vw;height: 50vh;font-size: 40px;padding-right:  60px;"><p id="p1">This company was founded by kusai almanlla and omer alzobe 
        and abdulaziz bawabeh in 2024. <br> The goal of its establishment is to make the car buying process easier.
     </p>
     
    <!-- <button id="butt" style="font-size: 20px;margin-left: 20px; border-radius:5px;background-color: aqua;">Read More</button> -->
    </div>

<div id="di1" style=" border:solid 2px gold;
width: 42vw;height: 60vh;overflow: hidden;background-color: white;overflow: auto;position: relative;">
    <div id="di11" style="position: absolute;"> 
        <h2 id="oo" style="margin-left: 150px;text-align: center;color: red;z-index: auto;">The Location of Our Company</h2>
    </div>
    <img src="img\0004-newwarkkk.jpg" alt="" style="border-radius: 0px;">
    <br>
    <p style="text-align: center; font-size: 20px;"><b>The comoany is located in New Yourk city  at 578 Street</b></p>
    <br>
</div>
</section>
<br><br>

<!-- /////////////////////// -->
<!-- <br> -->
<?php
include('footer_k.php');
?>

<script>
    var sliderImages = document.querySelectorAll('.slider-img');
var currentImageIndex = 0;

function changeSlide(n) {
    currentImageIndex += n;

    if (currentImageIndex < 0) {
        currentImageIndex = sliderImages.length - 1;
    } else if (currentImageIndex >= sliderImages.length) {
        currentImageIndex = 0;
    }

    for (var i = 0; i < sliderImages.length; i++) {
        sliderImages[i].style.display = 'none';
    }

    sliderImages[currentImageIndex].style.display = 'block';
}

function startSlider() {setInterval(function() {changeSlide(1);}, 1500);
}
startSlider();
// ---------------------------------

const scrollToTopButton = document.getElementById('scroll-to-top');

// Show the button when scrolling down
window.addEventListener('scroll', () => {
  if (window.pageYOffset > 100) {
    scrollToTopButton.classList.add('show');
  } else {
    scrollToTopButton.classList.remove('show');
  }
});

// Scroll to the top when the button is clicked
scrollToTopButton.addEventListener('click', () => {
  window.scrollTo({
    top: 0,
    behavior: 'smooth' // Smooth scrolling effect
  });
});
</script>
</body>
</html>