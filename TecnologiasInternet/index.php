<!DOCTYPE html>
<html lang="pt">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/x-icon" href="assets/images/estg_h.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css">
    <link rel="stylesheet" href="assets/css/auth-page.css">
    <link rel="stylesheet" href="assets/css/main.css">
    <title>Projeto TI</title>
</head>

<body>
    <header>
        <div class="container">
            <nav>
                <div class="logo">
                    <img src="assets/images/estg_h.png" alt="">
                </div>
                <div class="list-darkmode-menu">

                    <label class="mode">
                        <input type="checkbox" checked="checked" id="darkModeButton" />
                        <i class="fa-solid fa-sun"></i>
                        <i class="fa-solid fa-moon"></i>
                    </label>
            
                </div>
            </nav>
        </div>
    </header>

    <section class="home">
        <div class="container">
            <div class="home-info">
                <div class="left">

                    <h1>Seja Bem Vindo!</h1>
                    <h4>Trabalho de <span class="multiple"></span></h4>
                    
                </div>
                
                <div class="right">
                    <div class="profile">
                        <div class="container">
                            <div class="row justify-content-center">    
                                <form method="POST" class="TIform" action="login.php"> 
                                    <div class="mb-3">
                                        <label for="username" class="form-label">Username</label>
                                        <input  type="text" class="form-control" id="username" placeholder="Username" name="username" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="password" class="form-label">Password</label>
                                        <input type="password" class="form-control" id="password" placeholder="Password" name="password" required>
                                    </div>
                                    <button type="submit" class="btn btn-success" style="background-color:#81be41">Entrar</button>
                                    </div> 
                                    </form>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>

    </section>
    
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
    <script src="https://unpkg.com/typed.js@2.1.0/dist/typed.umd.js"></script>
    <script src="assets/js/main.js"></script>
    <script src="assets/js/index.js"></script>
</body>

</html>