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
