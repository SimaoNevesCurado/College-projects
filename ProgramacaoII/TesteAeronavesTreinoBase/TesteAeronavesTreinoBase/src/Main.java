import modelo.*;

public class Main {
    public static void main(String[] args) {
        Civil civil1 = new Civil("José", "FTS768678");
        Civil civil2 = new Civil("Maria", "KHI267920");
        Militar militar1 = new Militar("Joaquim", Patente.CORONEL);
        Militar militar2 = new Militar("Joana", Patente.MARECHAL);

        Balao balao = new Balao();
        balao.adicionar(civil1);
        balao.adicionar(militar1);
        balao.voarVertical(100);
        balao.voarDiagonal(50, 1000);
        System.out.println(balao);

        Helicoptero helicoptero = new Helicoptero();
        helicoptero.abastecer(2500);
        helicoptero.adicionar(civil2);
        helicoptero.adicionar(militar2);
        helicoptero.voarVertical(100);
        helicoptero.voarDiagonal(300, 1500);
        System.out.println(helicoptero);


    }
}