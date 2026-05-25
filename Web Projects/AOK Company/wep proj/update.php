<?php
include("header.php");
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="picure/icon/car-side-solid.svg" type="image/x-icon">
    <title>AOK Company Update</title>
    <style>
        body{
            background-color: #f5f5f5;
        }
        .main{
            border:2px  rgb(255, 228, 74) solid;
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
        input,textarea{
            padding: 10px;
            width:60%;
            border:2px  rgb(255, 228, 74) solid;
            border-radius: 30px;
            transition: 0.2s;
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
<body>
    
    <?php
        include("connect.php");
        $ID = $_GET["id"];// جلب id  المنتج الذي نحن فيه
        $up = mysqli_query($omar,"SELECT * FROM products WHERE id = $ID ");//  جلب كل البيانات من القواعد والاتصال بها
        $data = mysqli_fetch_array($up);//جلب كل البيانات من up
    ?>

    <main style="margin-block: 15rem 5rem;">
    <section class="main">
        <div>
        <form action="up.php" method="post" enctype="multipart/form-data">

            <h1>Update Products</h1><br><br>
            <label for="">Id of Product:</label><br><br>
            <input type="text" name="id" id="" value="<?php echo $data["id"]  ?>" readonly>
            <br><br><br>
            <label for="">Type of Product:</label><br><br>
            <input type="text" name="type" id="" value="<?php echo $data["type"]  ?>" readonly>
            <br><br><br>
            <label for="">Name of Product:</label><br><br>
            <input type="text" name="name" id="" value="<?php echo $data ["name"] ?>" required placeholder="product name">
            <br><br><br>
            <label for="">Describe of Product:</label><br><br>
            <input type="text" name="descripe" id="" value="<?php echo $data ["descripe"]?>" required placeholder="product descripe">
            <br><br><br>
            <label for="">Price of Product:</label><br><br>
            <input type="text" name="price" id="" value="<?php echo $data ["price"]?>" required placeholder="product price">
            <br><br><br>
            <label for="">Update image:</label><br><br>
            <input type="file" name="image1" id="" value="<?php echo $data ["image"]?>" required placeholder="product image">
            <br><br><br>
            <button name="update" type="submit">Update of Product</button>
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