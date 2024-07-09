package modelo;

import java.util.LinkedList;

public abstract class AeronaveComercial extends Aviao<Pessoa<?>> {

    public AeronaveComercial() {
    }

    public void voarVertical(int distancia) {
        altitude += distancia;
    }
}
