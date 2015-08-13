#include "stdafx.h"

//Given a string which contains only letters.Sort it by lower case first and upper case second.
//
//Example
//For "abAcD", a reasonable answer is "acbAD"
//
//Note
//It's not necessary to keep the original order of lower-case letters and upper case letters.
//
//Challenge
//Do it in one - pass and in - place.

namespace LintSolution1
{
    namespace SortLettersbyCase_Medium
    {
		bool isSmallerThan(char a, char b)
		{
			return islower(a) && !islower(b);
		}
		
		/**
		* @param chars: The letters array you should sort.
		*/
		void sortLetters(string &letters) {
			int len = letters.length();
			if (len < 2) { return; }

			int slow = 0;
			int fast = 0;
			while (fast < len)
			{
				if (isSmallerThan(letters[fast], 'A'))
				{
					swap(letters[slow], letters[fast]);
					slow++;
				}
				fast++;
			}
		}
     
        void Main()
        {
         
        }
    }
}
   
    