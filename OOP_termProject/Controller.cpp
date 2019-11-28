#include "View.cpp"
#include "Object.cpp"
#include "Model.cpp"
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
		while (1) {
			system("cls");
			view.initScreen(returnid, returnpasswd);	//�ʱ�ȭ��
			//bool login = model.loginCheck(returnid, returnpasswd);
//			if (!login) {
				//��ȿ���� ���� ���� while�� �����
//				continue;
//			}
			//�����ڰ����϶�
			if (returnid == "admin") {
				while (scanSignal != 0) {
					system("cls");
					view.managePage(scanSignal);//1���� 2ȸ��
					if (scanSignal == 1) {
						//��������
						while (scanSignal != 0) {
							system("cls");
							view.manageBook(scanSignal);
							if (scanSignal == 1) {
								//å�߰�
								system("cls");
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
							system("cls");
							view.managePerson(scanSignal);
							if (scanSignal == 1) {
								//ȸ�� �߰�.
								system("cls");
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

			else {
				while (scanSignal != 0) {
					system("cls");
					view.userPage(scanSignal);//�ñ׳� Ȯ�� 1�˻����� 2 �ݳ�
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
	}
	Controller() {

	}
};


int main() {
	Controller appc;
	while (1) {
		appc.run();
	}
	return 0;
};