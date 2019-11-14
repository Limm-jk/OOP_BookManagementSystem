#include "View.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {

	View view;
	int initScreenInput = 0;

	//book list선언(링크드리스트 - STL사용)
	std::list<Book> booklist;
	//person list선언(링크드리스트 - STL사용)
	std::list<person> personlist;

	//대출 id, title
	std::string loanId;
	std::string bookTitle;
	//반납 id, title
	std::string returnId;
	std::string returnTitle;

	//회원추가
	std::string name;
	std::string id;
	std::string passwd;

	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

	//도서 추가
	std::string addbookTitle;
	std::string addauthor;
	std::string addpublisher;
	int addbookNumber;
	//대출자
	bool addloan;

	//도서 삭제
	int delBookNumber;

	//도서 검색
	std::string searchBookTitle;

	void addbook(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
	}
	void addPerson(std::string& name, std::string& id, std::string& passwd) {
		view.addPerson(name, id, passwd);
		person newPerson(name, id, passwd);
		personlist.push_back(newPerson);
	}
public:
	void run() {

		system("cls");
		initScreenInput = view.initScreen();	//초기화면
		if (initScreenInput == 1) {				//초기화면의 입력값이 도서대출,반납 선택
			int LoanReturnInput = 0;			
			system("cls");
			LoanReturnInput = view.LoanReturn();	//도서 대출 반납 화면
			if (LoanReturnInput == 1) {				//대출
				system("cls");
				view.loanBook(loanId, bookTitle);
			}
			else if (LoanReturnInput == 2) {		//반납
				system("cls");
				view.returnBook(returnId, returnTitle);
			}
		
		}
		else if (initScreenInput == 2) {		//초기 화면에서 도서관리 선택
			system("cls");
			int manageBookInput = view.manageBook();	//도서 관리 화면
			if (manageBookInput == 1) {				//도서 추가
				system("cls");
				//view.addBook(addBookTitle, addAuthor, addDate, addBookNumber);
			}
			else if (manageBookInput == 2) {		//도서 삭제
				system("cls");
				view.deleteBook(delBookNumber);
			}
			else if (manageBookInput == 3) {		//도서 검색
				system("cls");
				view.searchBook(searchBookTitle);
			}
		}
		else if (initScreenInput == 3) {		//초기 화면에서 회원관리 선택

		}

	}
};

int main() {
	Controller appControl;
	while (1) {
		appControl.run();
	}
	return 0;
}