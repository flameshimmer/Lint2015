#include "stdafx.h"

//Compare two strings A and B, determine whether A contains all of the characters in B.
//
//The characters in string A and B are all Upper Case letters.
//
//Example
//For A = "ABCD", B = "ACD", return true.
//
//For A = "ABCD", B = "AABC", return false.
//
//Note
//The characters of B in A are not necessary continuous or ordered.

namespace LintSolution1
{
    namespace CompareStrings_Easy
    {
     
		/**
		* @param A: A string includes Upper Case letters
		* @param B: A string includes Upper Case letter
		* @return:  if string A contains all of the characters in B return true
		*           else return false
		*/
		bool compareStrings(string A, string B) {
			unordered_map<char, int> map;
			for (char c : A)
			{
				map[c] ++;
			}

			for (char c : B)
			{
				if (map.find(c) == map.end() || map[c] == 0) { return false; }
				map[c]--;
			}
			return true;
		}
     
     
        void Main()
        {
         
        }
    }
}
   
    