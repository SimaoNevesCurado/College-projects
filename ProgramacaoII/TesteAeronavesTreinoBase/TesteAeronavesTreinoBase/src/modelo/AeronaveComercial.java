package modelo;

import java.util.LinkedList;

public abstract class AeronaveComercial {
    protected int altitude;
    protected int distancia;
    protected LinkedList<Pessoa> pessoas;

    public AeronaveComercial() {
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

    public LinkedList<Pessoa> getPessoas() {
        return new LinkedList<>(pessoas);
    }

    public void adicionar(Pessoa pessoa) {
        if (pessoa == null || pessoas.contains(pessoa)) {
            return;
        }
        pessoas.add(pessoa);
    }

    public void remover(Pessoa pessoa) {
        pessoas.remove(pessoa);
    }

    public void voarVertical(int distancia) {
        altitude += distancia;
    }

    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        altitude += distanciaVertical;
        distancia += distanciaHorizontal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(getClass().getSimpleName()).append("\n");
        for (Pessoa pessoa : pessoas) {
            sb.append(pessoa).append("\n");
        }
        sb.append("altitude: ").append(altitude).append("m\n");
        sb.append("distância: ").append(distancia).append("m\n");
        return sb.toString();
    }
}
