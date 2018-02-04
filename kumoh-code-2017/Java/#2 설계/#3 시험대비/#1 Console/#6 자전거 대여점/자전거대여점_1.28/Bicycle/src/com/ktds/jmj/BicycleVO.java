package com.ktds.jmj;

public class BicycleVO {
	
	private String type;
	private int cost; // 비용
	private int count; // count
	
	public BicycleVO(String type, int cost, int count){
		setType(type);
		setCost(cost);
		setCount(count);
	}
	
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public int getCost() {
		return cost;
	}
	public void setCost(int cost) {
		this.cost = cost;
	}
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	
	/**
	 * 빌릴경우 count에서 하나 빼준다.
	 */
	public void rent(){ 
		this.count--;
		System.out.println(this.getType() + "한대를 대여하셨습니다.");
	}
	
	/**
	 * 반납 ( 금액을 계산하고, count를 하나 올려준다. ) 
	 * @param time 빌린시간에서 10분으로 나눈 값
	 * @return 내야하는 금액을 반환시킨다.
	 */
	public void back(){ 
		this.count++;
		System.out.println(this.getType()  + "한대를 반납하셨습니다.");
	}
	
	/**
	 * 보유 자전거 수 출력
	 */
	public void currentCount(){ // 현재 count 출력
		System.out.println(this.getType() + " : " + this.count + "(10분당 : " + this.cost + "천원)");
	}
	
	public boolean checkCount() { // count 확인
		if ( this.getCount() == 0 ){
			return true;
		}
		return false;
	}

}
