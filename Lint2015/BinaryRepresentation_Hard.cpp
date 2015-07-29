#include "stdafx.h"

//Given a(decimal - e.g. 3.72) number that is passed in as a string, return the binary 
//representation that is passed in as a string.If the fractional part of the number can 
//not be represented accurately in binary with at most 32 characters, return ERROR.
//
//
//Example
//For n = "3.72", return "ERROR".
//
//For n = "3.5", return "11.1".

namespace LintSolution1
{
    namespace BinaryRepresentation_Hard
    {
		int stringToInt(string s)
		{
			int result = 0;
			for (char c : s)
			{
				result = result * 10 + c - '0';
			}
			return result;
		}

		string binaryRepresentation(string s) {
			int len = s.size();
			int start = 0;
			bool isNeg = s[0] == '-';
			if (isNeg) { start++; }

			int cur = start+1;
			while (cur < len && s[cur] != '.') { cur++; }
			cur--;

			string before = s.substr(start, cur - start + 1);
			string after = s.substr(cur+2);

			string r1;
			if (before.size() > 0)
			{
				int val = stringToInt(before);
				while (val)
				{
					r1 = to_string(val % 2) + r1;
					val /= 2;
				}
			}

			string r2;
			if (after.size() > 0)
			{
				double val = stringToInt(after);
				for (int i = 0; i < after.size(); i++)
				{
					val /= 10;
				}
				int i = 0; 
				while (val)
				{
					r2 += (val * 2) >= 1 ? "1" : "0";
					val = val * 2 - 1;
					i++;
					if (i == 32) { return "ERROR"; }
				}
			}
			if (r1.empty()) { r1 == "0"; }
			if (r2.empty()) { r2 == "0"; }
			return r1 + "." + r2;
		}

        void Main()
        {
			print(binaryRepresentation("3.5"));
			print(binaryRepresentation("3.72"));
        }
    }
}
   
    