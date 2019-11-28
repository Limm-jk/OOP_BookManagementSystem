#include "View.cpp"
#include "Model.cpp"
#include "Object.cpp"
#include <stdlib.h>

class Controller {
private:
	View view;
	Model model;
	std::string SUPERUSER = "admin";
	bool testtrue = true; // ä���� bool����

	//�α���
	std::string returnid;
	std::string returnpasswd;
	person handler;
	int scanSignal;//��ȣ�Է½� ��ȣ���� ����

	//�˻� �Է¹��� å �̸�
	std::string returntitle;

	//�����ݳ�
	int returnBookNumber;

	//ȸ���߰�
	std::string name;
	std::string id;
	std::string passwd;

	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

	//ȸ�� ����
	std::string delId;

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

public:
	void run() {

		system("cls");
		while (1) {
			bool login = view.initScreen(returnid, returnpasswd);	//�ʱ�ȭ��
			//ȸ�� ��ȿ �� �����Ͱ��� Ȯ��
			if (!login) {
				//��ȿ���� ���� ���� while�� �����
				continue;
			}
			//ȸ�������϶�
			if (testtrue) {
				while (1) {
					view.userPage(scanSignal);//�ñ׳� Ȯ��
					while (scanSignal != 0) {
						if (scanSignal == 1) {
							view.searchBook(returntitle);//å�̸� �Է�
							//�˻��޼ҵ�
						}
						else if (scanSignal == 2) {
							view.returnBook(handler, returnBookNumber);
							//�ݳ��޼ҵ�
						}
						else if (scanSignal == 0) {
							//����&�α׾ƿ�
						}
						else {
							//�߸��� �Է�
						}
					}
				}
			}
			if (returnid == SUPERUSER) {
				while (scanSignal != 0) {
					view.managePage(scanSignal);
					if (scanSignal == 1) {
						//��������
						while (scanSignal != 0) {
							//scanSignal�޴� view�Լ�
							if (scanSignal == 1) {
								view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
								//�𵨿� addbook
								//bookInsert(addbookTitle, addauthor, addpublisher, addbookNumber);
							}
							else if (scanSignal == 2) {
								//����? view.delBook(delBookNumber);
								//model.bookDelete(delBookNumber);
							}
							else if (scanSignal == 0) {
								//�����մϴ�
							}
							else {
								//�߸��� �Է�
							}
						}
					}
					if (scanSignal == 2) {
						//ȸ������
						while (scanSignal != 0) {
							//scanSignal�޴� view�Լ�
							if (scanSignal == 1) {
								//ȸ�� �߰�.
								view.addPerson(name, id, passwd);
								//�𵨿� addbook
								//addPerson(name, id, passwd);
							}
							else if (scanSignal == 2) {
								//ȸ������? view.delPerson(delId);
								//model.personDelete(delId);
							}
							else if (scanSignal == 0) {
								//�����մϴ�
							}
							else {
								//�߸��� �Է�
							}
						}
					}
					else if (scanSignal == 0) {
						//���� �α׾ƿ�
					}
					else {
						//�߸��� �Է�
					}
				}
			}
		}
	}
	Controller() {

	}
};

int main() {
	Controller appControl;
	while (1) {
		appControl.run();
	}
	return 0;
}