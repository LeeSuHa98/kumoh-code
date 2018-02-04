package com.ktds.jmj;

import java.util.Scanner;

public class InputString {
	
	Scanner input = new Scanner( System.in );
	int Array[] = new int[2];
	String expression = "";
	public void runProgram() {
		while(true){
			
			System.out.println("식을 입력하세요.");
			expression = input.nextLine();
			expression = expression.replace(" ","");
			System.out.println(expression);
	
			if ( expression.matches("[0-9]*[+][0-9]*")){
				checkOperatorAndExecute("+");
				System.out.println(expression + "=" + (Array[0] + Array[1]));
			}
			else if (expression.matches("[0-9]*[-][0-9]*")){
				checkOperatorAndExecute("-");
				System.out.println(expression + "=" + (Array[0] - Array[1]));
			}
			else if ( expression.matches("[0-9]*[*][0-9]*")){
				checkOperatorAndExecute("*");
				System.out.println(expression + "=" + (Array[0] * Array[1]));
			}
			else if ( expression.matches("[0-9]*[/][0-9]*")) {
				checkOperatorAndExecute("/");
				System.out.println(expression + "=" + ((double)Array[0] / (double)Array[1]));
			}
			else{
			}
		}
	}
	
	public void checkOperatorAndExecute (String operator ) {
		Array[0] = Integer.parseInt( expression.substring( 0, expression.indexOf(operator) ) );
		Array[1] = Integer.parseInt( expression.substring( expression.indexOf(operator) + 1 ) );	
	}
	

}
