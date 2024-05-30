import modelo.GestorSemanaAulas;
import modelo.Aula;

public class    Main {

    public static void main(String[] args) {
        System.out.println();
        for (Aula aula : GestorSemanaAulas.INSTANCIA.getAulas()) {
            System.out.println(aula);
            System.out.println("\n----------------------------------------\n");
        }
    }
}
