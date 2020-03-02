#include "setComparer.hpp"

int main()
{



	setComparer<int> setInt;

	for (size_t i = 0; i < 10; i++)
	{
		setInt.insert(100 - 10 * i);
	}
	cout << setInt.size() << endl;
	setInt.erase(10);
	cout << "Max=";
	pair<int, bool> ret = setInt.getMax();
	if (ret.second)
	{
		cout << ret.first;
	}
	cout << "Min=";
	ret = setInt.getMin();
	if (ret.second)
	{
		cout << ret.first;
	}
	return 0;
}