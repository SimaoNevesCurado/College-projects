package modelo;

public class Militar extends Pessoa {
    private Patente patente;

    public Militar(String nome, Patente patente) {
        super(nome);
        this.patente = patente;
    }

    public Patente getPatente() {
        return patente;
    }

    @Override
    public String toString() {
        return super.toString() + " " + patente;
    }

}
