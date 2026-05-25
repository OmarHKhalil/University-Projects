
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>AOK Company</title>
    <style>

nav{
    width: 99%;
    height: 17vh;
    padding: 1rem;
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
nav a{
    display: flex;
    text-decoration:none;
    margin-top: 1rem;
}

#ul1{
    
    display: flex;
    row-gap: 1rem;
    align-items: end;
    list-style-type:none;  
    margin-left: 0px;
    flex-wrap: wrap;
    margin-top: 1rem;
}
ul li{
    width: 100px;
}
/* تكبير عرض اليست التي */
ul #lli{
width: 125px;
}
#ul1 li select{
    font-size: 25px;
    height: 40px;
    width: 100px;
    background-color:rgb(240, 240, 240);

    text-align: center;
    border-radius: 50px;
    color: gold;
    
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

/*--logo--*/
.logo:hover{
    scale: 0.95;
}
header .logo img{
    font-size: 30px;
    color:black;
}
.logo span{
    font-weight: bold;
    font-size: 30px;
    color: rgb(255, 228, 74);
}
.logo p{
    letter-spacing: 2.5px;
    color:black;
    font-size: 30px;
}
.logo{
    display: flex;
    flex-wrap: wrap;
    margin-left: 2rem;
    gap: 2rem;
}

        @media (width <1120px) {
            nav{
                height: auto;
            }   
        }
        @media (width <720px) {
            nav .logo{
                display: none;
            }   
        }
        
    </style>
</head>
<body>
        <nav id="na" style="display: flex; flex-direction: row; justify-content: space-between;">
            <a class="logo" href="homepage.php">
                <img src="picure/icon/car-side-solid.svg" height="80px" width="80px" alt="not found" style="color:black">
                <div>
                    <SPAN>AOK</SPAN>
                    <P >Company</P>
                </div>
            </a>
            <div>
            <ul id="ul1">
                <li id="lli"><select name="" id="carselect">
                    <option value="">Cars</option>
                    <option value="Mercedes.php">Mercedes</option>
                    <option value="BMW.php">BMW</option>
                    <option value="Ferrari.php">Ferrari</option>
                </select></li>
                
                <li><a href="homepage.php"><button id="a1">Homepage</button></a></li>
                <li id="li3"><a href="homepage.php #gallery" class="c"><button id="a1">Gallery</button></a></li>
                <li id="li2"><a href="homepage.php #sercics"class="c"><button id="a1">Service</button></a></li>
                <li ><a href="homepage.php #lastnews" class="c"><button id="a1">Last News</button></a></li>
                <li id="li1"><a href="homepage.php #about" class="c"><button id="a1">About Us</button></a></li>
                <li ><a href="term.php" class="c"><button id="a1">Term</button></a></li>
                
            </ul>
        </div>
        </nav>

</body>
</html>