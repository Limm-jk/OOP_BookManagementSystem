#include "View.cpp"
#include<stdlib.h>

class Controller {


public:
	void run() {

		View view;
		int initScreenInput = 0;

		//���� id, title
		std::string loanId;
		std::string bookTitle;
		//�ݳ� id, title
		std::string returnId;
		std::string returnTitle;

		system("cls");
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
	//�ʱ� UI�� ��û�ϴ� �κ�
	//�Է¹��� ���� ���� ó�� (�˻�, ����, ���� ��)
	//�����Է��� ���� �Ϳ� ���� ó��
	//ȸ������ ó��(���� person�� �Է¹��� �� ����)
};

int main() {
	Controller appControl;
	while (1) {
		appControl.run();
	}
	return 0;
}