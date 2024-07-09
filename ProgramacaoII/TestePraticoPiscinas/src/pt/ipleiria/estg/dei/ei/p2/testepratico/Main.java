package pt.ipleiria.estg.dei.ei.p2.testepratico;

import pt.ipleiria.estg.dei.ei.p2.testepratico.modelo.GestorInstanciaFerias;
import pt.ipleiria.estg.dei.ei.p2.testepratico.modelo.Piscina;

public class Main {
    public Main() {
        for (Piscina piscina : GestorInstanciaFerias.INSTANCIA.getPiscinas()) {
            System.out.println(piscina);
        }

    }

    public static void main(String[] args) {
        new Main();
    }
}
