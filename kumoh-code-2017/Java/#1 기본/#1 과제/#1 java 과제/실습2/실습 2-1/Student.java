public class Student
{
	private String major; // 학과
	private int grade; // 학년
	private int id; // 학번
	private String name; // 이름
	private String sex; // 성별
	private String birth; // 생일
	private float weight; // 체중
	private String address; // 주소
	
	public Student(String major, int grade, int id, String name, String sex, String birth, float weight, String address)
	{
		this.major = major;
		this.grade = grade;
		this.id = id;
		this.name = name;
		this.sex = sex;
		this.birth = birth;
		this.weight = weight;
		this.address = address;
	}
	
	public String getMajor(){return major;}
	public int getGrade(){return grade;}
	public int getId(){return id;}
	public String getName(){return name;}
	public String getSex(){return sex;}
	public String getBirth(){return birth;}
	public float getWeight(){return weight;}
	public String getAddress(){return address;}
}
