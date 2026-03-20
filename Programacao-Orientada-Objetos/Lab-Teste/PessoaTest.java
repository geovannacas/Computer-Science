import static org.junit.Assert.*;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class PessoaTest {

    @BeforeClass
    public static void inicializaClass() {
        System.out.println("iniciou série de teste");
    }

    @AfterClass
    public static void finalizaClass() {
        System.out.println("Finalizou série de teste");
    }

    @Test
    public void testFaixa1() {
        Pessoa p = new Pessoa("joão", 1500.00, 0, 20);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("maria", 1500.00, 1, 50);
        assertEquals(0, p.calculaImposto(), 0);
        System.out.println("Passou Teste 1 - primeira faixa");
    }

    @Test
    public void testFaixa2() {
        Pessoa p = new Pessoa("joão", 2000.00, 0, 60);
        assertEquals(15.91, p.calculaImposto(), 0.1);

        p = new Pessoa("joão", 2000.00, 2, 50);
        assertEquals(0, p.calculaImposto(), 0);
        System.out.println("Passou Teste 2 - segunda faixa");
    }

    @Test
    public void testFaixa3() {
        Pessoa p = new Pessoa("paulo", 3500.00, 0, 20);
        assertEquals(189.97, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 3500.00, 1, 20);
        assertEquals(10.26, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 3500.00, 2, 40);
        assertEquals(0, p.calculaImposto(), 0);
        System.out.println("Passou Teste 3 - terceira faixa");
    }

    @Test
    public void testFaixa4() {
        Pessoa p = new Pessoa("paulo", 4400.00, 0, 40);
        assertEquals(387.04, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 4400.00, 1, 30);
        assertEquals(207.33, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 4400.00, 2, 40);
        assertEquals(27.62, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 4400.00, 3, 20);
        assertEquals(0, p.calculaImposto(), 0);
        System.out.println("Passou Teste 4 - quarta faixa");
    }

    @Test
    public void testFaixa5() {
        Pessoa p = new Pessoa("jose", 7000.00, 0, 50);
        assertEquals(1098.85, p.calculaImposto(), 0.1);

        p = new Pessoa("jose", 7000.00, 2, 30);
        assertEquals(739.43, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 7000.00, 6, 40);
        assertEquals(20.59, p.calculaImposto(), 0.1);

        p = new Pessoa("paulo", 7000.00, 7, 20);
        assertEquals(0, p.calculaImposto(), 0);
        System.out.println("Passou Teste 5 - quinta faixa");
    }

    /**
     * Testa a regra de isenção para pessoas com 65 anos ou mais, sem dependentes,
     * em todas as faixas salariais. 
     * O imposto deve ser sempre zero. 
     */
    @Test
    public void testIdosoSemDependentes() {
        // Faixa 1
        Pessoa p1 = new Pessoa("ana", 1500.00, 0, 65);
        assertEquals(0, p1.calculaImposto(), 0);

        // Faixa 2
        Pessoa p2 = new Pessoa("carlos", 2000.00, 0, 70);
        assertEquals(0, p2.calculaImposto(), 0);

        // Faixa 3
        Pessoa p3 = new Pessoa("marta", 3500.00, 0, 80);
        assertEquals(0, p3.calculaImposto(), 0);

        // Faixa 4
        Pessoa p4 = new Pessoa("hugo", 4400.00, 0, 66);
        assertEquals(0, p4.calculaImposto(), 0);

        // Faixa 5
        Pessoa p5 = new Pessoa("sonia", 7000.00, 0, 90);
        assertEquals(0, p5.calculaImposto(), 0);
        System.out.println("Passou Teste 6 - Idosos sem dependentes");
    }

    /**
     * Testa a regra de isenção para pessoas com 65 anos ou mais, com 2 dependentes,
     * em todas as faixas salariais. 
     * O imposto deve ser sempre zero. 
     */
    @Test
    public void testIdosoComDoisDependentes() {
        // Faixa 1
        Pessoa p1 = new Pessoa("ana", 1500.00, 2, 65);
        assertEquals(0, p1.calculaImposto(), 0);

        // Faixa 2
        Pessoa p2 = new Pessoa("carlos", 2000.00, 2, 70);
        assertEquals(0, p2.calculaImposto(), 0);

        // Faixa 3
        Pessoa p3 = new Pessoa("marta", 3500.00, 2, 80);
        assertEquals(0, p3.calculaImposto(), 0);

        // Faixa 4
        Pessoa p4 = new Pessoa("hugo", 4400.00, 2, 66);
        assertEquals(0, p4.calculaImposto(), 0);

        // Faixa 5
        Pessoa p5 = new Pessoa("sonia", 7000.00, 2, 90);
        assertEquals(0, p5.calculaImposto(), 0);
        System.out.println("Passou Teste 7 - Idosos com 2 dependentes");
    }
}