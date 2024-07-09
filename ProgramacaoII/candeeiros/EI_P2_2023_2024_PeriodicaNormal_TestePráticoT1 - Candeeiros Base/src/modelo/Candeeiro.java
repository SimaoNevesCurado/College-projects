package modelo;

import java.util.LinkedList;

public abstract class Candeeiro<TLed extends Led>{
    protected LinkedList<TLed> leds;

    public Candeeiro() {
        leds = new LinkedList<>();
    }

    public void ligar() {
        for (TLed led : leds) {
            if (!led.isLigado()) {
                led.inverterEstado();
            }
        }
    }

    public void desligar() {
        for (TLed led : leds) {
            if (led.isLigado()) {
                led.inverterEstado();
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder(getClass().getSimpleName() + ":\n");
        for (TLed led : leds) {
            stringBuilder.append(led).append("\n");
        }
        return stringBuilder.toString();
    }
}
