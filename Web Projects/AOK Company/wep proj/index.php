<?php
    include("connection.php");
    session_start();
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        if (isset($_POST['login'])){
            if ($_POST['email'] == "" || $_POST['password'] == "") {
                echo "<script type='text/javascript'>alert('data not complete!!');</script>";
                die(); 
            } else {
                $email = $_POST['email'];
                $password = $_POST['password'];
                $data = mysqli_query($conn, "SELECT * FROM account WHERE email='$email' AND password='$password'");
                if (mysqli_num_rows($data) > 0 &&$email=="admin@example.com" || $email=="mo5rb600@gmail.com") {
                    $_SESSION['email'] = $email;
                    header('location:Admin.php');
                    exit;
                } else if(mysqli_num_rows($data) > 0) {
                    $_SESSION['email'] = $email;
                    header('location:homepage.php');
                    exit;
                }
                else{
                    echo "<script type='text/javascript'>alert('data not found!!');</script>";
                }
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
    <title>Document</title>
    <style>
body{
    background-image: url("img/35860.jpg");
    background-repeat: no-repeat;
    background-size: cover;
    background-attachment: fixed;
}
#d1{
    margin-left:100px ;
    margin-top:150px ;
    width:350px ;
    height:450px ;
    background-color: #ffffff;
    opacity:0.8 ;
    border-radius:15px;
    border: 1px solid gold;
}
#e1{
    width:220px ;
    height:30px ;
    margin-left:19px  ;
    transform: translate(-10px, -90px); 
    background-color: #000000;
    opacity:0.6 ;
    border-radius:20px ;
    border-color: gold;
    color: gold;
}
#p1{
    width:220px ;
    height:30px ;
    margin-left:25px  ;
    transform: translate(0px, -60px); 
    background-color: #000000;
    opacity:0.6 ;
    border-radius:20px ;
    border-color: gold;
    color: gold;
}
#s1{
    width:150px ;
    height:40px ;
    margin-left:25px  ;
    font-size:19px ;
    font-family: 'Times New Roman', Times, serif;
    transform: translate(140px, -20px); 
    background-color: #000000;
    opacity:0.6 ;
    border-radius:20px ;
    border-color: gold;
    color: gold;
}
#s1:hover{
    color: white;
}
#s2{
    width:150px ;
    height:40px ;
    transform: translate(-15px, 40px); 
    font-size:19px ;
    font-family: 'Times New Roman', Times, serif;
    background-color: #000000;
    opacity:0.6 ;
    border-radius:30px ;
    border-color: gold;
    color: gold;
}
#s2:hover{
    color: white;
}
#ic1{
 width:60px;
 margin-left:20px ;   
 transform: translate(0px, -65px); 
}
#ic2{
    width:37px;
    margin-left:25px ;   
    transform: translate(0px, -45px); 
}
#a1{
    width:150px ;
    transform: translate(100px, -80px);
}
#i2{
width: 60px;
transform: translate(40px, -110px); 
}
#i3{
    width: 100px;
    transform: translate(-45px, -20px); 
    }
    .error{
        font-size:20px ;
        color: red;
        font-family: 'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
    }

    </style>
</head>
<body>
    
   
 <div id="d1">
    <img src="img/a.png" id="a1">
        <form id="f1" method="post"action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
          <img src="img/b.png" id="ic1">
           <input type="email" id="e1" name="email" placeholder="email" > <br>
           <img src="img/c.png" id="ic2" >
           <input type="password" id="p1"  name="password" placeholder="password" >
           <input type="submit" id="s1" value="LOGIN" name="login">
           <button id="s2"> <a href="signup.php" style="color:gold;text-decoration: none;">Sing up</a></button>
           <a href="https://www.facebook.com/"><img src="img/d.png" id="i2"></a>
           <a href="https://www.google.com/"  ><img src="img/g.png" id="i3"></a>
        </form>
 </div>
</body>
</html>