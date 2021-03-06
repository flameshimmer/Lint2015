#include "stdafx.h"

//Implement an assignment operator overloading method.
//
//Make sure that :
//
//The new data can be copied correctly
//The old data can be deleted / free correctly.
//We can assign like A = B = C
//Have you met this question in a real interview ? Yes
//Example
//If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B.
//If we assign like A = B = C, both A and B should have a copy of data from C.
//
//Challenge
//Consider about the safety issue if you can and make sure you released the old data.
//
//Clarification
//This problem is for C++ only as Java and Python don't have overloading for assignment operator.

namespace LintSolution1
{
    namespace AssignmentOperatorOverloadingCPlusPlusOnly_Medium
    {
		//class Solution
		//{
		//public:
		//	char* m_data;
		//	Solution() : m_data(NULL) {}
		//	Solution(char* data)
		//	{
		//		m_data = data;
		//	}

		//	Solution operator=(const Solution& obj)
		//	{
		//		if (this == &obj) { return *this; }
		//		if (m_data)
		//		{
		//			delete[] m_data;
		//			m_data = NULL;
		//		}

		//		if (obj.m_data)
		//		{
		//			m_data = new char[strlen(obj.m_data) + 1];
		//			strcpy(m_data, obj.m_data);
		//		}
		//		return *this;
		//	}
		//};
     
        void Main()
        {
         
        }
    }
}
   
    