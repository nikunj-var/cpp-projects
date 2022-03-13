class Box{
    double length;
    double width;
    double depth;
    Box(double w,double h,double d){
        width=w;
        length=h;
        depth=d;
    }
    Box(){
         width=-1;
        length=-1;
        depth=d-1
    }
    Box(double len){
        width=length=depth=len;
    }
    double volume(){
        return width*length*depth;
    }
}
public class Main
{
	public static void main(String[] args) {
        Box b1=new Box(10,20,30);
        Box b2=new Box();
        Box b3=new Box(10);
        double vol;
        vol=b3.volume();
        System.out.println(vol);
         vol=b2.volume();
        System.out.println(vol);
	 vol=b1.volume();
        System.out.println(vol);
	
	}
}
