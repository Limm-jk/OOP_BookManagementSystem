#include "View.cpp"
#include<stdlib.h>

class Controller {

	View view;
	int initScreenInput = 0;

	//대출 id, title
	std::string loanId;
	std::string bookTitle;
	//반납 id, title
	std::string returnId;
	std::string returnTitle;

	//도서 추가
	std::string addBookTitle;
	std::string addAuthor;
	std::string addDate;
	int addBookNumber;

	//도서 삭제
	int delBookNumber;

	//도서 검색
	std::string searchBookTitle;

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
				view.addBook(addBookTitle, addAuthor, addDate, addBookNumber);
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