import modelo.*;

import java.awt.*;

public class Main {
    public static void main(String[] args) {
        CandeeiroMulticor candeeiroMulticor = new CandeeiroMulticor();
        CandeeiroMultiluminosidade candeeiroMultiluminosidade = new CandeeiroMultiluminosidade();

        System.out.println(candeeiroMulticor);

        candeeiroMulticor.ligar();

        System.out.println("==> Após ligar\n" + candeeiroMulticor);

        candeeiroMulticor.setCorAleatoria();

        System.out.println("==> Após definir cor aleatória\n" + candeeiroMulticor);

        System.out.println(candeeiroMultiluminosidade);

        candeeiroMultiluminosidade.ligar();

        System.out.println("==> Após ligar\n" + candeeiroMultiluminosidade);

        candeeiroMultiluminosidade.alterarLuminosidade(-5);

        System.out.println("==> Após decrementar 50% da luminosidade\n" + candeeiroMultiluminosidade);
    }
}
