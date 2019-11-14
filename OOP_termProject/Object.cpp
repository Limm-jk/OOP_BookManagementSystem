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
	std::string date;	//������ yyyy-mm-dd
	int bookNumber;


public:
	//�޼ҵ�
	//�����ڷ� �ʱⰪ ����
	Book(std::string Title, std::string Author, std::string Date, int booknum)
		:bookTitle(Title), author(Author), date(Date),  bookNumber(booknum) {
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
	int getbookNumber() {
		return bookNumber;
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
	void setBookNumber(int booknum) {
		bookNumber = booknum;
	}
};

class person {
private:
	//�̸�
	//����
	//�̸���
	//����Ǽ�
	//���� ��¥
	std::string name;
	int age;
	std::string email;
	int loanNumber;
	std::string loanDate;

public:
	//�޼ҵ�
	//�����ڷ� �ʱⰪ ����
	person(std::string Name, int Age, std::string Email)
		:name(Name), age(Age), email(Email) {
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