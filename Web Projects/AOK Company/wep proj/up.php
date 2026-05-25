<?PHP
include("connect.php");
//جلب البيانات
        if(isset($_POST['update'])){
                $ID=$_POST['id'];
                $TYPE =$_POST['type'];
                $NAME = $_POST['name'];
                $DESCRIP = $_POST['descripe'];
                $PRICE = $_POST ['price'];
                $IMAGE = $_FILES['image1'];
                $image_location = $_FILES ['image1']['tmp_name'];//الصوره والصيغه الخاصه بها
                $image_name = $_FILES ['image1']['name'];//اسم الصوره
                $image_up = "picure/".$image_name;
                $update="UPDATE products SET name ='$NAME', descripe = '$DESCRIP' , price = '$PRICE' , image = '$image_up', type='$TYPE' WHERE id=$ID" ;
            mysqli_query($omar, $update);
            if(move_uploaded_file($image_location,"picure/".$image_name)){
                echo "<script>alert('Done')</script>";
            }
            else
                echo " <script>alert('it is proplem')</script>";
            header('location:all-products.php');//الانتقال من الصفحه
        
        }
?>