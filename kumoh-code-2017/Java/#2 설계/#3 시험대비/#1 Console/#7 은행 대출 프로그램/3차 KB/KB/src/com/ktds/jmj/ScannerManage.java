package com.ktds.jmj;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ScannerManage {
	private Scanner input;
	
	public String inputScanner() {
		input = new Scanner(System.in);
		return input.next();
	}
	
	public int inputScannerInt(){
		input = new Scanner(System.in);
		return input.nextInt();
	}
	
	public boolean checkScanner( String checkScan, String whatString ) {
		if ( !whatString.matches(checkScan) ) {
			return true;
		}
		else {
			return false;
		}
	}

}
