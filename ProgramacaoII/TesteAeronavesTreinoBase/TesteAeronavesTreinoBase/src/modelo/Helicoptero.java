package modelo;

public class Helicoptero extends AeronaveComercial {
    private int combustivel;

    public Helicoptero() {
        combustivel = 0;
    }

    public int getCombustivel() {
        return combustivel;
    }

    public void abastecer(int quantidade) {
        combustivel += quantidade;
    }

    @Override
    public void voarVertical(int distancia) {
        super.voarVertical(distancia);
        combustivel -= distancia;
    }

    @Override
    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        super.voarDiagonal(distanciaVertical, distanciaHorizontal);
        combustivel -= (distanciaVertical + distanciaHorizontal);
    }

    @Override
    public String toString() {
        return super.toString() + "combustível: " + combustivel + "l\n";
    }
}
