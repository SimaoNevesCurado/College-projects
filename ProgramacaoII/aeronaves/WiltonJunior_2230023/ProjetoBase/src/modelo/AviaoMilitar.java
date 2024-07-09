package modelo;

public class AviaoMilitar extends Aviao<Militar> implements Combustivel {
    private final GestorCombustivel gestorCombustivel;

    public AviaoMilitar() {
        this.gestorCombustivel = new GestorCombustivel();
    }

    @Override
    public int getCombustivel() {
        return gestorCombustivel.getCombustivel();
    }

    @Override
    public void abastecer(int quantidade) {
        gestorCombustivel.abastecer(quantidade);
    }

    public void voarDiagonal(int distanciaVertical, int distanciaHorizontal) {
        super.voarDiagonal(distanciaVertical, distanciaHorizontal);
        gestorCombustivel.voarDiagonal(distanciaVertical, distanciaHorizontal);
    }

    @Override
    public String toString() {
        return super.toString() + "combustível: " + gestorCombustivel.getCombustivel() + "l\n";
    }

}
