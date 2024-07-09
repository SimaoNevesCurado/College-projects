package modelo;

public class Civil extends Pessoa {
    private String numeroPassaporte;

    public Civil(String nome, String numeroPassaporte) {
        super(nome);
        this.numeroPassaporte = numeroPassaporte;
    }

    public String getNumeroPassaporte() {
        return numeroPassaporte;
    }

    @Override
    public String toString() {
        return super.toString() + " " + numeroPassaporte;
    }
}
