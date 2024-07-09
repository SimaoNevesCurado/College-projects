package pt.ipleiria.estg.dei.ei.p2.testepratico.modelo;

import java.util.LinkedList;

public abstract class Piscina<TUtente extends UtentePiscina> {
    protected int capacidadeMaximaAgua;
    protected int quantidadeAguaAtual;
    protected LinkedList<TUtente> utentes;

    public Piscina(int capacidadeMaximaAgua) {
        this.capacidadeMaximaAgua = capacidadeMaximaAgua;
        quantidadeAguaAtual = 0;
        utentes = new LinkedList<>();
    }

    public int getCapacidadeMaximaAgua() {
        return capacidadeMaximaAgua;
    }

    public int getQuantidadeAguaAtual() {
        return quantidadeAguaAtual;
    }

    public void encher() {
        if (quantidadeAguaAtual < capacidadeMaximaAgua) {
            quantidadeAguaAtual = capacidadeMaximaAgua;
        }
    }

    public void esvaziar() {
        quantidadeAguaAtual = 0;
    }

    public void adicionarAgua(int litros) {
        if (litros < 0 || quantidadeAguaAtual + litros > capacidadeMaximaAgua) {
            return;
        }
        this.quantidadeAguaAtual += litros;
    }

    public void removerAgua(int litros) {
        if (litros < 0 || quantidadeAguaAtual - litros < 0) {
            this.quantidadeAguaAtual = 0;
            return;
        }
        this.quantidadeAguaAtual -= litros;
    }

    public LinkedList<TUtente> getPessoas() {
        return new LinkedList<>(utentes);
    }

    public void adicionar(TUtente utente){
        if(utente == null || utentes.contains(utente)){
            return;
        }
        utentes.add(utente);
    }

    public void remover(TUtente utente) {
        utentes.remove(utente);
    }
}
