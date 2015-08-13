#include "stdafx.h"

//Given a string and an offset, rotate string by offset. (rotate from left to right)
//
//Example
//Given "abcdefg".
//
//offset = 0 = > "abcdefg"
//offset = 1 = > "gabcdef"
//offset = 2 = > "fgabcde"
//offset = 3 = > "efgabcd"
//Challenge
//Rotate in - place with O(1) extra memory.
//

namespace LintSolution1
{
    namespace RotateString_Easy
    {
     
		/**
		* @param str: a string
		* @param offset: an integer
		* @return: nothing
		*/
		void rotateString(string &str, int offset){
			int len = str.length();
			if (len < 2) { return; }
			offset = len - offset % len;

			reverse(str.begin(), str.begin() + offset);
			reverse(str.begin() + offset, str.end());
			reverse(str.begin(), str.end());
		}
     
        void Main()
        {
			string input = "";
			rotateString(input, 10);

			input = "abcdefg";
			rotateString(input, 3);

			print(input);
        }
    }
}
   
    