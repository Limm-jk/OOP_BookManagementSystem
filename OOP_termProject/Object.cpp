#include<string>

class Book {
private:
	//����
	//����
	//��ó⵵
	//������ (�ʱⰪ �̴���)
	//å ������ȣ
	std::string bookTitle;
	std::string author;
	std::string loaner;
	std::string date;	//������ yy-mm-dd
	int ISBN;
	

public:
	//�޼ҵ�
	//�����ڷ� �ʱⰪ ����
	Book(std::string Title, std::string Author, std::string Date, int isbn)
		:bookTitle(Title), author(Author), date(Date), ISBN(isbn) {
		loaner = "";
	}

	//getter
	std::string getBookTitle() {
		return bookTitle;
	}
	std::string getAuthor() {
		return author;
	}
	std::string getLoaner() {
		return loaner;
	}
	std::string getDate() {
		return date;
	}
	int getISBN() {
		return ISBN;
	}

	//setter
	void setBookTitle(std::string Title) {
		bookTitle = Title;
	}
	void setAuthor(std::string Author) {
		author = Author;
	}
	void setLoaner(std::string Loaner) {
		loaner = Loaner;
	}
	void setDate(std::string Date) {
		date = Date;
	}
	void setISBN(int isbn) {
		ISBN = isbn;
	}
};

class person {
private:
	//�̸�
	//����
	//��ȭ��ȣ
	//�ֹι�ȣ
	//�̸���
	//����Ǽ�
	//���� ��¥
	std::string name;
	int age;
	std::string phoneNumber;
	std::string residentNumber;
	std::string email;
	int loanNumber;
	std::string loanDate;

public:
	//�޼ҵ�
	//�����ڷ� �ʱⰪ ����
	person(std::string Name, int Age, std::string PhoneNumber, std::string ResidentNumber, std::string Email)
	:name(Name), age(Age), phoneNumber(PhoneNumber), residentNumber(ResidentNumber), email(Email){
		loanNumber = 0;
		loanDate = "";
	}

	//getter
	std::string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	std::string getPhoneNumber() {
		return phoneNumber;
	}
	std::string getResidentNumber() {
		return residentNumber;
	}
	std::string getEmail() {
		return email;
	}
	int getLoanNumber() {
		return loanNumber;
	}
	std::string getLoanDate() {
		return loanDate;
	}

	//setter
	void setName(std::string Name) {
		name = Name;
	}
	void setAge(int Age) {
		age = Age;
	}
	void setPhoneNumber(std::string PhoneNumber) {
		phoneNumber = PhoneNumber;
	}
	void setResidentNumber(std::string ResidentNumber) {
		residentNumber = ResidentNumber;
	}
	void setEmail(std::string Email) {
		email = Email;
	}
	void setLoanNumber(int LoanNumber) {
		loanNumber = LoanNumber;
	}
	void setLoanDate(std::string date) {
		loanDate = date;
	}
};