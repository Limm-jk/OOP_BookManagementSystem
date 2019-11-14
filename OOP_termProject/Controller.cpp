#include "View.cpp"
#include<stdlib.h>

class Controller {

	View view;
	int initScreenInput = 0;

	//���� id, title
	std::string loanId;
	std::string bookTitle;
	//�ݳ� id, title
	std::string returnId;
	std::string returnTitle;

	//���� �߰�
	std::string addBookTitle;
	std::string addAuthor;
	std::string addDate;
	int addBookNumber;

	//���� ����
	int delBookNumber;

	//���� �˻�
	std::string searchBookTitle;

public:
	void run() {

		system("cls");
		initScreenInput = view.initScreen();	//�ʱ�ȭ��
		if (initScreenInput == 1) {				//�ʱ�ȭ���� �Է°��� ��������,�ݳ� ����
			int LoanReturnInput = 0;			
			system("cls");
			LoanReturnInput = view.LoanReturn();	//���� ���� �ݳ� ȭ��
			if (LoanReturnInput == 1) {				//����
				system("cls");
				view.loanBook(loanId, bookTitle);
			}
			else if (LoanReturnInput == 2) {		//�ݳ�
				system("cls");
				view.returnBook(returnId, returnTitle);
			}
		
		}
		else if (initScreenInput == 2) {		//�ʱ� ȭ�鿡�� �������� ����
			system("cls");
			int manageBookInput = view.manageBook();	//���� ���� ȭ��
			if (manageBookInput == 1) {				//���� �߰�
				system("cls");
				view.addBook(addBookTitle, addAuthor, addDate, addBookNumber);
			}
			else if (manageBookInput == 2) {		//���� ����
				system("cls");
				view.deleteBook(delBookNumber);
			}
			else if (manageBookInput == 3) {		//���� �˻�
				system("cls");
				view.searchBook(searchBookTitle);
			}
		}
		else if (initScreenInput == 3) {		//�ʱ� ȭ�鿡�� ȸ������ ����

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