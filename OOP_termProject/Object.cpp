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
	int getbookNumber() {
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