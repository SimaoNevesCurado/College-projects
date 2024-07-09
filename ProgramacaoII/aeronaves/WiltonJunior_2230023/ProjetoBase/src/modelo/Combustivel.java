package modelo;

public interface Combustivel {
    int getCombustivel();

    void abastecer(int quantidade);

    void voarDiagonal(int distanciaVertical, int distanciaHorizontal);
}
