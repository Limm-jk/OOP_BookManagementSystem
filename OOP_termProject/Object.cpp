#pragma once
#include<string>

//인터페이스 및 추상클래스
class Library{
public:
	virtual ~Library() {}  // 가상 소멸자의 선언
	
	virtual std::string getAuthor() = 0;
	virtual void setAuthor(std::string Author) = 0;
	virtual std::string getPublisher() = 0;
	virtual void setPublisher(std::string Publisher) = 0;
};

//인터페이스 및 추상클래스
class People {
public :
	virtual ~People() {}	//가상 소멸자 선언

	virtual void setName(std::string Name) = 0;
	virtual std::string getName() = 0;
};


class Book :Library{
private:
	//제목
	//저자
	//출판사
	//책 고유번호
	//대출 여부
	std::string bookTitle;
	std::string author;
	std::string publisher;
	int bookNumber;
	bool loan;

public:
	//메소드
	//생성자로 초기값 설정
	Book() {
		bookTitle = "";
		author = "";
		publisher = "";
		bookNumber = 0;
		loan = false;
	}
	Book(std::string Title, std::string Author, std::string Publisher, int BookNumber)
	:bookTitle(Title), author(Author), publisher(Publisher), bookNumber(BookNumber){
		loan = false;
	}

	~Book() {}

	//getter
	std::string getBookTitle() {
		return bookTitle;
	}
	std::string getAuthor() {
		return author;
	}
	std::string getPublisher() {
		return publisher;
	}
	int getBookNumber() {
		return bookNumber;
	}
	bool getLoan() {
		return loan;
	}
	//setter
	void setBookTitle(std::string Title) {
		bookTitle = Title;
	}
	void setAuthor(std::string Author) {
		author = Author;
	}
	void setPublisher(std::string Publisher) {
		publisher = Publisher;
	}
	void setBookNumber(int booknum) {
		bookNumber = booknum;
	}
	void setLoan(bool Loan) {
		loan = Loan;
	}
};

class person: People {
private:
	//이름
	//아이디
	//패스워드
	//대출권수
	//대출 책1
	//대출 책2
	//대출 책3

	std::string name;
	std::string id;
	std::string passwd;
	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

public:
	//메소드
	//생성자로 초기값 설정
	person() {
		name = "";
		id = "";
		passwd = "";
		loanNumber = 0;
		loanBook1 = "";
		loanBook2 = "";
		loanBook3 = "";
	}

	person(std::string Name, std::string Id, std::string Passwd) 
	:name(Name), id(Id), passwd(Passwd){
		loanNumber = 0;
		loanBook1 = "";
		loanBook2 = "";
		loanBook3 = "";
	}

	//getter
	std::string getName() {
		return name;
	}
	std::string getId() {
		return id;
	}
	std::string getPasswd() {
		return passwd;
	}
	int getLoanNumber() {
		return loanNumber;
	}
	std::string getLoanBook1() {
		return loanBook1;
	}
	std::string getLoanBook2() {
		return loanBook2;
	}
	std::string getLoanBook3() {
		return loanBook3;
	}

	//setter
	void setName(std::string Name) {
		name = Name;
	}
	void setId(std::string Id) {
		id = Id;
	}
	void setPasswd(std::string Passwd) {
		passwd = Passwd;
	}
	void setLoanNumber(int LoanNumber) {
		loanNumber = LoanNumber;
	}
	void setLoanBook1(std::string LoanBook1) {
		loanBook1 = LoanBook1;
	}
	void setLoanBook2(std::string LoanBook2) {
		loanBook2 = LoanBook2;
	}
	// setLoanBook3 로 수정완료. 
	void setLoanBook3(std::string LoanBook3) {
		loanBook3 = LoanBook3;
	}
};