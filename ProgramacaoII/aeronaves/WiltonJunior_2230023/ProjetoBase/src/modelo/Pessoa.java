package modelo;

public abstract class Pessoa<Tid> {
    protected String nome;
    protected Tid identificacao;

    public Pessoa(String nome, Tid identificacao) {
        this.nome = nome;
        this.identificacao = identificacao;
    }

    public String getNome() {
        return nome;
    }

    public Tid getIdentificacao() {
        return identificacao;
    }

    @Override
    public String toString() {
        return getClass().getSimpleName() + " " + nome + " " + identificacao;
    }
}
