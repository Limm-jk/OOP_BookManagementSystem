#include<iostream>
#include<list>
#include"Object.cpp"
#include <windows.h>

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
		std::cout << "0. 로그인 페이지로 돌아가기" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
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

		//return true;
	}

	void loanBook(std::list<Book> searchBooklist, int& bookNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "고유번호    제목      저자   출판사      대출여부" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getBookNumber();
			std::cout << "	";
			std::cout << (*list).getBookTitle();
			std::cout << "	";
			std::cout << (*list).getAuthor();
			std::cout << "	";
			std::cout << (*list).getPublisher();
			std::cout << "	";
			std::cout << (*list).getLoan() << std::endl;
			std::cout << "" << std::endl;
			
			++list; //이터레이터 증가
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "대출할 책의 고유번호를 입력해 주세요 : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "대출할 책의 고유번호는 숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}

		/*for (std::list<Book>::iterator test = searchBooklist.begin(); test != searchBooklist.end(); ++test) {
			if ((*test).getBookNumber() == bookNumber) {
				return true;
			}
		}
		return false;*/
	}

	void returnBook(person Person, int& bookNumber) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << Person.getLoanBook1() << "     " << Person.getLoanBook2() << "     " << Person.getLoanBook3() << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "반납할 책의 고유번호를 입력해주세요 : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "반납할 책의 고유번호는 숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}

		//if (Person.getLoanBook1() != "") {
		//	int a = atoi(Person.getLoanBook1().c_str());
		//	if (a == bookNumber) {
		//		return true;
		//	}
		//}
		//if (Person.getLoanBook2() != "") {
		//	int b = atoi(Person.getLoanBook2().c_str());
		//	if (b == bookNumber) {
		//		return true;
		//	}
		//}
		//if (Person.getLoanBook3() != "") {
		//	int c = atoi(Person.getLoanBook3().c_str());
		//	if (c == bookNumber) {
		//		return true;
		//	}
		//}

		////반납할 책의 고유번호를 입력하지 않았을 때 false
		//return false;
	}

	void managePage(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 관리" << std::endl;
		std::cout << "2. 회원 관리" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. 로그인 페이지로 돌아갑니다." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;


		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}
	
	
	void manageBook(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 도서 추가" << std::endl;
		std::cout << "2. 도서 삭제" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. 이전 페이지로 돌아갑니다." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}

	void managePerson(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 회원 추가" << std::endl;
		std::cout << "2. 삭제" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. 이전 페이지로 돌아갑니다." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;


		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}


	void addBook(std::string& bookTitle, std::string& author, std::string& publisher, int& bookN) {
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

		std::cout << "추가할 도서의 제목을 입력해 주세요 : ";
		std::cin >> bookTitle;
		std::cout << "추가할 도서의 작가를 입력해 주세요 : ";
		std::cin >> author;
		std::cout << "추가할 도서의 출판사를 입력해 주세요 : ";
		std::cin >> publisher;
		
		//숫자만 입력 예외처리
		while(1){
			std::cout << "추가할 도서의 책번호를 입력해 주세요 : ";
			std::cin >> bookN;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "도서의 책 번호는 숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*
		if (bookTitle != "" && author != "" && publisher != "") {
			return true;
		}

		return false;*/
	}

	void addPerson(std::string& name, std::string& id, std::string& pwd) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. 회원 추가를 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "추가할 회원의 이름을 입력해 주세요 : ";
		std::cin >> name;
		std::cout << "추가할 회원의 ID를 입력해 주세요 : ";
		std::cin >> id;
		std::cout << "추가할 회원의 비밀번호를 입력해 주세요 : ";
		std::cin >> pwd;

		/*if (name != "" && id != "" && pwd != "") {
			return true;
		}
		else {
			return false;
		}*/
	}

	void returnBook(std::list<Book> searchBooklist, int& returnNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "고유번호     제목      저자      출판사     대출여부" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getBookNumber();
			std::cout << "           ";
			std::cout << (*list).getBookTitle();
			std::cout << "	      ";
			std::cout << (*list).getAuthor();
			std::cout << "	      ";
			std::cout << (*list).getPublisher();
			std::cout << "	      ";
			if ((*list).getLoan() == true) {
				std::cout << "대출가능" << std::endl;
			}
			else {
				std::cout << "대출불가" << std::endl;
			}
			std::cout << "" << std::endl;
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "반납할 책의 고유번호를 입력해주세요 : ";
			std::cin >> returnNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "반납할 책의 고유번호는 숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		
		/*for (std::list<Book>::iterator test = searchBooklist.begin(); test != searchBooklist.end(); ++test) {
			if ((*test).getBookNumber() == returnNumber) {
				return true;
			}
		}
		return false;*/
		
	}

	void deletePerson(std::string& deleteId) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. 회원 삭제를 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "삭제할 회원의 id를 입력해 주세요 :";
		std::cin >> deleteId;

		//return true;
	}
	
	void deleteBook(int bookNumber) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. 도서 삭제를 선택하셨습니다." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "삭제할 책의 고유번호를 입력해주세요 : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "삭제할 책의 고유번호는 숫자만 입력해 주세요" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
	}

	void faultPage() {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "잘못된 입력입니다. 다시 입력해 주세요" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		Sleep(1000);
	}
};
