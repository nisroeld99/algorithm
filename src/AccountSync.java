package exercise;


class Account {
	int money;
	
	public void run(){
		money++;
		System.out.println(money);
	}
	
	synchronized void deposit(int amount){
		if ( amount < 0){
			System.out.println("wrong!");			
		}else {
			int new_money = money+ amount;
			try{
				Thread.sleep(500);				
			}catch(Exception e){
			}
			this.money = new_money;
			System.out.println(amount+"원이 입금되었습니다. 잔금 : "+money);
			
		}
		      
	}
	synchronized void withdraw(int amount){
		if ( money - amount < 0){
			System.out.println("wrong!");			
		}else {
			int new_money = money- amount;
			try{
				Thread.sleep(500);
			}catch(Exception e){
				
			}
			
			this.money = new_money;
			System.out.println(amount+"원이 출금되었습니다. 잔금 : "+money);

		}		
	}	
}

class Deposit extends Thread{
	Account acc ;
	int amount = 0 ;
	Deposit(){}
	Deposit(Account acc, int amount){
		this.acc = acc ;
		this.amount = amount;
	}
	public void run(){
		acc.deposit(amount);		
	}
}
class Withdraw extends Thread{
	Account acc ;
	int amount = 0 ;
	Withdraw(){}
	Withdraw(Account acc, int amount){
		this.acc = acc ;
		this.amount = amount;
	}
	public void run(){
		acc.withdraw(amount);	
	}
}

public class Main {  
   public static void main(String[] args) {
	   Account ac = new Account();
	   ac.money = 0 ;
	   Deposit d1 = new Deposit(ac,500);
	   Withdraw w1 = new Withdraw(ac,500);
	   Deposit d2 = new Deposit(ac,500);
	   Withdraw w2 = new Withdraw(ac,500);
	   Deposit d3 = new Deposit(ac,500);
	   Withdraw w3 = new Withdraw(ac,500);
	   Deposit d4 = new Deposit(ac,500);
	   Withdraw w4 = new Withdraw(ac,500);
	   d1.start();
	   w1.start();
	   d2.start();
	   w2.start();
	   d3.start();
	   w3.start();
	   d4.start();
	   w4.start();
  }  
}
