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
		long long getVal(string s)
		{
			long long result = 0;
			for (char c : s)
			{
				result = result * 10 + c - '0';
			}
			return result;
		}

		string binaryRepresentation(string s) {
			int len = s.size();
			if (len == 0) { return ""; }

			int start = 0;
			int end = start + 1;
			while (end < len && s[end] != '.') { end++; }
			end--;

			string before = s.substr(start, end - start + 1);
			string after = s.substr(end + 2);

			string r1;
			if (!before.empty())
			{
				long long val = getVal(before);
				while (val)
				{
					r1 = to_string(val % 2) + r1;
					val /= 2;
				}
			}
			
			string r2;
			if (!after.empty())
			{
				double val = getVal(after);
				for (int i = 0; i < after.size(); i++) { val /= 10; }

				int i = 0;
				while (val)
				{
					if (val * 2 >= 1) { r2 += "1"; val = val * 2 - 1; }
					else { r2 += "0"; val = val * 2; }
					i++;
					if (i>32) { return "ERROR"; }
				}
			}

			string result = r1.empty() ? "0" : r1;
			if (!r2.empty()) { result += "." + r2; }
			return result;
		}

		void Main()
		{

			print(binaryRepresentation("4096.6435546875"));
			print(binaryRepresentation("6.125"));
			print(binaryRepresentation("1.0"));
			print(binaryRepresentation("3.5"));
			print(binaryRepresentation("3.72"));
		}
	}
}

