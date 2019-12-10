#include "View.cpp"
#include "Object.cpp"
#include "Model.cpp"
#include <stdlib.h>
#include <windows.h>

class Controller {
private:
	View view;
	Model model;
	std::string SUPERUSER = "admin";
	std::string SUPERUSERPW = "admin";
	bool testtrue = true; // ä���� bool����

	//�α���
	std::string returnid;
	std::string returnpasswd;
	person handler;
	int scanSignal = 1;//��ȣ�Է½� ��ȣ���� ����

	//�˻�/���� �Է¹��� å �̸�
	std::string returntitle;
	int loanNumber;

	//�����ݳ�
	int returnBookNumber;

	//ȸ���߰�
	std::string name;
	std::string id;
	std::string passwd;

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
	std::list<Book> searchBooklist;

public:
	void run() {
		model.fileRead();
		
		while (1) {
			system("cls");
			scanSignal = 1;
			view.initScreen(returnid, returnpasswd);	//�ʱ�ȭ��
			bool login = model.loginCheck(returnid, returnpasswd);

			//�����ڰ����϶�
			if (returnid == "admin" && returnpasswd == "admin") {
				while (1) {
					system("cls");
					view.managePage(scanSignal);//1���� 2ȸ��
					if (scanSignal == 1) {
						//��������
						while (1) {
							system("cls");
							view.manageBook(scanSignal);
							if (scanSignal == 1) {
								//å�߰�
								system("cls");
								view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
								//�𵨿� addbook
								if (model.bookInsert(addbookTitle, addauthor, addpublisher, addbookNumber)) {
									model.fileWrite();
									model.fileRead();
									view.success();
								}
								else {
									view.fail();
								}
							}
							else if (scanSignal == 2) {
								view.deleteBook(delBookNumber);
								if (model.bookDelete(delBookNumber)) {
									model.fileWrite();
									model.fileRead();
									view.success();
								}
								else {
									view.fail();
								}
							}
							else if (scanSignal == 0) {
								//�����մϴ�
								break;
							}
							else {
								//�߸��� �Է�
								view.faultPage();
							}
						}
					}
					else if (scanSignal == 2) {

						//ȸ������
						while (1) {
							system("cls");
							view.managePerson(scanSignal);
							if (scanSignal == 1) {
								//ȸ�� �߰�.
								system("cls");
								view.addPerson(name, id, passwd);
								//�𵨿� addbook
								if (model.addPerson(name, id, passwd)) {
									model.fileWrite();
									model.fileRead();
									view.success();
								}
								else {
									view.fail();
								}
							}
							else if (scanSignal == 2) {
								system("cls");
								view.deletePerson(delId);
								if (model.personDelete(delId)) {
									model.fileWrite();
									model.fileRead();
									view.success();
								}
								else {
									view.fail();
								}
							}
							else if (scanSignal == 0) {
								//�����մϴ�
								break;
							}
							else {
								//�߸��� �Է�
								view.faultPage();
							}
						}
					}
					else if (scanSignal == 0) {
						//���� �α׾ƿ�
						break;
					}
					else {
						//�߸��� �Է�
						view.faultPage();
					}
				}
			}

			//------------�� ������ ����-------------

			else {
				if (!login) {
					continue;
				}
				while (1) {
					system("cls");
					view.userPage(scanSignal);//�ñ׳� Ȯ�� 1�˻����� 2 �ݳ�
					if (scanSignal == 1) {
						system("cls");
						view.searchBook(returntitle);//å�̸� �Է�
						searchBooklist = model.bookSearchByTitle(returntitle);
						view.loanBook(searchBooklist, loanNumber);
						if (model.bookLoan(returnid, loanNumber)) {
							//����
							view.success();
							model.fileWrite();
							model.fileRead();
						}
						else {
							//å����

							view.fail();
						}
					}
					else if (scanSignal == 2) {
						system("cls");
						view.returnBook(model.idToPerson(returnid), returnBookNumber);
						if (model.bookReturn(returnid, returnBookNumber)) {
							//����
							view.success();
							model.fileWrite();
							model.fileRead();
						}
						else {
							//å����
							view.fail();
						}
						//�ݳ��޼ҵ�
					}
					else if (scanSignal == 0) {
						//����&�α׾ƿ�
						break;
					}
					else {
						//�߸��� �Է�
						view.faultPage();
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