<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>logout</title>
    <link rel="icon" type="image/x-icon" href="assets/images/estg_h.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    <?php
        session_start();   //diz ao browser para utilizar variáveis de sessão;
        session_unset();   //remove todas as variáveis de sessão
        session_destroy(); //destrói a sessão
        header("refresh:0;url=index.php");
    ?>
  </body>
</html>