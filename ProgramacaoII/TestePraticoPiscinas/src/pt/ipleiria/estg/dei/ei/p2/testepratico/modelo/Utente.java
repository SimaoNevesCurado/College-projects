package pt.ipleiria.estg.dei.ei.p2.testepratico.modelo;

public class Utente implements UtentePiscina {
    protected String nome;

    public Utente(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }
}
