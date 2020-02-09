#include "Beauty.h"

ostream& operator<<(ostream& os, const Beauty& beauty)
{
	os << "美女的姓名为:" << beauty.name 
	   << ",年龄为:" << beauty.age << endl;
	return os;
}