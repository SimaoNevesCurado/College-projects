package modelo;

import java.util.LinkedList;

public class AviaoMilitar {
    private int altitude;
    private int distancia;
    private int combustivel;
    private LinkedList<Militar> militares;

    public AviaoMilitar() {
        altitude = 0;
        distancia = 0;
        combustivel = 0;
        militares = new LinkedList<>();
    }

    public int getAltitude() {
        return altitude;
    }

    public int getDistancia() {
        return distancia;
    }

    public int getCombustivel() {
        return combustivel;
    }

    public LinkedList<Militar> getMilitares() {
        return new LinkedList<>(militares);
    }

    public void adicionar(Militar militar) {
        if (militar == null || militares.contains(militar)) {
            return;
        }
        militares.add(militar);
    }

    public void remover(Militar militar) {
        militares.remove(militar);
    }

    public void abastecer(int quantidade) {
        combustivel += quantidade;
    }

    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        altitude += distanciaVertical;
        distancia += distanciaHorizontal;
        combustivel -= distanciaVertical + distanciaHorizontal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(getClass().getSimpleName()).append("\n");
        for (Militar militar : militares) {
            sb.append(militar).append("\n");
        }
        sb.append("altitude: ").append(altitude).append("m\n");
        sb.append("distância: ").append(distancia).append("m\n");
        sb.append("combustível: ").append(combustivel).append("l\n");
        return sb.toString();
    }

}
