public class Cachorro {
    private Cachorro meuPet;
    private String nome;

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public static void main(String[] args){
        Cachorro cachorro;
        cachorro = new Cachorro();
        cachorro.setNome("Zeus");
        
    }
}
