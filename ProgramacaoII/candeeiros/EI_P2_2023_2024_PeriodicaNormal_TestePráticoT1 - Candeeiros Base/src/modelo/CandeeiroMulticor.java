package modelo;

import java.awt.*;
import java.util.LinkedList;
import java.util.Random;

public class CandeeiroMulticor extends Candeeiro<LedCorVariavel>{
    public CandeeiroMulticor() {
        super();
        leds.add(new LedCorVariavel(Color.WHITE, 50));
    }

    public void setCorAleatoria() {
        Random random = new Random();
        Color corAleatoria = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));
        for (LedCorVariavel led : leds) {
            led.setCor(corAleatoria);
        }
    }


}
