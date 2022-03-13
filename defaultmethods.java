//default methods
interface camera{
    void takesnap();
    void recordvideo();
    private void greet(){
        System.out.println("good morning");
    }
    default void recordnewvideo(){
        greet();
        System.out.println("recording new video");
    }
}
interface wifi{
    String[] getnetworks();
    void connecttonetwork(String network);
}
class cellphone{
    void callnumber(int phonennumber){
        System.out.println("calling"+phonennumber);
    }
    void pickcall(){
        System.out.println("connecting..");
    }
}
class smartphone extends cellphone implements wifi,camera{
    public void takesnap(){
            System.out.println("taking snap");
    }
    public void recordvideo(){
        System.out.println("recording video..");
    }
    public String[] getnetworks(){
        System.out.println("getting list of networks..");
        String[] networklist={"nikunj","dev","love"};
        return networklist;
    }
    public void connecttonetwork(String network){
        System.out.println("connecting to"+network);
    }
}
public class Main
{
	public static void main(String[] args) {
	smartphone s=new smartphone();
		s.recordvideo();
		s.recordnewvideo();
	//	s.greet();//it will throw an error
	String[] ar=s.getnetworks();
	for(String item : ar)
	    System.out.println(item);
	}

}

//inheritance in interface
interface sampleinterface{
    void meth1();
    void meth2();
}
interface childinterface extends sampleinterface{
    void meth3();
    void meth4();
}
class mysampleclass implements childinterface{
    public void meth3(){
        System.out.println("meth3");
    }
        public void meth4(){
        System.out.println("meth4");
    }
        public void meth1(){
        System.out.println("meth1");
    }
        public void meth2(){
        System.out.println("meth2");
    }
}
public class Main
{
	public static void main(String[] args) {
        mysampleclass s=new mysampleclass();
        s.meth1();
        s.meth2();
        s.meth3();
        s.meth4();
	}
}

//threads in java

class mythread extends Thread{
    @Override
    public void run(){
        int i=0;
        while(i<40){
            System.out.println("my thread is running");
            System.out.println("i am happy");
            i++;
        }
    }
}
class mythread2 extends Thread{
    @Override
    public void run(){
        int i=0;
        while(i<40){
            System.out.println("thread is working");
            System.out.println("i am sad");
            i++;
        }
    }
}
public class Main{
	public static void main(String[] args) {
	mythread2 t2 = new mythread2();
    mythread t1=new mythread();
    t1.start();
    t2.start();
	}
}

//creating java thread using runnable interface
class mythreadrunnable1 implements Runnable{
    @Override
    public void run(){
        int i=0;
        while(i<40){
            System.out.println("i am a thread 1 not thread");
            System.out.println("i am happy");
            i++;
        }
    }
}
class mythreadrunnable2 implements Runnable{
    @Override
    public void run(){
        int i=0;
        while(i<40){
            System.out.println("thread is working");
            System.out.println("i am sad");
            i++;
        }
    }
}
public class Main{
	public static void main(String[] args) {
	    mythreadrunnable1 th=new mythreadrunnable1();
	    Thread g1=new Thread(th);
	    
	    mythreadrunnable2 th2=new mythreadrunnable2();
	    Thread g2=new Thread(th2);
	    g1.start();
	    g2.start();
	}
}
//thread constructors
class mythread extends Thread{
    public mythread(String name){
        super(name);
    }
    public void run(){
        
        
        int i=10;
    }
}
public class Main
{
	public static void main(String[] args) {
        mythread m=new mythread("nikunj");
        m.start();
        System.out.println("id of thread is"+m.getId());
         System.out.println("id of thread is"+m.getName());
	}
}

//thread priorities

class mythr1 extends Thread{
    public mythr1(String name){
        super(name);
    }
    public void run(){
        int i=34;
        while(true){
        System.out.println("thank you"+this.getName());
        }
    }
}
//which thread gets executed is highly dependent on the os!
public class Main
{
	public static void main(String[] args) {
	    
	    mythr1 th1=new mythr1("nikunj");
	      mythr1 th2=new mythr1("love");
	        mythr1 th3=new mythr1("dev");
	        th3.setPriority(Thread.MAX_PRIORITY);
	        th1.start();
	        th2.start();
	        th3.start();
	}
}
