package com.ktds.jmj;

public class Bicycle {
	
	public void start() {
		BicycleBiz program = new BicycleBiz();
		program.startProgram();
	}

	public static void main(String[] args) {
		
		Bicycle bicycle = new Bicycle();
		bicycle.start();

	}

}
