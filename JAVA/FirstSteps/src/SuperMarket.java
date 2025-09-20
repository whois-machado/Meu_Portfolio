public class SuperMarket {

    public static void main(String[] args){
        System.out.print("The products are ");
        nameProd();
        System.out.print("and its prices are ");
        priceTag();
        System.out.print("The total is ");
        sumOp();
    }
    public static void sumOp(){
        System.out.println(3+11);
    }
    public static void priceTag(){
        System.out.print("[$3] ");
        System.out.println("& [$11]");
    }
    public static void nameProd(){
        System.out.print("rice ");
        System.out.println("& meat");
    }
}
