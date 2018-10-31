#include <iostream>
#include <queue>
#include <string>
#include "UserInformation.h"
using namespace std;

#pragma once
class Line
{
public:
	Line();
	~Line();
	int aWaitNo = 0;
	int bWaitNo = 0;
	int cWaitNo = 0;
	CString aDepartmentWaitingList = _T("");
	CString bDepartmentWaitingList = _T("");
	CString cDepartmentWaitingList = _T("");
	CString aDepartmentCalling;
	CString bDepartmentCalling;
	CString cDepartmentCalling;
	queue<UserInformation> aDepartment;
	queue<UserInformation> bDepartment;
	queue<UserInformation> cDepartment;
	string quhao(char department);
	string jiaohao(char department);
};

