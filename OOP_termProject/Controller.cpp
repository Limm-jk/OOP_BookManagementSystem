#include "View.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {

	View view;
	std::string SUPERUSER = "admin";
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//�α���
	std::string returnid;
	std::string returnpasswd;

	//�˻� å �̸�
	std::string returntitle;
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
		view.initScreen(returnid, returnpasswd);	//�ʱ�ȭ��
		//ȸ�� ��ȿ �� �����Ͱ��� Ȯ��

		//ȸ�������϶�
		int i = view.userPage();
		while (i != 0) {
			if (i == 1) {
				view.searchBook(returntitle);
				//�˻��޼ҵ�
			}
			if (i == 2) {
				//�ݳ��޼ҵ�
			}

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