package modelo;

public abstract class LedMultiluminosidade extends Led {

    public LedMultiluminosidade(int luminosidadeMaxima) {
        super(luminosidadeMaxima);
    }

    public void incrementarLuminosidade() {
        luminosidade += 0.1 * luminosidadeMaxima;
        if (luminosidade > luminosidadeMaxima) {
            luminosidade = luminosidadeMaxima;
        }
    }

    public void decrementarLuminosidade() {
        luminosidade -= 0.1 * luminosidadeMaxima;
        if (luminosidade < 0) {
            luminosidade = 0;
        }
    }


}
