#pragma once
class Objects
{
	virtual void add() = 0;		//����Ʈ�� ��ü �߰�. person�� ID�� �ߺ��Ǵ��� üũ�ϰ� ����ó�� or �ڵ����� ID �ο�(�����صθ� �˻����� �ӵ��̵�)
	virtual void modify() = 0;	//��ü��������
	virtual void del() = 0;		//����Ʈ���� ��ü ���� ��ũ �̾���̱�
	virtual void search() = 0;	//person�� ID��(�̸��ߺ��� ���� �Ұ�)
								//�����˻��� �ش� �ܾ �߰��� �ѹ��� �� �־ �˻��� �ɷ�����
								//�Ѵ� list ���ϱ� apppView���� �ʿ��� Ŭ���� �����ؼ� ���� �����

	protected:
		Objects() {}//������
		~Objects() {}//�Ҹ���
};

