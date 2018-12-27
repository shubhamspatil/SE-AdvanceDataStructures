package arith;
import arith.siddhi;

import java.util.*;
import java.lang.*;
import java.io.*;

public  class Arithmetic implements siddhi.siddhi1
{
	int op1,op2,result;
 	
 	Arithmetic()
	{
 		Scanner sc=new Scanner(System.in);
	
		System.out.println("Enter the first number:");
			op1=sc.nextInt();
	
		System.out.println("Enter the second number:");
			op2=sc.nextInt();	
	}
	
	public void add()
	{
		result=op1+op2;
		System.out.println("The addition of two variables is:" + result);
	}

	public void subtract() 
	{
		result=op1-op2;
		System.out.println("The subtraction of two variables is: " + result);
	
	}
	
	public void multiply()
	{
		 result=op1*op2;
		System.out.println("The multiplication of two variables is: " + result);
			
	}

	public void divide() 
	{
		result=op1/op2;
		System.out.println("The division of two variables is: " + result);
		
	}

	public static void main(String[] args)
	{
		int ch;
		char choice = 0;
		Arithmetic a=new Arithmetic();
		Scanner sc=new Scanner(System.in);
		
			System.out.println("Enter your choice:");
					ch=sc.nextInt();
				
				switch(ch)
				{
					case 1:
							a.add();
						break;
						
					case 2:
							a.subtract();	
						break;
						
					case 3:
						a.multiply();
						break;
						
					case 4:
						a.divide();
						break;
						
					default:
							System.out.println("You have entered wrong choice:");
				}	
		}
}