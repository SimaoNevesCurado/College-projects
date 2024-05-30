<!DOCTYPE html>
<html lang="pt">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="icon" type="image/x-icon" href="assets/images/estg_h.png">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/boxicons@latest/css/boxicons.min.css">
  <link rel="stylesheet" href="assets/css/main.css">
  <link rel="stylesheet" href="assets/css/dashboard-page.css">
  <title>Dashboard</title>
</head>

<?php
//para informar o servidor qeue o browser vai usar variáveis de início de sessão
session_start();
if(!isset($_SESSION['username'])){  //se a sessão não estiver iniciada
  header("refresh:2;url=index.php");  //Manda um cabeçalho HTTP ao navegador para dar refresh à página e direcioná-la para o index.php
  die("Acesso restrito");
}


//Obtem os valores da temperatura diretamente dos ficheiros da API
$valor_temperatura = file_get_contents("api/files/temperatura/valor.txt");
$log_temperatura = file_get_contents("api/files/temperatura/log.txt");
$nome_temperatura = file_get_contents("api/files/temperatura/nome.txt");
$hora_temperatura = file_get_contents("api/files/temperatura/hora.txt");

//Obtem os valores dos clientes diretamente dos ficheiros da API
$valor_clientes = file_get_contents("api/files/clientes/valor.txt");
$log_clientes = file_get_contents("api/files/clientes/log.txt");
$nome_clientes = file_get_contents("api/files/clientes/nome.txt");
$hora_clientes = file_get_contents("api/files/clientes/hora.txt");

//Obtem os valores dos clientes diretamente dos ficheiros da API
$valor_quarto = file_get_contents("api/files/quartos/valor.txt");
$log_quarto = file_get_contents("api/files/quartos/log.txt");
$nome_quarto = file_get_contents("api/files/quartos/nome.txt");
$hora_quarto = file_get_contents("api/files/quartos/hora.txt");



//calcula percentagens para colocar na progress bar e respetivas classes
$percent_clientes = ($valor_clientes * 100) / 40;
$percent_clientesClass = 'style="width:' . $percent_clientes . '%" aria-valuenow="50" aria-valuemin="0" aria-valuemax="100"';
$percent_Temperatura = ($valor_temperatura * 100) / 25;
$percent_TemperaturaClass = 'style="width:' . $percent_Temperatura . '%" aria-valuenow="50"aria-valuemin="0"aria-valuemax="100"';
$percent_quartoClass = 'style="width:' . $valor_quarto . '%" aria-valuenow="50"aria-valuemin="0"aria-valuemax="100"';


//Estrutura de decisao que controla o valor do atuador dos clientes
  //Restaurante
if ($valor_clientes >= 0 && $valor_clientes < 20) {

  $clientes_badge = 'class="btn btn-success"';
  $clientes_badgeText = "Restaurante OK";
  $clientes_progressBar = 'class="progress-bar bg-success"';
} else {
  if ($valor_clientes >= 20 && $valor_clientes < 40) {
    $clientes_badge = 'class="btn btn-warning"';
    $clientes_badgeText = "Restaurante Estável";
    $clientes_progressBar = 'class="progress-bar bg-warning"';
  } else {
    $clientes_badge = 'class="btn btn-danger"';
    $clientes_badgeText = "Restaurante cheio";
    $clientes_progressBar = 'class="progress-bar bg-danger"';
  }
}

  //Temperatura
if ($valor_temperatura >= 18 && $valor_temperatura <= 21) {
  $temperatura_badge = 'class="btn btn-secondary"';
  $temperatura_badgeText = "Ar condicionado desligado";
  $temperatura_progressBar = 'class="progress-bar bg-secondary"';

} else {
  if ($valor_temperatura < 18) {
    $temperatura_badge = 'class="btn btn-warning"';
    $temperatura_badgeText = "Ar condicionado ligado : Quente";
    $temperatura_progressBar = 'class="progress-bar bg-warning"';

  } else {
    $temperatura_badge = 'class="btn btn-primary"';
    $temperatura_badgeText = "Ar condicionado ligado : Frio";
    $temperatura_progressBar = 'class="progress-bar bg-primary"';
  }
}

  //Quartos
if ($valor_quarto >= 0 && $valor_quarto < 50) {

  $quarto_badge = 'class="btn btn-success"';
  $quarto_badgeText = "Quartos Parcialmente Vazios";
  $quarto_progressBar = 'class="progress-bar bg-success"';

} else {
    if ($valor_quarto >= 50 && $valor_quarto < 100) {
      $quarto_badge = 'class="btn btn-warning"';
      $quarto_badgeText = "Quartos Quase Cheios";
      $quarto_progressBar = 'class="progress-bar bg-warning"';

    } else {
      $quarto_badge = 'class="btn btn-danger"';
      $quarto_badgeText = "Quartos Cheios";
      $quarto_progressBar = 'class="progress-bar bg-danger"';
    }
}
?>

<style>
  @media screen and (max-width: 767px) {
  .home {
    position: relative;
    padding: 30px 50px;

  }
}
</style>

