// lambda.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ScopeGuard.h"
#include <memory>
#include <iostream>

int main()
{
	FILE* fp = nullptr;
	int res = fopen_s(&fp, "aa.txt", "wb");
	if (res < 0)
	{
		return -1;
	}

	NS_SCOPE_GUARD::ON_SCOPE_EXIT([&] {if (nullptr != fp) { fclose(fp); }});
    
	return 0;
}

