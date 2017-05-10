/*  busy waiting을 구현 (spinlock)
   	   Test task = new Test();
	   Test task2 = new Test();
	   task.start();
	   while (task.isAlive()){
		   
	   }
	   task2.start();
*/


package exercise;

class TheTask implements Runnable{
	
    // 해당 쓰레드가 실행되면 자기 자신의 모니터링 락을 획득
    // 5번 반복하면서 0.5초씩 쉬면서 total에 값을 누적
    // 그후에 notify()메소드를 호출하여 wait하고 있는 쓰레드를 깨움 
     public int total;
     @Override
     public void run(){
         synchronized(this){
             for(int i=0; i<5 ; i++){
                 System.out.println(i + "를 더합니다.");
                 total += i;
                 try {
                     Thread.sleep(500);
                 } catch (InterruptedException e) {
                     e.printStackTrace();
                 }
             }
             System.out.println(total);
             notify();
         }
     }
	
}

public class Main {
   

   public static void main(String[] args) {
      

	  Runnable r = new TheTask();
	  Runnable r2 = new TheTask();
	  Thread task = new Thread(r);
	  Thread task2 = new Thread(r);
	  
	  
	  
	  task.start();
	  
	  synchronized(task){
		  try{
			  System.out.println("task가 완료될때까지 stop ");
			  task.wait();
		  }catch(Exception e){
		  }
	  }
	  
	  task2.start();	
   }
   
}

