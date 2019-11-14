#include "View.cpp"
#include<stdlib.h>

class Controller {

	bool idcheck(std::string returnId) {
		return false;
	}
	bool pwcheck(std::string returnpw) {
		return true;
	}
public:
	void run() {

		View view;
		int initScreenInput = 0;

		//대출 id, title
		std::string loanId;
		std::string bookTitle;
		//반납 id, title
		std::string returnId;
		std::string returnpw;
		std::string returnTitle;

		system("cls");
		view.login(returnId, returnpw);
		if (!idcheck(returnId)) {
			view.inputError();
		}
		
		initScreenInput = view.initScreen();
		if (initScreenInput == 1) {
			int LoanReturnInput = 0;
			system("cls");
			LoanReturnInput = view.LoanReturn();
			if (LoanReturnInput == 1) {
				system("cls");
				view.loanBook(loanId, bookTitle);
			}
			else if (LoanReturnInput == 2) {
				system("cls");
				view.returnBook(returnId, returnTitle);
			}
		}



	}
	//초기 UI를 요청하는 부분
	//입력받은 값에 대한 처리 (검색, 저장, 수정 등)
	//대출입력을 받은 것에 대한 처리
	//회원가입 처리(모델의 person에 입력받은 값 설정)
};

int main() {
	Controller appControl;
	while (1) {
		appControl.run();
	}
	return 0;
}