#include "CSGuard.h"

void CSGuard::enterSection()
{
	if (!this->in_)
	{
		EnterCriticalSection(criticalSectionPointer_);
		this->in_ = true;
	}
}

void CSGuard::leaveSection()
{
	if (this->in_)
	{
		LeaveCriticalSection(criticalSectionPointer_);
		this->in_ = false;
	}
}

CSGuard::CSGuard(LPCRITICAL_SECTION criticalSectionPointer) :
	criticalSectionPointer_(criticalSectionPointer), in_(false)
{
}

CSGuard::~CSGuard()
{
	if(this->in_)
		LeaveCriticalSection(criticalSectionPointer_);
}

