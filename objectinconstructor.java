//use of objects as constructor parameter to copy the object elements

class box{
    double width;
    double height;
    double depth;
    box(box ob){
        width=ob.width;
        depth=ob.depth;
        height=ob.height;        
    }
    box(double h,double w,double d){
        width=w;
        height=h;
        depth=d;
    }
    Box(){
         width=-1;
        height=-1;
        depth=d-1
    }
    box(double len){
        width=height=depth=len;
    }
    double volume(){
        return width*height*depth;
    }
}

public class Main
{
	public static void main(String[] args) {
      box b1=new box(10,20,30);
      box b2=new box();
      box b3=new box(7);
      box b4=new box(b1);//create copy of my box
      double vol;
        vol=b1.volume();
        System.out.println(vol);        
        vol=b2.volume();
        System.out.println(vol);
        vol=b3.volume();
        System.out.println(vol);
        vol=b4.volume();
        System.out.println(vol);            

    }}