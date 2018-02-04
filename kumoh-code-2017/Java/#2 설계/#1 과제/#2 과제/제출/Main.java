package 명단관리;

public class Main 
{
	public static void main(String[] args) 
	{
		try {
			Student studentObj = new Student("이순신", 2, "김현수", "충무시");
			studentObj.show();
			studentObj.changeAddress("서울시");
			studentObj.show();
			
			Under underObj = new Under("학부", "이순신", 2, "김현수", "충무시", "석향");
			underObj.show(); 
			underObj.changeAddress("서울시");
			underObj.changeCircle("AIT"); // underObj.changeCircle("");로
			//바꾸어실행한후예외발생확인요
//			underObj.changeCircle("");
			underObj.show();

			Graduate graduateObj = new Graduate("대학원", "장길산", 1, "김태남", "황해도", "AI");
			graduateObj.show();
			graduateObj.changeAddress("서울시");
			graduateObj.changeMajor("PL"); //  graduateObj.changeMajor("");로 
			// 바꾸어실행한후예외발생확인요
//			graduateObj.changeMajor("");
			graduateObj.show();

			IndustryGraduate industryGraduateObj = new IndustryGraduate("대학원", "홍길동", 1, "박인용", "구미시", "AI", "삼성", "신기술", "책임");

			industryGraduateObj.show();
			industryGraduateObj.changeAddress("서울시");
			industryGraduateObj.changeMajor("PL");
			industryGraduateObj.changePosition("이사");
			//industryGraduateObj.changePosition("");로
			//바꾸어실행한후예외발생확인요
//			industryGraduateObj.changePosition("");
			industryGraduateObj.show();
		}
		catch (MyException e) 
		{
			System.out.println("오류번호: " + e.getCode());
			System.out.println("오류내용: " + e.getDescription());
		}
	}
}
