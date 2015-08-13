#include "stdafx.h"

//Write a method to replace all spaces in a string with %20. The string is given 
//in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.
//
//Example
//Given "Mr John Smith", length = 13.
//
//The string after replacement should be "Mr%20John%20Smith".
//
//Note
//If you are using Java or Python，please use characters array instead of string.
//
//Challenge
//Do it in - place.

namespace LintSolution1
{
	namespace SpaceReplacement_Easy
	{
		/**
		* @param string: An array of Char
		* @param length: The true length of the string
		* @return: The true length of new string
		*/
		int replaceBlank(char str[], int len) {
			if (len <= 0) { return 0; }

			int spaceCount = 0;
			for (int i = 0; i < len; i++)
			{
				if (str[i] == ' ') { spaceCount++; }
			}

			int newLen = len + spaceCount*2;

			int store = newLen - 1;
			int cur = len - 1;
			while (cur >= 0)
			{
				if (str[cur] != ' ') { str[store--] = str[cur]; }
				else
				{
					str[store--] = '0';
					str[store--] = '2';
					str[store--] = '%';
				}
				cur--;
			}
			return newLen;
		}

		void Main()
		{
			char input[] = "Mr John Smith";

 		}
	}
}

