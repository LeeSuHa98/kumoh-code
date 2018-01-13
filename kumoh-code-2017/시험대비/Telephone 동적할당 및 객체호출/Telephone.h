#include <iostream>
#include <string>

using namespace std;

class Telephone
{
private:
	string message;
	Telephone* tmp;
	string phone_no;
public:
	Telephone() {}
	Telephone(string phone_no) 
	{
		this->phone_no = phone_no;
	}
	~Telephone() { delete[] tmp; }

	void setMessage(string message) { this->message = message; }
	void setPhone_no(string phone_no) { this->phone_no = phone_no; }
	string getMessage() { return message; }
	string getPhone_no() { return phone_no; }

	void connect(Telephone& p);
	void send();
	string receive();
	void disconnect();
};