package PhiloTest;


public class Philostable {
	
	Object[] chopstick;
	Philosopher[] philos;
	
	
	Philostable(){}
	Philostable(int num){
		chopstick = new Object[num];
		philos = new Philosopher[num];		
		for (int i = 0 ; i<num ; i++){
			chopstick[i] = new Object();
			if ( i %2 == 0 )
				philos[i] = new Philosopher(i,i,(i+1)%(num));
			else 
				philos[i] = new Philosopher(i,(i+1)%(num),i);
		}
		
	}
	
	class Philosopher extends Thread{
		int id, left,right;
		
		Philosopher(){}
		Philosopher(int id ,int left,int right){
			this.id = id;
			this.left = left;
			this.right = right;
		}
		public void run(){
			System.out.println(id + "철학자는 ready to eat ");
			while (true){
				
				try {
					sleep(1500);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				synchronized (chopstick[left]) {
					System.out.println(id + "철학자는 "+ left+"포크를 들었다! " );
					try {
						sleep(1500);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					synchronized (chopstick[right]) {
						System.out.println(id + "철학자는 "+ right+"포크를 들었다! " );						
						try {
							sleep(1500);
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						System.out.println(id + "철학자는 " +"먹는다" );
					}
				}
				
				
			}
		}
	}

	private void starteating(){
		for (int i = 0 ; i<philos.length ; i++){
			philos[i].start();			
		}
		try {
			philos[0].join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}
  	
	public static void main(String[] args) {
		Philostable d = new Philostable(5);
		d.starteating();
	}

}

