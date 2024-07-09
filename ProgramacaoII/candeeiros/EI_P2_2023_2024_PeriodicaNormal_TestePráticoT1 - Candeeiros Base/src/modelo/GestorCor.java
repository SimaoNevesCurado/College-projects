package modelo;

import java.awt.*;

public class GestorCor {
    protected Color cor;

    public GestorCor(Color cor){
        this.cor = cor;
    }

    public String getCor() {
        return "RGB(" + cor.getRed() + "," + cor.getGreen() + "," + cor.getBlue() + ")";
    }

    public void setCor(Color cor) {
        this.cor = cor;
    }
}
