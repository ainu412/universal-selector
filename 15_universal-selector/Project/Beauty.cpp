#include "Beauty.h"

ostream& operator<<(ostream& os, const Beauty& beauty)
{
	os << "��Ů������Ϊ:" << beauty.name 
	   << ",����Ϊ:" << beauty.age << endl;
	return os;
}