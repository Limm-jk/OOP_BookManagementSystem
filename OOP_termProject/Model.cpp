#include<list>
#include"Object.cpp"
//�ٲ�
class Model {
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//���ͷ�����
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();


public:
	void dataInit() {
		//������������� booklist�� ������ å�����͸� Ǫ��(�ʱ����� 1���� ����)
		//������������� personlist�� ������ ��������͸� Ǫ��(�ʱ����� 1���� ����)
	}

	//�α��� check
	bool loginCheck(std::string id, std::string passwd) {
		//�ش��ϴ� id�� passwd�� ��ġ�ϸ� true����
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id && (*itr).getPasswd() == passwd) {
				return true;
			}
		}

		//id�� passwd �� �� �ϳ��� Ʋ���� false����
		return false;
	}


	//book �߰�
	bool bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		//����ó���� bookNumber�� ���� ���� �ִ��� Ȯ��
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			if ((*itr).getBookNumber() == addbookNumber) {
				return false;
			}
		}

		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
		
		return true;
	}

	//person �߰�
	bool addPerson(std::string& name, std::string& id, std::string& passwd) {
		//����ó���� id�� ���� ���� �ִ��� Ȯ��
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				return false;
			}
		}

		person newPerson(name, id, passwd);
		personlist.push_back(newPerson);

		return true;
	}


	//book �˻�
	std::list<Book> bookSearch(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = booklist.begin(); iterPos != booklist.end(); ++iterPos)
		{
			if ((*iterPos).getBookNumber() == givenBookNumber) {//�־��� �Ͱ� ���� å��ȣ�� ���� ��ü�� ����ų �� �۵�
				Book abook((*iterPos).getBookTitle, (*iterPos).getAuthor, (*iterPos).getPublisher, (*iterPos).getBookNumber);//����Ű�� ��ü�� ����
				abook.setLoan((*iterPos).getLoan);
				aList.push_back(abook);//��ȯ�� ����Ʈ�� �ٿ��ֱ�
			}
		}
		return aList;//����Ʈ ��ȯ
	}

	/*
	std::list<Book> bookSearch(std::string title  ) {

		bklistItr = booklist.begin();//�ʱ�ȭ
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle() == title) {
				return true;
			}
			++bklistItr;
		}
		bklistItr = booklist.begin();//ã�µ� ���� �ÿ� �ʱ�ȭ �� ����
		return false;
	}
	*/

	bool bookSearchNum(int bookNum) {
		bklistItr = booklist.begin();

	}

	bool bookDelete(int bookNumber) {
		if (bookSearchNum(bookNumber)) {
			booklist.erase(bklistItr);
			return true;
		}
		return false;
	}
	
	bool bookLoan(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 
		while (bklistItr != booklist.end()) { 
			if ((*bklistItr).getBookNumber() == bookNumber) { // å�� �ִ��� Ȯ��
				while (pslistItr != personlist.end()) { 
					if ((*pslistItr).getId == id) { // id ���� ��� ã�� 
						int num = (*pslistItr).getLoanNumber;
						std::string settitle = std::to_string(bookNumber);
						// �Ǽ��� 1,2�϶��� loanbook�� ���°���� �𸥴�.
						if (num == 0) { // å�� ������ �ʾ��� ��
							(*bklistItr).setLoan(true);
							(*pslistItr).setLoanNumber(1);
							(*pslistItr).setLoanBook1(settitle);
							return true;
						}
						else if (num == 1) { // �ѱ� ������ �� 
							// ���� ���ȴ��� Ȯ�� 
							if ((*pslistItr).getLoanBook1 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
						}
						else if (num == 2) { // �α� ������ ��
							// ���� �Ⱥ��ȴ��� Ȯ�� 
							if ((*pslistItr).getLoanBook1 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook3(settitle);
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}

	// �ݳ�
	bool bookReturn(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 

		while (bklistItr != booklist.end())
		{
			if ((*bklistItr).getBookNumber == bookNumber) { 
				if ((*bklistItr).getLoan == true) { // å�� ���� �������� Ȯ�� 
					std::string gettitle = std::to_string(bookNumber);
					while (pslistItr != personlist.end())
					{
						if ((*pslistItr).getId == id) { // ���̵� Ȯ�� 
							int num = (*pslistItr).getLoanNumber(); // ���� �Ǽ� Ȯ�� 
							if (num == 1) {
								if ((*pslistItr).getLoanBook1 == gettitle) { // �ݳ��� å�� ������ å�� ��ġ�ϴ��� Ȯ�� 
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 0;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
							else if (num == 2) {
								if ((*pslistItr).getLoanBook1 == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 1;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook2 == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber = 1;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
							else if (num == 3) {
								if ((*pslistItr).getLoanBook1 == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook2 == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook3 == gettitle) {
									(*pslistItr).setLoanBook3(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
						}
					}
				
				}
			}
		}
		return false;
	}

	//person ����
	bool personDelete(std::string id) {
		
		//id �˻�
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				personlist.erase(itr);
				return true;
			}
		}

		//ã�� id�� ������ false����
		return false;
	}



	//���� ������Ʈ
};
