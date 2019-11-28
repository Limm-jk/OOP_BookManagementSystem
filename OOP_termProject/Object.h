#pragma once
#include<string>

class Book {
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
	Book(std::string Title, std::string Author, std::string Publisher, int BookNumber);

	//getter
	std::string getBookTitle();
	std::string getAuthor();
	std::string getPublisher();
	int getBookNumber();
	bool getLoan();
	//setter
	void setBookTitle(std::string Title);
	void setAuthor(std::string Author);
	void setPublisher(std::string Publisher);
	void setBookNumber(int booknum);
	void setLoan(bool Loan);
};

class person {
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
	person(std::string Name, std::string Id, std::string Passwd);

	//getter
	std::string getName();
	std::string getId();
	std::string getPasswd();
	int getLoanNumber();
	std::string getLoanBook1();
	std::string getLoanBook2();
	std::string getLoanBook3();
	
	//setter
	void setName(std::string Name);
	void setId(std::string Id);
	void setPasswd(std::string Passwd);
	void setLoanNumber(int LoanNumber);
	void setLoanBook1(std::string LoanBook1);
	void setLoanBook2(std::string LoanBook2);
	// setLoanBook3 로 수정완료. 
	void setLoanBook3(std::string LoanBook3);
};