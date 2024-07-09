package pt.ipleiria.estg.dei.ei.p2.testepratico.modelo;

import java.util.LinkedList;

public abstract class PiscinaAnimais<TUtente extends UtentePiscina> extends Piscina<TUtente>{

    public PiscinaAnimais(int capacidadeMaximaAgua) {
        super(capacidadeMaximaAgua);
    }

    public void adicionarTratamento(int valor) {
        quantidadeAguaAtual += valor;
        if (quantidadeAguaAtual > capacidadeMaximaAgua) {
            quantidadeAguaAtual = capacidadeMaximaAgua;
        }
    }
}
