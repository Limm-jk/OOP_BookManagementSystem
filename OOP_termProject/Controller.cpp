#include "View.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {

	View view;

	std::string SUPERUSER = "admin";
	std::string SUPERUSERPW;
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//�α���(�ʱ�ȭ��)
	std::string returnid;
	std::string returnpasswd;

	int scanSignal;//��ȣ�Է½� ��ȣ���� ����

	//�˻� �Է¹��� å �̸�
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
		view.userPage(scanSignal);//�ñ׳� Ȯ��
		while (scanSignal != 0) {
			if (scanSignal == 1) {
				view.searchBook(returntitle);//å�̸� �Է�
				//�˻��޼ҵ�
			}
			if (scanSignal == 2) {
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