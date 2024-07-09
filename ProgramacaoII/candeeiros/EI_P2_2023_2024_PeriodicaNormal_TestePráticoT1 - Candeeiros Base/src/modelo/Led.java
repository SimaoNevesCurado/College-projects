package modelo;

public abstract class Led {
    protected int luminosidadeMaxima;
    protected int luminosidade;

    public Led(int luminosidadeMaxima) {
        this.luminosidadeMaxima = luminosidadeMaxima;
        luminosidade = 0;
    }

    public int getLuminosidadeMaxima() {
        return luminosidadeMaxima;
    }

    public int getLuminosidade() {
        return luminosidade;
    }

    public boolean isLigado() {
        return luminosidade > 0;
    }

    public void inverterEstado() {
        luminosidade = luminosidade > 0 ? 0 : luminosidadeMaxima;
    }

    @Override
    public String toString() {
        return getClass().getSimpleName() + (isLigado() ? " ligado " : " desligado ") +
                +getLuminosidade() + " de " + luminosidadeMaxima + " lumens ";
    }
}
