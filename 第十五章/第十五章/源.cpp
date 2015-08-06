#include<iostream>
#include<string>
using namespace std;

class quote
{
public:
	quote() = default;  //Ĭ�Ϲ��캯��
	quote(const string s, double val) : bookNo(s), price(val){}
	string isbn() const { return bookNo;}     //��������,���ذ汾��
	virtual double net_price(size_t n) const  //�����������麯�������ظ����������鼮�������ܶ�  //�����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
	{
		return n*price;
	}
	virtual ~quote() = default;   //�������������ж�̬��
private:
	string bookNo;        //�鼮��ISBN���
protected:
	double price = 0.0;   //������ͨ״̬�µĲ����۵ļ۸�
};

class Bulk_quote : public quote  //Bulk_quote�̳���Quote
{   
public:
	Bulk_quote() = default;  
	Bulk_quote(const string& s,double,size_t,double);
	//���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
	double net_price(size_t) const override;
private:
	size_t min_qty = 0;      //�����ۿ����ߵ���͹�����
	double discount = 0.0;   //��С����ʾ���ۿ۶�
};

//���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total(ostream &os, const quote &item, size_t n)
{
	//���ݴ���item�βεĶ������͵���Quote::net_price
	//����Bult_quote::net_price
	double ret = item.net_price(n);
	//����Quote:isbn
	os << "ISBN: "<< item.isbn()  << " # sold: " << n << " total due: "<< ret <<endl;
}

int main()
{
	//15.1 ʲô�����Ա������ĳЩ����������ϣ��������������Զ����ʺ�����İ汾����ʱ����ͽ���Щ�����������麯��
	//�����б�����Ϊvirtual�ĳ�Ա������ϣ�����ֳ�Ա�����������ض��塣���˹��캯���⣬�����static��Ա������Ϊ���Ա

	//15.2 protected����˵������private�к����������಻�ܷ���˽�г�Ա�������ܷ����ܱ�����Ա���ܱ�����Աͬʱ����ֹ�����û�����
	/*protectedΪ�ܱ����ķ��ʱ�ţ�protected��Ա���Ա�����ĳ�Ա����Ԫ���������Ա������Ԫ�����ʣ��������Ա������͵���ͨ�û����ʡ�
	  ��private��Ա��ֻ�ܱ�����ĳ�Ա����Ԫ���ʣ������಻�ܷ���*/


	system("pause");
	return 0;
}