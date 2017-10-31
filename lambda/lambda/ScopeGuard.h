/*
ʹ��C++11��lambdaʵ����Դ���ͷţ���ֹ��Դй¶
ʹ�÷�ʽ������Դ����֮������������
NS_SCOPE_GUARD::ON_SCOPE_EXIT([&] {�ͷ���Դ});
*/
#pragma once

#include <functional>

namespace NS_SCOPE_GUARD {

	class ScopeGuard
	{
	public:
		typedef std::function<void()> Function;
	public:
		explicit ScopeGuard(Function onExitFunc)
			: _onExitFunc(onExitFunc), _dismissed(false)
		{

		}
		~ScopeGuard()
		{
			if (!_dismissed)
			{
				_onExitFunc();
			}
		}

		// ĳ������·�����Դ�ͷ�
		void dismiss(void)
		{
			_dismissed = true;
		}
	private:
		Function _onExitFunc;
		bool _dismissed;

	private:
		ScopeGuard(const ScopeGuard&);
		ScopeGuard& operator=(const ScopeGuard&);
	};

#define SCOPE_LOCAL_NAME_CAT(name,line) name##line
#define SCOPE_LOCAL_NAME(name,line) SCOPE_LOCAL_NAME_CAT(name,line)
#define ON_SCOPE_EXIT(func) ScopeGuard SCOPE_LOCAL_NAME(sg,__LINE__)(func)

};
