package modelo;

public class GestorCombustivel {
    int combustivel;

    public GestorCombustivel() {
    }

    public int getCombustivel() {
        return combustivel;
    }

    public void abastecer(int quantidade) {
        combustivel += quantidade;
    }

    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        combustivel -= (distanciaVertical + distanciaHorizontal);
    }
}