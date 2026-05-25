<?PHP
include("connect.php");
//جلب البيانات
        if(isset($_POST['upload'])){
                $NAME = $_POST['name'];
                $DESCRIP = $_POST['descripe'];
                $PRICE = $_POST ['price'];
                $IMAGE = $_FILES['image1'];
                $image_location = $_FILES ['image1']['tmp_name'];//الصوره والصيغه الخاصه بها
                $image_name = $_FILES ['image1']['name'];//اسم الصوره
                $image_up = "picure/".$image_name;
                $TYPE = $_POST["type"];
                $insert = "INSERT INTO products(name,descripe,price,image,type) VALUES('$NAME','$DESCRIP','$PRICE','$image_up','$TYPE')";
            mysqli_query($omar, $insert);
            if(move_uploaded_file($image_location,"picure/".$image_name)){
                echo "<script>alert('Done')</script>";
            }
            else
                echo " <script>alert('it is proplem')</script>";
            header('location: Admin.php');//الانتقال من الصفحه
        
        }

        ?>