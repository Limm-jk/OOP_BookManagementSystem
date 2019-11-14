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
	int userPage() {
		int input = 0;

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
		return input;
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

	void returnBook(std::string& returnId, std::string& returnTitle) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. 도서 반납을 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "반납할 책 이름을 입력해주세요 : ";
		std::cin >> returnTitle;
	}

	int manageBook() {
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

	void addBook(std::string& bookTitle, std::string& author, std::string& date, int& bookNumber) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 추가를 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "책의 제목을 입력해 주세요 : ";
		std::cin >> bookTitle;
		std::cout << "책의 저자를 입력해 주세요 : ";
		std::cin >> author;
		std::cout << "책의 출시일을 입력해 주세요(yyyy-mm-dd) : ";
		std::cin >> date;
		std::cout << "책의 고유 번호를 입력해 주세요 : ";
		std::cin >> bookNumber;
	}

	void deleteBook(int& bookNum) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;+
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



		std::cout << "2. 도서 삭제를 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "삭제할 도서의 고유번호를 입력해 주세요 : ";
		std::cin >> bookNum;
	}

	void searchBook(std::string& bookTitle) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "3. 도서 검색을 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "검색할 도서의 제목을 입력해 주세요 : ";
		std::cin >> bookTitle;
	}
};