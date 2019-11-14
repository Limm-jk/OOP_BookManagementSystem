#include<iostream>


class View {

public:
	//초기 UI를 보여주는 메소드
	void login(std::string& returnId, std::string& returnpw) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-- 도서 관리 시스템입니다.--" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "ID를 입력해 주세요 : ";
		std::cin >> returnId;
		std::cout << "Password를 입력해주세요 : ";
		std::cin >> returnpw;
	}

	int initScreen() {
		int input;

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 반납, 대출, 조회" << std::endl;
		std::cout << "2. 도서 관리" << std::endl;
		std::cout << "3. 회원 관리" << std::endl;
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
	int LoanReturn() {
		int input = 0;

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 대출" << std::endl;
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

		return input;
	}

	void loanBook(std::string& loanId, std::string& bookTitle) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 대출을 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "ID를 입력해 주세요 : ";
		std::cin >> loanId;
		std::cout << "대출할 책 이름을 입력해주세요 : ";
		std::cin >> bookTitle;

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

		std::cout << "ID를 입력해 주세요 : ";
		std::cin >> returnId;
		std::cout << "반납할 책 이름을 입력해주세요 : ";
		std::cin >> returnTitle;
	}

	void inputError() {
		std::cout << "\n\n\n 잘못된 입력입니다. \n\n\n" <<std::endl;
	}
};