<body>
 
  
  
  <!-- MODAL QUE É ATIVADO QUANDO O BOTAO DE LOGOUT É CLICADO -->
  <div class="modal fade" id="exampleModal" tabindex="1" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <h1 class="modal-title fs-5" id="exampleModalLabel">Logout</h1>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
          Tem a certeza que deseja sair da conta atual?
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancelar</button>
          <a href="logout.php"><button type="button" class="btn btn-primary">Sair</button></a>
        </div>
      </div>
    </div>
  </div>
  <!--FIM DO MODAL -->

  <!--HEADER-->
  <header>
    
    <div style="margin-top: 70px;" class="container">
      <nav>
        <div class="logo">
          <img src="assets/images/estg_h.png" alt="">
        </div>
        <div class="list-darkmode-menu">
          <!--Menu-->
          <ul>
            <li><a href="#">Home</a></li>
            <li><a href="historico.php">Historico</a></li>
            <li><a href="#" data-bs-toggle="modal" data-bs-target="#exampleModal">Logout</a></li>
          </ul>
          <!-- ICON que muda consuante o tema-->
          <label class="mode">
            <input type="checkbox" checked="checked" id="darkModeButton" />
            <i class="fa-solid fa-sun"></i>
            <i class="fa-solid fa-moon"></i>
          </label>
          <!--  botao do Menu que faz parte do mobile e das telas mais pequenas -->
          <button class="hamburger">
            <div class="bar"></div>
          </button>

        </div>
      </nav>
    </div>
  </header>
  <section class="home">

    <div class="container">
      <!--PAINEIS DE INFORMACAO-->
      <!-- painel 1 Sensor-->
      <h1>Bem vindo novamente,<span style="color:#81be41">&nbsp;<?php echo $_SESSION["username"] ?> </span> </h1>
      <br>
      <div class="container mt-0 mb-3">
        <div class="row">
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/temperature-high.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0"><?php echo $nome_temperatura ?></h6> <span>Atualizado às
                      <?php echo $hora_temperatura ?></span>
                  </div>
                </div>
                <div class="badge"> <span>Sensor</span> </div>
              </div>
              <div class="mt-5">
                <h3 class="heading"><?php echo $valor_temperatura ?> Graus </h3>
                <div class="mt-5">
                  <div class="progress">
                    <div <?php echo $temperatura_progressBar ?> role="progressbar" <?php echo $percent_TemperaturaClass ?>> </div>
                  </div>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_temperatura ?>ºC <span class="text2">de 30ºC
                        máximos</span></span> </div>
                </div>
              </div>
            </div>
          </div>
          <!-- PAinel 2 Sensor-->
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/client.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0"><?php echo $nome_clientes ?> (Restaurante)</h6> <span>Atualizado às
                      <?php echo $hora_clientes ?></span>
                  </div>
                </div>
                <div class="badge"> <span>Sensor</span> </div>
              </div>
              <div class="mt-5">
                <h3 class="heading"><?php echo $valor_clientes ?> Clientes</h3>
                <div class="mt-5">
                  <div class="progress">
                    <div <?php echo $clientes_progressBar ?> role="progressbar" <?php echo $percent_clientesClass ?>>
                    </div>
                  </div>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_clientes ?> <span class="text2">de 40
                        máximos</span></span> </div>
                </div>
              </div>
            </div>
          </div>
          <!--Painel 3 sensor  -->
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/bed.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0"><?php echo $nome_quarto ?></h6> <span>Atualizado às
                      <?php echo $hora_quarto ?></span>
                  </div>
                </div>
                <div class="badge"> <span>Sensor</span> </div>
              </div>
              <div class="mt-5">
                <h3 class="heading"> <?php echo $valor_quarto ?> Hóspedes</h3>
                <div class="mt-5">
                  <div class="progress">
                    <div <?php echo $quarto_progressBar ?> role="progressbar" <?php echo $percent_quartoClass ?>>
                    </div>
                  </div>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_quarto ?> <span class="text2">de 100
                        hospedes</span></span> </div>
                </div>
              </div>
            </div>
          </div>
          <!--Painel 1 atuador  -->
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/temperature-high.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0">Estado da <?php echo $nome_temperatura ?></h6> <span>Atualizado às
                      <?php echo $hora_temperatura ?></span>
                  </div>
                </div>
                <div class="badge"> <span style="background-color:#1c583c">Atuador</span> </div>
              </div>
              <div>
                <div class="mt-4">
                  <button type="button" <?php echo $temperatura_badge ?>> <?php echo $temperatura_badgeText ?></button>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_temperatura ?>ºC <span class="text2">de 30ºC
                        máximos</span></span> </div>
                </div>
              </div>
            </div>
          </div>
          <!--Painel 2 atuador  -->
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/client.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0"> Estado dos <?php echo $nome_clientes ?></h6> <span>Atualizado às
                      <?php echo $hora_clientes ?></span>
                  </div>
                </div>
                <div class="badge"> <span style="background-color:#1c583c">Atuador</span> </div>
              </div>
              <div>
                <div class="mt-4">
                  <button type="button" <?php echo $clientes_badge ?>> <?php echo $clientes_badgeText ?></button>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_clientes ?> <span class="text2">de 40
                        clientes máximos</span></span> </div>
                </div>
              </div>
            </div>
          </div>
          <!--Painel 3 atuador  -->
          <div class="col-md-4">
            <div class="card p-3 mb-2">
              <div class="d-flex justify-content-between">
                <div class="d-flex flex-row align-items-center">
                  <div class="icon"> <img src="assets/images/bed.png" style="width:40px"></img> </div>
                  <div class="ms-2 c-details">
                    <h6 class="mb-0"> Estado dos <?php echo $nome_quarto ?></h6> <span>Atualizado às
                      <?php echo $hora_quarto ?></span>
                  </div>
                </div>
                <div class="badge"> <span style="background-color:#1c583c">Atuador</span> </div>
              </div>
              <div>
                <div class="mt-4">
                  <button type="button" <?php echo $quarto_badge ?>> <?php echo $quarto_badgeText ?></button>
                  <div class="mt-3"> <span class="text1"><?php echo $valor_quarto ?> <span class="text2">de 100
                        hospedes</span></span> </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>







    <!--AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA-->
    </div>


  </section>
 
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
    crossorigin="anonymous"></script>
    <script src="assets/js/main.js"></script>
  <script src="assets/js/dashboard.js"></script>

</body>

</html>