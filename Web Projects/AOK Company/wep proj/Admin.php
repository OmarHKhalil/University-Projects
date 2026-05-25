<?php
include("header.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>AOK Company</title>
    <style>
        html{
            background-color: #f5f5f5;
        }
        .main{
            border:2px  rgb(255, 228, 74) solid;
            border-radius: 30px;
            width: 70%;
            box-shadow: rgba(0, 0, 0, 0.2) 0px 2px 1px -1px, rgba(0, 0, 0, 0.14) 0px 1px 1px 0px, rgba(0, 0, 0, 0.12) 0px 1px 3px 0px;
            padding: 10px 0;
            margin-inline: auto;
            text-align: center;
            background-color: #eee;
            transition: 0.1s;
            
        }
        .main div{
            margin-block: 0rem 2rem;
            
        }
        .main input{
            padding: 10px;
            width:60%;
            border:2px  rgb(255, 228, 74) solid;
            border-radius: 30px;
        }
        .main button{
            padding:10px;
            width:40%;
            border:2px  rgb(255, 228, 74) solid;
            border-radius: 30px;
            transition: 0.2s;
        }
        .main label{
            text-align: left;
            padding:10px;
            cursor: pointer;
            font-weight: bold;
            font-size: 25px;
            text-align: left;
            width: 91%;
            display: inline-block;
            transition: 0.2s;
        }
        .main a{
            text-decoration: none;
            color:black;
            font-weight:bold;
            border-radius: 5%;
            border:2px  rgb(255, 228, 74) solid;
            margin-left: 5px;
            padding:10px;
            border-radius: 30px;
        }
        .main h1{
            font-size: 35px;
        }
        .main a:hover, button:hover{
            scale: 0.95;
            background-color:rgb(202, 200, 200);
        }
        .main a:active{
            scale: 0.95;
        }
        .main section:hover{
            scale: 0.99;
        }
        nav{
            margin-top: -238px;
            margin-left: -10px;
        }
        nav p {
            margin: 0;
        }
    </style>
</head>
<body >
    <main style="margin-block: 15rem 5rem;">
    <section class="main" >
        <div >
        <form action="insert.php" method="post" enctype="multipart/form-data">

            <h1>Admin</h1><br><br>
            <label for="">Name of Product:</label><br><br>
            <input type="text" name="name" id="" required placeholder="product name">
            <br><br><br>
            <label for="">Describe of Product:</label><br><br>
            <input type="text"  name="descripe" id="" required placeholder="product descripe">
            <br><br><br>
            <label for="">Price of Product:  </label><br><br>
            <input type="text" name="price" id="" required placeholder="product price">
            <br><br><br>
            <label for="">Image of Product:</label><br><br>
            <input type="file" name="image1" id="" required placeholder="product image">
            <br><br><br>
            <label for="">Type of Product:</label><br><br>
            <input type="text" name="type" id="" required placeholder="product type">
            <br><br><br>
            <button name="upload">Upload of Product</button>
            <br><br><br>
            <a href="all-products.php">View all products</a>
            <a href="Mercedes.php">View of Mercedes Product</a>
            <a href="BMW.php">View of Bmw Product</a>
            <a href="Ferrari.php">View of Ferrari Product</a>
            </form>
        </div>
    </sectiom>
    </main>
    <script>
        document.getElementById('carselect').onchange=function(){
            var x=document.getElementById('carselect');
            var y=x.value;
            window.location.href=y;    
        }
    </script>
</body>
</html>

<?php
include("footer.php");
?>