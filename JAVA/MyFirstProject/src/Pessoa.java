public class Pessoa {
    private Cachorro meuPet;
    private String nome;

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public static void main(String[] args){
        System.out.prinln("Ola Mundo!");
        Pessoa professor;
        Cachorro caoProfessor;
        professor = new Pessoa();
        professor.setNome("Braida");
        caoProfessor = new Cachorro();

    }
}
