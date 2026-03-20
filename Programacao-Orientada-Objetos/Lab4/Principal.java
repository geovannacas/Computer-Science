import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		ArrayList<ProgramaTV> programas = new ArrayList<>();

		ProgramaTV p = new ProgramaTV("O outro lado do paraíso", "Novela");
		p.setDiretor(new Pessoa("Diretor 1", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 1", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 2", "Brasileiro"));
		programas.add(p);

		p = new ProgramaTV("Orgulho e Paixão", "Novela");
		p.setDiretor(new Pessoa("Diretor 2", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 3", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 4", "Brasileiro"));
		programas.add(p);

		p = new ProgramaTV("Marley e eu", "Filme");
		p.setDiretor(new Pessoa("Diretor 3", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 5", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 6", "Brasileiro"));
		programas.add(p);

		p = new ProgramaTV("Show Ivete Sangalo", "Show");
		p.setDiretor(new Pessoa("Diretor 4", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 7", "Brasileiro"));
		p.setArtistas(new Pessoa("Artista 8", "Brasileiro"));
		programas.add(p);

		// Séries adicionadas
		Serie s1 = new Serie("Stranger Things", "Série", 4, 34);
		s1.setDiretor(new Pessoa("Irmãos Duffer", "Americano"));
		s1.setArtistas(new Pessoa("Millie Bobby Brown", "Britânica"));
		s1.setArtistas(new Pessoa("Finn Wolfhard", "Canadense"));
		programas.add(s1);

		Serie s2 = new Serie("Dark", "Série", 3, 26);
		s2.setDiretor(new Pessoa("Baran bo Odar", "Alemão"));
		s2.setArtistas(new Pessoa("Louis Hofmann", "Alemão"));
		s2.setArtistas(new Pessoa("Lisa Vicari", "Alemã"));
		programas.add(s2);

		// Imprimir todos
		for (ProgramaTV prog : programas) {
			System.out.println(prog);
			System.out.println("----------------------------");
		}
	}
}
