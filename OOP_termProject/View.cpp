#include<iostream>
#include<list>
#include"Object.cpp"
#include <windows.h>

class View {

public:
	//�ʱ� UI�� �����ִ� �޼ҵ�
	//�� �޼ҵ忡�� �Է¹��� �� �Է¹޴� ���� ���� ����ó�� �ʿ�

	//�α��� ������
	void initScreen(std::string& Id, std::string& passwd) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "----------------------�α���---------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "ID : ";
		std::cin >> Id;
		std::cout << "Passwd : ";
		std::cin >> passwd;
	}

	//������ �α���
	void userPage(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �˻� / ����" << std::endl;
		std::cout << "2. ���� �ݳ�" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. �α��� �������� ���ư���" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
	}

	void searchBook(std::string& bookTitle) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �˻� / ������ �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "�˻��� å�� �Է��� �ּ��� : ";
		std::cin >> bookTitle;

		//return true;
	}

	void loanBook(std::list<Book> searchBooklist, int& bookNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "������ȣ    ����      ����   ���ǻ�      ���⿩��" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getBookNumber();
			std::cout << "	";
			std::cout << (*list).getBookTitle();
			std::cout << "	";
			std::cout << (*list).getAuthor();
			std::cout << "	";
			std::cout << (*list).getPublisher();
			std::cout << "	";
			std::cout << (*list).getLoan() << std::endl;
			std::cout << "" << std::endl;
			
			++list; //���ͷ����� ����
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "������ å�� ������ȣ�� �Է��� �ּ��� : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "������ å�� ������ȣ�� ���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}

		/*for (std::list<Book>::iterator test = searchBooklist.begin(); test != searchBooklist.end(); ++test) {
			if ((*test).getBookNumber() == bookNumber) {
				return true;
			}
		}
		return false;*/
	}

	void returnBook(person Person, int& bookNumber) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << Person.getLoanBook1() << "     " << Person.getLoanBook2() << "     " << Person.getLoanBook3() << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "�ݳ��� å�� ������ȣ�� �Է����ּ��� : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "�ݳ��� å�� ������ȣ�� ���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}

		//if (Person.getLoanBook1() != "") {
		//	int a = atoi(Person.getLoanBook1().c_str());
		//	if (a == bookNumber) {
		//		return true;
		//	}
		//}
		//if (Person.getLoanBook2() != "") {
		//	int b = atoi(Person.getLoanBook2().c_str());
		//	if (b == bookNumber) {
		//		return true;
		//	}
		//}
		//if (Person.getLoanBook3() != "") {
		//	int c = atoi(Person.getLoanBook3().c_str());
		//	if (c == bookNumber) {
		//		return true;
		//	}
		//}

		////�ݳ��� å�� ������ȣ�� �Է����� �ʾ��� �� false
		//return false;
	}

	void managePage(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� ����" << std::endl;
		std::cout << "2. ȸ�� ����" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. �α��� �������� ���ư��ϴ�." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;


		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}
	
	
	void manageBook(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �߰�" << std::endl;
		std::cout << "2. ���� ����" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. ���� �������� ���ư��ϴ�." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}

	void managePerson(int& input) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ȸ�� �߰�" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "0. ���� �������� ���ư��ϴ�." << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;


		while (1) {
			std::cin >> input;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*if (input == 1 || input == 2 || input == -1) {
			return true;
		}
		else {
			return false;
		}*/
	}


	void addBook(std::string& bookTitle, std::string& author, std::string& publisher, int& bookN) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �߰��� �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "�߰��� ������ ������ �Է��� �ּ��� : ";
		std::cin >> bookTitle;
		std::cout << "�߰��� ������ �۰��� �Է��� �ּ��� : ";
		std::cin >> author;
		std::cout << "�߰��� ������ ���ǻ縦 �Է��� �ּ��� : ";
		std::cin >> publisher;
		
		//���ڸ� �Է� ����ó��
		while(1){
			std::cout << "�߰��� ������ å��ȣ�� �Է��� �ּ��� : ";
			std::cin >> bookN;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "������ å ��ȣ�� ���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		/*
		if (bookTitle != "" && author != "" && publisher != "") {
			return true;
		}

		return false;*/
	}

	void addPerson(std::string& name, std::string& id, std::string& pwd) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ȸ�� �߰��� �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "�߰��� ȸ���� �̸��� �Է��� �ּ��� : ";
		std::cin >> name;
		std::cout << "�߰��� ȸ���� ID�� �Է��� �ּ��� : ";
		std::cin >> id;
		std::cout << "�߰��� ȸ���� ��й�ȣ�� �Է��� �ּ��� : ";
		std::cin >> pwd;

		/*if (name != "" && id != "" && pwd != "") {
			return true;
		}
		else {
			return false;
		}*/
	}

	void returnBook(std::list<Book> searchBooklist, int& returnNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "������ȣ     ����      ����      ���ǻ�     ���⿩��" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getBookNumber();
			std::cout << "           ";
			std::cout << (*list).getBookTitle();
			std::cout << "	      ";
			std::cout << (*list).getAuthor();
			std::cout << "	      ";
			std::cout << (*list).getPublisher();
			std::cout << "	      ";
			if ((*list).getLoan() == true) {
				std::cout << "���Ⱑ��" << std::endl;
			}
			else {
				std::cout << "����Ұ�" << std::endl;
			}
			std::cout << "" << std::endl;
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "�ݳ��� å�� ������ȣ�� �Է����ּ��� : ";
			std::cin >> returnNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "�ݳ��� å�� ������ȣ�� ���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		
		/*for (std::list<Book>::iterator test = searchBooklist.begin(); test != searchBooklist.end(); ++test) {
			if ((*test).getBookNumber() == returnNumber) {
				return true;
			}
		}
		return false;*/
		
	}

	void deletePerson(std::string& deleteId) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. ȸ�� ������ �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "������ ȸ���� id�� �Է��� �ּ��� :";
		std::cin >> deleteId;

		//return true;
	}
	
	void deleteBook(int bookNumber) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. ���� ������ �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		while (1) {
			std::cout << "������ å�� ������ȣ�� �Է����ּ��� : ";
			std::cin >> bookNumber;
			if (std::cin) {
				break;
			}
			if (!std::cin) {
				std::cout << "������ å�� ������ȣ�� ���ڸ� �Է��� �ּ���" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
	}

	void faultPage() {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		Sleep(1000);
	}
};
