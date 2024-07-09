package modelo;

import java.awt.*;

public class LedCorVariavel extends Led implements Cor{
    private GestorCor gestorCor;
    public LedCorVariavel(Color cor, int luminosidadeMaxima) {
        super(luminosidadeMaxima);
        this.gestorCor = new GestorCor(cor);
    }

    public String getCor() {
        return gestorCor.getCor();
    }

    public void setCor(Color cor) {
        gestorCor.setCor(cor);
    }

    @Override
    public String toString() {
        return super.toString() + gestorCor.getCor();
    }
}
