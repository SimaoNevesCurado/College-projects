<!DOCTYPE html>
<html lang="pt">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="icon" type="image/x-icon" href="assets/images/estg_h.png">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/boxicons@latest/css/boxicons.min.css">
  <link rel="stylesheet" href="assets/css/main.css">
  <link rel="stylesheet" href="assets/css/dashboard-page.css">
  <link rel="stylesheet" href="assets/css/historico-page.css">
  <title>Historico</title>
</head>

<?php
    session_start();
    if(!isset($_SESSION['username'])){ 
      header("refresh:2;url=index.php"); 
      die("Acesso restrito");
    }
?>

<body>
  <!--Informação para fazer logout (se desejamos mesmo sair ou não)-->
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
            <li><a href="dashboard.php">Home</a></li>
            <li><a href="#">Historico</a></li>
            <li><a href="#" data-bs-toggle="modal" data-bs-target="#exampleModal">Logout</a></li>
          </ul>
          <!-- ICON que muda consoante o tema-->
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

    <div class="container mt-1 mb-3" >
      <!--PAINEIS DE INFORMACAO-->
      <!-- painel 1 Sensor-->
      <div class="container">
        <div class="row">
          <div class="table-buttons">
            <div class="col-md-4">
              <div class="card p-3 mb-2">
                <div class="d-flex justify-content-between">
                  <div class="d-flex flex-row align-items-center">
                    <div class="icon"> <img src="assets/images/temperature-high.png" style="width:40px"></img> </div>
                    <h3 class="heading"><a href="#" onclick="mostrarTabela('tabelaTemperatura')">&nbsp;Temperatura</a></h3>
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
                    <h3 class="heading"><a href="#" onclick="mostrarTabela('tabelaClientes')">&nbsp;Clientes</a></h3>
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
                    <h3 class="heading"><a href="#" onclick="mostrarTabela('tabelaQuarto')">&nbsp;Quartos</a></h3>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
        <br>
        <!--TABELAS SENSORES E ATUADORES-->
        <!--Tabela sensor 1-->
        <table id="tabelaTemperatura" class="table table-striped" style="height: 100% !important;">
          <thead>
            <tr>
              <th scope="col">Histórico</th>
              <th scope="col">Hora e Valor do Sensor</th>
              <th scope="col">Estado do Atuador</th>
            </tr>
          </thead>
          <tbody>
            <?php
            //Quantidade de logs
            $numero_historico=1;

            //Variáveis para contar as quantidades de logs no ficheiro
            $ficheiro_temperatura_sensor = file('api/files/temperatura/log.txt');
            $contador_sensor = count($ficheiro_temperatura_sensor);


            //Ciclo for para adicionar uma linha de cada vez que se adiciona um log
            for($numero_historico=1; $numero_historico<=$contador_sensor; $numero_historico++){
              if($numero_historico>0 && $numero_historico<=$contador_sensor){
                $log_temperatura_sensor=$ficheiro_temperatura_sensor[$numero_historico-1];  //-1, porque o índice inicia a 0
              }
              else{
                $log_temperatura_sensor="Sem logs";
              }

              //Estado do atuadores
              $valor_temperatura=explode(":",$log_temperatura_sensor);
              if($numero_historico>0 && $numero_historico<=$contador_sensor){
                if($valor_temperatura[3]<18){
                  $log_temperatura_atuador="Ar condicionado ligado : Quente";
                }
                else{
                  if($valor_temperatura[3]>=18 && $valor_temperatura[3]<=21){
                    $log_temperatura_atuador="Ar condicionado desligado";
                  }
                  else{
                    $log_temperatura_atuador="Ar condicionado ligado : Frio";
                  }
                }
              }
              else{
                $log_temperatura_atuador="Sem logs";
              }

              echo "<tr>";
              echo "<td>{$numero_historico}</td>";
              echo "<td>{$log_temperatura_sensor}</td>";
              echo "<td>{$log_temperatura_atuador}</td>";
              echo "</tr>";
            }
            ?>
          </tbody>
        </table>
        <!--Tabela sensor 2-->        
       <table id="tabelaClientes" class="table table-striped">
          <thead>
            <tr>
              <th scope="col">Histórico</th>
              <th scope="col">Hora e Valor do Sensor</th>
              <th scope="col">Estado do Atuador</th>
            </tr>
          </thead>
          <tbody>
          <?php

            //Quantidade de logs
            $numero_historico=1;

            //Variáveis para contar as quantidades de logs no ficheiro 
            $ficheiro_clientes_sensor = file('api/files/clientes/log.txt');
            $contador_sensor = count($ficheiro_clientes_sensor);

            //Ciclo for para adicionar uma linha de cada vez que se adiciona um log
            for($numero_historico=1; $numero_historico<=$contador_sensor; $numero_historico++){
              if($numero_historico>0 && $numero_historico<=$contador_sensor){
                $log_clientes_sensor=$ficheiro_clientes_sensor[$numero_historico-1];
              }
              else{
                $log_clientes_sensor="Sem logs";
              }

              //Estado do atuador
              $valor_clientes=explode(":",$log_clientes_sensor);
              if($numero_historico>0 && $numero_historico<=$contador_sensor){
                if($valor_clientes[3]>=0 && $valor_clientes[3]<20){
                  $log_clientes_atuador="Restaurante OK";
                }
                else{
                  if($valor_clientes[3]>=20 && $valor_clientes[3]<40){
                    $log_clientes_atuador="Restaurante Estável";
                  }
                  else{
                    $log_clientes_atuador="Restaurante Cheio";
                  }
                }
              }
              else{
                $log_clientes_atuador="Sem logs";
              }

              echo "<tr>";
              echo "<td>{$numero_historico}</td>";
              echo "<td>{$log_clientes_sensor}</td>";
              echo "<td>{$log_clientes_atuador}</td>";
              echo "</tr>";
            }
            ?>
          </tbody>
        </table>
        <!--Tabela sensor 3-->
        <table id="tabelaQuarto" class="table table-striped">
          <thead>
            <tr>
              <th scope="col">Histórico</th>
              <th scope="col">Hora e Valor do Sensor</th>
              <th scope="col">Estado do Atuador</th>
            </tr>
          </thead>
          <tbody>
          <?php

          //Quantidade de logs
          $numero_historico=1;

          //Variáveis para contar as quantidades de logs em cada ficheiro (Sensor e Atuador)
          $ficheiro_quarto_sensor = file('api/files/quartos/log.txt');
          $contador_sensor = count($ficheiro_quarto_sensor);

          //Ciclo for para adicionar uma linha de cada vez que se adiciona um log
          for($numero_historico=1; $numero_historico<=$contador_sensor; $numero_historico++){
            if($numero_historico>0 && $numero_historico<=$contador_sensor){
              $log_quarto_sensor=$ficheiro_quarto_sensor[$numero_historico-1];
            }
            else{
              $log_quarto_sensor="Sem logs";
            }

            //Estado do atuador
            $valor_quarto=explode(":",$log_quarto_sensor);
            if($numero_historico>0 && $numero_historico<=$contador_sensor){
              if($valor_quarto[3]>=0 && $valor_quarto[3]<50){
                $log_quarto_atuador="Quartos Parcialmente Vazios";
              }
              else{
                if($valor_quarto[3]>=50 && $valor_quarto[3]<100){
                  $log_quarto_atuador="Quartos quase cheios";
                }
                else{
                  $log_quarto_atuador="Quartos cheios";
                }
              }
            }
            else{
              $log_quarto_atuador="Sem logs";
            }

            echo "<tr>";
            echo "<td>{$numero_historico}</td>";
            echo "<td>{$log_quarto_sensor}</td>";
            echo "<td>{$log_quarto_atuador}</td>";
            echo "</tr>";
          }
          ?>
          </tbody>
        </table>
      </div>
    </div>
  </section>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
    crossorigin="anonymous"></script>


   <!--Para poder mostrar as tabelas específicas -->
  <script>
function mostrarTabela(idTabela) {
    // Seleciona todas as tabelas que existem
  var tabelas = document.querySelectorAll('table');
    // Oculta todas as tabelas
  tabelas.forEach(function(tabela) {
    tabela.style.display = 'none'; // Define o estilo de exibição como 'none' para ocultar a tabela
  });
    // Exibe a tabela específica com o ID fornecido
  document.getElementById(idTabela).style.display = 'table'; // Define o estilo de exibição como 'table' para exibir a tabela
}
</script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
    crossorigin="anonymous"></script>
    <script src="assets/js/main.js"></script>
    <script src="assets/js/dashboard.js"></script>
</body>

</html>