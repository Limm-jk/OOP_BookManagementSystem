#include<iostream>
#include<list>
#include"Object.cpp"

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
	int userPage() {
		int input = 0;

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
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cin >> input;
		//����ó�� �ʿ�
		return input;
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
	}

	void loanBook(std::list<Book> searchBooklist, int& bookNumber) {
		std::list<Book>::iterator list = searchBooklist.begin();
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "������ȣ    ����      ����   ���ǻ�      ���⿩��" << std::endl;

		while (list != searchBooklist.end()) {
			std::cout << (*list).getbookNumber();
			std::cout << "	";
			std::cout << (*list).getBookTitle();
			std::cout << "	";
			std::cout << (*list).getAuthor();
			std::cout << "	";
			std::cout << (*list).getPublisher();
			std::cout << "	";
			std::cout << (*list).getLoan() << std::endl;
			std::cout << "" << std::endl;
		}
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		
		std::cout << "������ å�� ������ȣ�� �Է��� �ּ��� : ";
		std::cin >> bookNumber;
	}

	void returnBook(std::string& returnId, std::string& returnTitle) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "2. ���� �ݳ��� �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "�ݳ��� å �̸��� �Է����ּ��� : ";
		std::cin >> returnTitle;
	}

	int manageBook() {
		int input;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �߰�" << std::endl;
		std::cout << "2. ���� ����" << std::endl;
		std::cout << "3. ���� �˻�" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		
		std::cin >> input;
		return input;
	}

	void addBook(std::string& bookTitle, std::string& author, std::string& date, int& bookNumber) {

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

		std::cout << "å�� ������ �Է��� �ּ��� : ";
		std::cin >> bookTitle;
		std::cout << "å�� ���ڸ� �Է��� �ּ��� : ";
		std::cin >> author;
		std::cout << "å�� ������� �Է��� �ּ���(yyyy-mm-dd) : ";
		std::cin >> date;
		std::cout << "å�� ���� ��ȣ�� �Է��� �ּ��� : ";
		std::cin >> bookNumber;
	}

	void deleteBook(int& bookNum) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;+
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



		std::cout << "2. ���� ������ �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "������ ������ ������ȣ�� �Է��� �ּ��� : ";
		std::cin >> bookNum;
	}

	void searchBook(std::string& bookTitle) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "3. ���� �˻��� �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "�˻��� ������ ������ �Է��� �ּ��� : ";
		std::cin >> bookTitle;
	}
};