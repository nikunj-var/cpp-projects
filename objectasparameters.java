class test{
    int a,int b;
    test(int i,int j){
        a=i;
        b=j;
    }
    //return true if o is equal to the invoking object
    boolean equalto(test o){
        if(o.a==a && o.b==b){
            return true;
        }
        else
            return false;
    }
}
public class Main
{
	public static void main(String[] args) {
        test ob1=new test(100,22);
        test ob2=new test(100,22);
        System.out.println(ob1.equalto(ob2));
    }}