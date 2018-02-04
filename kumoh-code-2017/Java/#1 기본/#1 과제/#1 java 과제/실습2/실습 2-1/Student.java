public class Student
{
	private String major; // �а�
	private int grade; // �г�
	private int id; // �й�
	private String name; // �̸�
	private String sex; // ����
	private String birth; // ����
	private float weight; // ü��
	private String address; // �ּ�
	
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
