package pt.ipleiria.estg.dei.ei.p2.testepratico.modelo;


import java.util.LinkedList;

public enum GestorInstanciaFerias {
    INSTANCIA;

    private LinkedList<Piscina> piscinas;
    private LinkedList<Cao> caes;
    private LinkedList<Gato> gatos;
    private LinkedList<Pessoa> pessoas;

    GestorInstanciaFerias() {
        caes = new LinkedList<>();
        gatos = new LinkedList<>();
        pessoas = new LinkedList<>();

        caes.add(new Cao("Boby"));
        caes.add(new Cao("Pintarola"));
        caes.add(new Cao("Salsicha"));
        gatos.add(new Gato("Tareco"));
        gatos.add(new Gato("Garfield"));
        gatos.add(new Gato("Riscas"));
        gatos.add(new Gato("Tom"));
        pessoas.add(new Pessoa("Carlos"));
        pessoas.add(new Pessoa("Maria"));
        pessoas.add(new Pessoa("Joaquim"));
        pessoas.add(new Pessoa("Rui"));
        pessoas.add(new Pessoa("Edgar"));
        pessoas.add(new Pessoa("Ana"));
        pessoas.add(new Pessoa("Bela"));
        pessoas.add(new Pessoa("Marco"));
        pessoas.add(new Pessoa("Fernando"));


        piscinas = new LinkedList<>();

        PiscinaCaes piscinaCaes = new PiscinaCaes(5000);
        piscinaCaes.adicionarAgua(4700);
        piscinaCaes.adicionar(pessoas.get(0));
        piscinaCaes.adicionar(pessoas.get(1));
        piscinaCaes.adicionar(pessoas.get(2));
        piscinaCaes.adicionar(caes.get(0));
        piscinaCaes.adicionar(caes.get(1));
        piscinas.add(piscinaCaes);

        PiscinaGatos piscinaGatos = new PiscinaGatos(4000, 25);
        piscinaGatos.adicionarAgua(3650);
        piscinaGatos.adicionar(pessoas.get(0));
        piscinaGatos.adicionar(pessoas.get(1));
        piscinaGatos.adicionar(pessoas.get(2));
        piscinaGatos.adicionar(gatos.get(0));
        piscinaGatos.adicionar(gatos.get(1));
        piscinaGatos.adicionar(gatos.get(2));
        piscinaGatos.adicionar(gatos.get(3));
        piscinas.add(piscinaGatos);

        PiscinaPessoas piscinaPessoas = new PiscinaPessoas(10000, 30);
        piscinaGatos.adicionarAgua(6000);
        piscinaGatos.adicionar(pessoas.get(0));
        piscinaGatos.adicionar(pessoas.get(1));
        piscinaGatos.adicionar(pessoas.get(2));
        piscinaGatos.adicionar(pessoas.get(3));
        piscinas.add(piscinaPessoas);

    }

    public Piscina getPiscina(int indice) {
        return piscinas.get(indice);
    }

    public LinkedList<Piscina> getPiscinas() {
        return piscinas;
    }
}
