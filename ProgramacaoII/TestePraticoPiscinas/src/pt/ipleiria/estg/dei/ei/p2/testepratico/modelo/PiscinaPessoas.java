package pt.ipleiria.estg.dei.ei.p2.testepratico.modelo;

import java.util.LinkedList;

public class PiscinaPessoas extends Piscina<Pessoa> implements PiscinaComTemperatura{
    private final GestorTemperatura gestorTemperatura;

    public PiscinaPessoas(int capacidadeMaximaAgua, float temperatura) {
        super(capacidadeMaximaAgua);
        gestorTemperatura = new GestorTemperatura(temperatura);
    }

    @Override
    public float getTemperatura() {
        return gestorTemperatura.getTemperatura();
    }

    @Override
    public void setTemperatura(float temperatura) {
        gestorTemperatura.setTemperatura(temperatura);
    }
}
