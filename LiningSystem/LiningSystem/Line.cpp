#include "stdafx.h"
#include "Line.h"
#include <queue>
#include "UserInformation.h"
#include <string>
using namespace std;

Line::Line()
{
}


Line::~Line()
{
}

string Line::quhao(char department)
{
	UserInformation newone;
	newone.departmentSign = department;
	switch (department)
	{
	case 'a':
		if (aDepartment.empty())
		{
			aWaitNo = 0;
		}
		newone.waitNumber = ++aWaitNo; aDepartment.push(newone);
		aDepartmentWaitingList += (CString)((department + to_string(aWaitNo) + '\r' + '\n').c_str()); break;
	case 'b':
		if (bDepartment.empty())
		{
			bWaitNo = 0;
		}
		newone.waitNumber = ++bWaitNo; bDepartment.push(newone);
		bDepartmentWaitingList += (CString)((department + to_string(bWaitNo) + '\r' + '\n').c_str()) ; break;
	case 'c':
		if (cDepartment.empty())
		{
			cWaitNo = 0;
		}
		newone.waitNumber = ++cWaitNo; cDepartment.push(newone);
		cDepartmentWaitingList += (CString)((department + to_string(cWaitNo) + '\r' + '\n').c_str()) ; break;
	}
	return "1";
}

string Line::jiaohao(char department)
{
	switch (department)
	{
	case 'a':
		if (!aDepartment.empty())
		{
			aDepartmentCalling = (CString)((department + to_string(aDepartment.front().waitNumber)).c_str()); aDepartmentWaitingList.Replace(aDepartmentCalling + _T("\r") + _T("\n"), _T(""));
			aDepartment.pop();
		}
		else
		{
			aDepartmentCalling = _T("нч");
		}
		break;
	case 'b':
		if (!bDepartment.empty())
		{
			bDepartmentCalling = (CString)((department + to_string(bDepartment.front().waitNumber)).c_str()); bDepartmentWaitingList.Replace(bDepartmentCalling + _T("\r") + _T("\n"), _T(""));
			bDepartment.pop();
		}
		else
		{
			bDepartmentCalling = _T("нч");
		}
		break;
	case 'c':
		if (!cDepartment.empty())
		{
			cDepartmentCalling = (CString)((department + to_string(cDepartment.front().waitNumber)).c_str()); cDepartmentWaitingList.Replace(cDepartmentCalling + _T("\r") + _T("\n"), _T(""));
			cDepartment.pop();
		}
		else
		{
			cDepartmentCalling = _T("нч");
		}
		break;
	}
	return "1";
}
