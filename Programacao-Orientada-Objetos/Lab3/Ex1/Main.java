package Lab3.Ex1;

public class Main {
    public static void main(String[] args) {
        Compositor comp1 = new Compositor("Tom Jobim", "Brasileira");
        Compositor comp2 = new Compositor("Beethoven", "Alemã");

        Musica musica1 = new Musica("Garota de Ipanema", 1962, "Bossa Nova", comp1);
        Musica musica2 = new Musica("Sinfonia nº 5", 1808, "Clássica", comp2);

        System.out.println(musica1);
        System.out.println();
        System.out.println(musica2);
    }
}
