<?php
include('connection.php');
$errors=array();
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $username = $_POST["Username"];
    $email=$_POST["email"];
    $password=$_POST["password"];
    $Confirmpassword=$_POST["Confirmpassword"];
    $s;
    if (empty($username)) {
        $errors['username'] = "username is requird";
    }
     if (empty($email)) {
    $errors['email'] = "email is requird";  
    }
    if (empty($password)) {
    $errors['password'] = "password is requird";
    }
    if (empty($Confirmpassword)) {
    $errors['Confirmpassword'] = "confirm password is requird";
    }
    if (empty($errors)) {
    if ($password != $Confirmpassword) {
        $errors['Confirmpassword'] = "password do not match";
    }
     else {   
        $ins="INSERT INTO account (username,password,email)VALUES('$username','$password','$email')";
        $res=mysqli_query($conn,$ins);
        $s=" Account created ";
        header('location:index.php');
    }

}
mysqli_close($conn);
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign Up</title>
    <Style>
       *{
        margin: 0;
        padding: 0;
        box-sizing: border-box;
       }
       body{
        display: flex;
        align-items: center;
        flex-direction: column;
        height: 100vh;
       }
       form{
        margin-top: 50px;
        text-align: center;
       }
       input{
        display: block;
        width: 350px;
        height: 40px;
        margin: 20px;
        border: none;
        outline: none;
        font-size: 20px;
        border-bottom: solid 1px gold;
        background: transparent;
       } 
       button{
        width: 350px;
        height: 40px;
        font-size: 20px;
        margin-top: 20px;
        background-color: rgb(249, 219, 46);
        border: solid 3px white;
        color: white;
       }
       button:hover{
        cursor: pointer;
        background-color: white;
        color: rgb(249, 219, 46);
        border: solid 3px rgb(249, 219, 46);
       }
       form h1{
        color: white;
        margin-bottom: 30px;
       }
       ::placeholder{
        color:white;
       }
    </Style>
</head>
<body style="background-image: url(img/white-ferrari-on-rooftop-nicc84h9haf7boy8.jpg); background-position: center;background-repeat: no-repeat;background-attachment: fixed;background-size: cover;">
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post" style="background-color:rgb(100,100,100);opacity:0.8;border:solid 3px white;padding:20px;">
        <h1>SignUp</h1>
        <input type="text" name="Username" placeholder="Username">
        <?php if(isset($errors['username'])) { echo "<span style='color:red;'>".$errors['username']."</span>"; } ?>
       
        <input type="email" name="email" placeholder="Email">
        <?php if(isset($errors['email'])) { echo "<span style='color:red;'>".$errors['email']."</span>"; } ?>

         <input type="password" name="password" placeholder="Password">
        <?php if(isset($errors['password'])) { echo "<span style='color:red;'>".$errors['password']."</span>"; } ?>
       
        <input type="password" name="Confirmpassword" placeholder="confirm Password">
        <?php if(isset($errors['Confirmpassword'])) { echo "<span style='color:red;'>".$errors['Confirmpassword']."</span>"; } ?>
       
        <br>
        <button type="submit" name="signup">SignUp</button>
        <?php if(isset($s)){echo "<br><br><span style='color:gold;font-size:30px;'><b>".$s."<b></span>";} ?>
    </form>
</body>
</html>