package modelo;

import java.util.LinkedList;

public abstract class Aviao<TPessoa extends Pessoa<?>> {
    protected int altitude;
    protected int distancia;
    protected LinkedList<TPessoa> pessoas;

    public Aviao() {
        altitude = 0;
        distancia = 0;
        pessoas = new LinkedList<>();
    }

    public int getAltitude() {
        return altitude;
    }

    public int getDistancia() {
        return distancia;
    }

    public LinkedList<TPessoa> getTPessoas() {
        return new LinkedList<>(pessoas);
    }

    public void adicionar(TPessoa pessoa) {
        if (pessoa == null || pessoas.contains(pessoa)) {
            return;
        }
        pessoas.add(pessoa);
    }

    public void remover(TPessoa pessoa) {
        pessoas.remove(pessoa);
    }

    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        altitude += distanciaVertical;
        distancia += distanciaHorizontal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(getClass().getSimpleName()).append("\n");
        for (TPessoa pessoa : pessoas) {
            sb.append(pessoa).append("\n");
        }
        sb.append("altitude: ").append(altitude).append("m\n");
        sb.append("distância: ").append(distancia).append("m\n");
        return sb.toString();
    }
}
