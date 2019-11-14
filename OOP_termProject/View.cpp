#include<iostream>
#include<list>
#include"Object.cpp"

class View {

public:
	//초기 UI를 보여주는 메소드
	//각 메소드에서 입력받을 때 입력받는 값에 대한 예외처리 필요

	//로그인 페이지
	void initScreen(std::string& Id, std::string& passwd) {
		
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "----------------------로그인---------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "ID : ";
		std::cin >> Id;
		std::cout << "Passwd : ";
		std::cin >> passwd;
	}

	//유저로 로그인
	void userPage(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 검색 / 대출" << std::endl;
		std::cout << "2. 도서 반납" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cin >> input;
		//예외처리 필요
	}

	void searchBook(std::string& bookTitle) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 검색 / 대출을 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		
		std::cout << "검색할 책을 입력해 주세요 : ";
		std::cin >> bookTitle;
	}

	void loanBook(std::list<Book> searchBooklist, int& bookNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "고유번호    제목      저자   출판사      대출여부" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getbookNumber();
			std::cout << "	";
			std::cout << (*list).getBookTitle();
			std::cout << "	";
			std::cout << (*list).getAuthor();
			std::cout << "	";
			std::cout << (*list).getPublisher();
			std::cout << "	";
			std::cout << (*list).getLoan() << std::endl;
			std::cout << "" << std::endl;
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		
		std::cout << "대출할 책의 고유번호를 입력해 주세요 : ";
		std::cin >> bookNumber;
	}

	void returnBook(person Person, int& bookNumber) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << Person.getLoanBook1()<<"     "<<Person.getLoanBook2()<<"     "<<Person.getLoanBook3()<< std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "반납할 책의 고유번호를 입력해주세요 : ";
		std::cin >> bookNumber;
	}

	int managePage() {
		int input;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 추가" << std::endl;
		std::cout << "2. 도서 삭제" << std::endl;
		std::cout << "3. 도서 검색" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		
		std::cin >> input;
		return input;
	}


	void addBook(std::string& bookTitle, std::string& author, std::string& publisher, int& bookN ) {

		std::cout << "추가할 도서의 제목을 입력해 주세요 : ";
		std::cin >> bookTitle;
		std::cout << "추가할 도서의 작가를 입력해 주세요 : ";
		std::cin >> author;
		std::cout << "추가할 도서의 출판사를 입력해 주세요 : ";
		std::cin >> publisher;
		std::cout << "추가할 도서의 책번호를 입력해 주세요 : ";
		std::cin >> bookN;
	}

	void addPerson(std::string& name, std::string& id, std::string& pwd) {

		std::cout << "추가할 회원의 이름을 입력해 주세요 : ";
		std::cin >> name;
		std::cout << "추가할 회원의 ID를 입력해 주세요 : ";
		std::cin >> id;
		std::cout << "추가할 회원의 비밀번호를 입력해 주세요 : ";
		std::cin >> pwd;
	}
};