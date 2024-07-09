package modelo;

public class Helicoptero extends AeronaveComercial implements Combustivel {
    private final GestorCombustivel gestorCombustivel;

    public Helicoptero() {
        gestorCombustivel = new GestorCombustivel();
    }

    public int getCombustivel() {
        return gestorCombustivel.getCombustivel();
    }

    public void abastecer(int quantidade) {
        gestorCombustivel.abastecer(quantidade);
    }

    @Override
    public void voarVertical(int distancia) {
        super.voarVertical(distancia);
        // Para deixar o codigo mais otimizado podemos usar a funcao voarDiagonal e passarmos só a distancia Vertical
        gestorCombustivel.voarDiagonal(distancia, 0);
    }

    @Override
    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        super.voarDiagonal(distanciaVertical, distanciaHorizontal);
        gestorCombustivel.voarDiagonal(distanciaVertical, distanciaHorizontal);
    }

    @Override
    public String toString() {
        return super.toString() + "combustível: " + gestorCombustivel.getCombustivel() + "l\n";
    }
}
