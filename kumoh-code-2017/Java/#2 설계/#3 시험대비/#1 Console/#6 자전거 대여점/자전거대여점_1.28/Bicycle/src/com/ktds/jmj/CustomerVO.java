package com.ktds.jmj;

import java.util.Date;
import java.util.List;

public class CustomerVO {

	private String name; // 이름
	private String what; // 어떤자전거를 빌렸는지
	private long rentTime; // 빌린시간

	private int money;
	
	public int getMoney() {
		return money;
	}
	public void setMoney(int money) {
		this.money = money;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public String getType() {
		return what;
	}
	public void setType(String what) {
		this.what = what;
	}

	public long getRentTime() {
		return rentTime;
	}
	public void setRentTime(long rentTime) {
		this.rentTime = rentTime;
	}
	


}
