#include<iostream>


class View {

public:
	//�ʱ� UI�� �����ִ� �޼ҵ�
	void login(std::string& returnId, std::string& returnpw) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-- ���� ���� �ý����Դϴ�.--" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "ID�� �Է��� �ּ��� : ";
		std::cin >> returnId;
		std::cout << "Password�� �Է����ּ��� : ";
		std::cin >> returnpw;
	}

	int initScreen() {
		int input;

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� �ݳ�, ����, ��ȸ" << std::endl;
		std::cout << "2. ���� ����" << std::endl;
		std::cout << "3. ȸ�� ����" << std::endl;
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
	int LoanReturn() {
		int input = 0;

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� ����" << std::endl;
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

		return input;
	}

	void loanBook(std::string& loanId, std::string& bookTitle) {

		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. ���� ������ �����ϼ̽��ϴ�." << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "ID�� �Է��� �ּ��� : ";
		std::cin >> loanId;
		std::cout << "������ å �̸��� �Է����ּ��� : ";
		std::cin >> bookTitle;

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

		std::cout << "ID�� �Է��� �ּ��� : ";
		std::cin >> returnId;
		std::cout << "�ݳ��� å �̸��� �Է����ּ��� : ";
		std::cin >> returnTitle;
	}

	void inputError() {
		std::cout << "\n\n\n �߸��� �Է��Դϴ�. \n\n\n" <<std::endl;
	}
};