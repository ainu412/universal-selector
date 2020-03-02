#include <iostream>
#include <set>
using namespace std;

template <class _Ty, class _Container = set<_Ty>>
class setComparer
{
public:
	typedef setComparer<_Ty, _Container> t;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;
	//Ĭ��set����
	setComparer() :c() {};
	//ָ��������Ԫ�ع���
	setComparer(const t& ty) :c(ty) {};
	//ָ����������
	setComparer(const _Container _Cont) :c(_Cont) {};
	//��ֵ���������
	t& operator=(const setComparer& other)
	{
		c = other.c;
		return *this;
	}
	//����Ԫ��
	bool insert(const value_type& ty)
	{
		typename _Container::iterator it = c.insert(c.begin(), ty);
		if (it != c.end())
		{
			cout << "����" << ty << "�ɹ�!" << endl;
			return true;
		}
		return false;
	}
	//ɾ��Ԫ��
	bool erase(const value_type& ty)
	{
		if (c.erase(ty) > 0)
		{
			return true;
		}
		return false;
	}
	//ȡ�����ֵ
	pair<value_type, bool> getMax() const
	{
		pair<value_type, bool> ret;
		if (c.size() > 0)
		{
			ret.first = *(--c.end());
			ret.second = true;
		}
		else 
		{
			ret.second = false;
		}		
		return ret;
	}
	//ȡ����Сֵ
	pair<value_type, bool> getMin() const
	{
		pair<value_type, bool> ret;
		if (c.begin() == c.end())
		{
			ret.second = false;
		}
		else
		{
			ret.first = *c.begin();
			ret.second = true;
		}
		return ret;
	}
	bool empty() const
	{
		return c.empty();
	}
	size_type size() const 
	{
		return c.size();
	}
protected:
	_Container c;
};