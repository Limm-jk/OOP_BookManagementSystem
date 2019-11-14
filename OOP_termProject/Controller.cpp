#include "View.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {

	View view;
	int initScreenInput = 0;

	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//���� id, title
	std::string loanId;
	std::string bookTitle;
	//�ݳ� id, title
	std::string returnId;
	std::string returnTitle;

	//ȸ���߰�
	std::string name;
	std::string id;
	std::string passwd;

	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

	//���� �߰�
	std::string addbookTitle;
	std::string addauthor;
	std::string addpublisher;
	int addbookNumber;
	//������
	bool addloan;

	//���� ����
	int delBookNumber;

	//���� �˻�
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
				//view.addBook(addBookTitle, addAuthor, addDate, addBookNumber);
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