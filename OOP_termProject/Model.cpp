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

	//book ����, �˻�, ����
	void bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
	}

	std::list<Book> bookSearch(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = bookList.begin(); iterPos != bookList.end(); ++iterPos)
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
		bklistItr = booklist.begin();
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookNumber() == bookNumber) {
				(*bklistItr).setLoan(true);
				return true;
			}
		}

		return false;
	}

	// �ݳ�
	bool bookReturn(std::string id, int bookNumber) {

	}

	//person ����, �˻�, ����



	//���� ������Ʈ
};
