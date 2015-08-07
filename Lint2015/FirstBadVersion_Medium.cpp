#include "stdafx.h"

//The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case,
//so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.
//
//You can call isBadVersion to help you determine which version is the first bad one.
//The details interface can be found in the code's annotation part.
//
//Example
//Given n = 5:
//
//isBadVersion(3) -> false
//isBadVersion(5) -> true
//isBadVersion(4) -> true
//Here we are 100% sure that the 4th version is the first bad version.
//
//Note
//Please read the annotation in code area to get the correct way to call isBadVersion in different language. 
//For example, Java is VersionControl.isBadVersion(v)
//
//Challenge
//You should call isBadVersion as few as possible.

namespace LintSolution1
{
    namespace FirstBadVersion_Medium
    {     

		//you can use VersionControl::isBadVersion(k) to judge whether
		//the kth code version is bad or not.
		class VersionControl {
		public:
			static bool isBadVersion(int k){ return true; }
		};

		/**
		* @param n: An integers.
		* @return: An integer which is the first bad version.
		*/
		int findFirstBadVersion(int n) {
			if (n <= 0) { return -1; }

			int start = 1;
			int end = n;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (VersionControl::isBadVersion(mid))
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return start;
		}

        void Main()
        {
         
        }
    }
}
   
    