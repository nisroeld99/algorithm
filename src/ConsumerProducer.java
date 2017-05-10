package exercise;

class SyncStack { 
	char[] buff =new char[6];
	int idx = 0 ;
	
	synchronized  void pop(){
		while ( idx ==0 ){
			try{
				this.wait();// SyncStack을 호출한 Consumer를 재운다. Producer process는 진행
//				System.out.println(Thread.currentThread());  //test
			}catch(Exception e){	
			}	
		}
		this.notify(); // producer에서 자고 있는 것 깨우기 
		idx --;
		printStack();
		System.out.println("pop"+buff[idx]);
	}
	
	synchronized  void push(char c){
		while ( idx == buff.length-1){
			try{
				this.wait(); // producer 를 재운다  
			}catch(Exception e){
			}
			
		}
		this.notify();
		
		buff[idx] = c;
		printStack();
		System.out.println("push"+c);
		idx++;
	}
	private void printStack(){
		System.out.print("inStack : ");
		for (int i =0 ; i<=idx ;i++){
			System.out.print(buff[i]);
		}
		System.out.println();
	}
	
	
}

// 생산자 클래스 (스택에 값을 계속 넣음)
class Producer extends Thread {  
	SyncStack stack ;
	Producer(SyncStack stack){
		this.stack= stack; 
	}
	public void run(){
		
       for (int i=0; i<10; i++) {
    	   char c = (char)(Math.random() * 26 + 'A');

	          stack.push(c); 
	           try { 
	               Thread.sleep((int)(Math.random() * 150)); 
	           } catch (InterruptedException e) {  } 
	       } 
	


		
	}
} 

// 소비자 클래스 (스택에서 값을 계속 가져감)
// 생산자보다 소비자의 속도가 늦어서 스택에 쌓이게 함.
class Consumer extends Thread { 
	SyncStack theStack;  
	   public Consumer(SyncStack s) { 
	       theStack = s; 
	   }  
	   public void run() { 
	       
	       for (int i=0; i<10; i++) { 
	           theStack.pop(); 
	           try { 
	               Thread.sleep((int)(Math.random() * 300)); 
	           } catch (InterruptedException e) {  } 
	       } 
	   } 
	


} 

public class ProducerConsumer { 
   public static void main(String args[]) { 
	   SyncStack buf = new SyncStack();
	   Producer p = new Producer(buf);
	   Consumer c = new Consumer(buf);
	   p.start();
	   c.start();
   } 
}

