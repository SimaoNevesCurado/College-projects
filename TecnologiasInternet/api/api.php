  <?php 


  // Define o cabeçalho para indicar que a resposta será em texto HTML com codificação UTF-8
  header('Content-Type: text/html; charset=utf-8');

  // Define o fuso horário para a Europa/Londres = Lisboa
  date_default_timezone_set("Europe/London");

  if ($_SERVER["REQUEST_METHOD"] == "POST"){

  echo("recebi um poste");
  print_r ( $_POST );
  if(isset($_POST["valor"]) && isset( $_POST["nome"]) && isset($_POST["hora"])){
    file_put_contents("files/". $_POST["nome"] ."/valor.txt", $_POST["valor"]);
    file_put_contents("files/" . $_POST['nome'] . "/hora.txt", date('d-m-Y H:i:s'));
    file_put_contents("files/". $_POST["nome"] ."/nome.txt", $_POST["nome"]);
    file_put_contents("files/". $_POST["nome"] ."/log.txt", "Hora: ".$_POST["hora"]." | Valor: ".$_POST["valor"]. "\r\n",FILE_APPEND);
  }

  } elseif ($_SERVER['REQUEST_METHOD'] == "GET") {
      // Se o método HTTP for GET, verifica se 'nome' e 'field' foram enviados
      if (isset($_GET['nome']) && isset($_GET['field'])) {
          // Verifica se o ficheiro solicitado existe
          if (file_exists("files/" . $_GET['nome'] . "/" . $_GET['field'] . ".txt")) {
              // Se existir, retorna o conteúdo do ficheiro
              echo (file_get_contents("files/" . $_GET['nome'] . "/" . $_GET['field'] . ".txt"));
          } else {
              // Se não existir, retorna mensagem de erro e código HTTP 404
              echo ("Parâmetros Insuficientes para completar o GET");
              http_response_code(404);
          }
      } else {
          // Se faltar parâmetros no GET, retorna mensagem de erro e código HTTP 400
          echo ("Faltam parametros no GET");
          http_response_code(400);
      }
  } else {
      // Se o método HTTP não for POST nem GET, retorna erro e código HTTP 403
      echo "Método não permitido";
      http_response_code(403);
  }
  ?>  