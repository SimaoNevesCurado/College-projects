package modelo;

import java.awt.*;
import java.util.LinkedList;

public class CandeeiroMultiluminosidade extends Candeeiro<LedMultiluminosidade> {

    public CandeeiroMultiluminosidade() {
        super();
        leds.add(new LedLuminosidadeVariavel(100));
        leds.add(new LedLuminosidadeECorVariavel(Color.YELLOW, 120));
    }
    public void alterarLuminosidade(int numeroVezes) {
        if (numeroVezes < 0) {
            for (int i = 0; i < -numeroVezes; i++) {
                for (LedMultiluminosidade led : leds) {
                    led.decrementarLuminosidade();
                }
            }
        } else {
            for (int i = 0; i < numeroVezes; i++) {
                for (LedMultiluminosidade led : leds) {
                    led.incrementarLuminosidade();
                }
            }
        }
    }

}
