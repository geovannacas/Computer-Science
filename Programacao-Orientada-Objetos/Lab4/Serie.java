public class Serie extends ProgramaTV {
	
	private int temporadas;
	private int episodios;

	public Serie(String nome, String categoria, int temporadas, int episodios) {
		super(nome, categoria);
		this.temporadas = temporadas;
		this.episodios = episodios;
	}

	public int getTemporadas() {
		return temporadas;
	}

	public int getEpisodios() {
		return episodios;
	}

	@Override
	public String toString() {
		String base = super.toString();
		base += "Temporadas: " + temporadas + "\n";
		base += "Episódios: " + episodios + "\n";
		return base;
	}
}
