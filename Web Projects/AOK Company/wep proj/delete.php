<?php
    include("connect.php");//الاتصال مع قاعده البيانات
    $ID = $_GET["id"];//احضار ال ID
    mysqli_query($omar,"DELETE FROM products WHERE id = $ID");
    header('location: all-products.php');//الانتقال من الصفحه

?>