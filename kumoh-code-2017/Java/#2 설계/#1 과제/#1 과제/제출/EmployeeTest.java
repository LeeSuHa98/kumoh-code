public class EmployeeTest
{
	public static void main(String[] args)
	{
		// instantiate a Employee object
		Employee employee = new Employee("Kim", "222-22-2222");
		employee.print(); // display employee information
		System.out.println("====================================");

		// instantiate a Employee object
		Employee employee2 = new Employee("Hong Kil Dong is my name", "010-123-4586965");
		employee2.print(); // display employee information
		employee2.setPhoneNumber("010-123-1234"); // change phone number
		employee2.print(); // display employee information
		System.out.println("====================================");

		// instantiate a Employee object
		Employee employee3 = new Employee("Kenny", "333-222-1110");
		employee3.print(); // display employee information
		employee3.setName("Tommy"); // change name
		employee3.print(); // display employee information
		System.out.println("====================================");

	} // end main
}
