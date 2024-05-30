<!doctype html>
<html>
 <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Projeto TI</title>
    <link rel="icon" type="image/x-icon" href="assets/images/estg_h.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
  <?php

session_start(); // Inicia a sessão

// Função para verificar as credenciais de login
function verificarCredenciais($username, $password, $utilizadores) {
    if (isset($utilizadores[$username])) { // Verifica se o usuário existe no array de utilizadores
        $hashArmazenada = $utilizadores[$username]["password_hash"];
        if (password_verify($password, $hashArmazenada)) { // Verifica se a senha está correta
            return true; // Credenciais corretas
        }
    }
    return false; // Credenciais incorretas
}

// Carregar os utilizadores e senhas do arquivo
$utilizadores = array();
$linhas = file("users.txt", FILE_IGNORE_NEW_LINES);
foreach ($linhas as $linha) {
    list($username, $password_hash) = explode(",", $linha);
    $utilizadores[$username] = array("password_hash" => $password_hash);
}

// Verificar se o formulário de login foi enviado
if (isset($_POST["password"])) {
    $username = $_POST["username"]; 
    $password = $_POST["password"];

    if (verificarCredenciais($username, $password, $utilizadores)) { // Verifica as credenciais
        $_SESSION["username"] = $username; // Define a sessão para o usuário logado
        header("Location: dashboard.php"); // Redireciona para a página de dashboard
        exit(); // Encerra o script após o redirecionar
    } else {
        $_SESSION["credenciais_corretas"] = false; 
        header("refresh:0;url=index.php"); // Volta ao formulário de login
        exit(); // Encerra o script após o redirecionar
    }
}


    ?>
  </body>
</html>