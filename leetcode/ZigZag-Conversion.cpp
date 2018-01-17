/* ZigZag Conversion */

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
class Solution{
public:
	std::string convert(std::string s, int nRows)
	{
		if (nRows <= 1 || s.size() <= nRows)
			return s;

		std::vector<std::string> vs(nRows);
		int row = 0;
		int step = 1;
		for (int i = 0; i < s.size(); ++i) {
			if (row == nRows - 1) step = -1;	/* 注意上边界和下边界 */
			if (row == 0)		  step = 1;
			vs[row] += s[i];
			row += step;
		}
		std::string ret;
		for (int i = 0; i < nRows; ++i) {
			ret += vs[i];
		}
		return ret;
	}
};


int main()
{
	/*
		P     H     D
		A   S I   S A    A
		Y  I  R  L  S   D
		P L   I G   D S
		A     N     A
	*/
	std::string str = "PAYPALISHIRINGLSDASDASDA";
	int nRows = 5;
	//std::string res = convert(str, nRows);
	Solution so;
	std::cout << so.convert(str, nRows) << std::endl;
	return 0;
}
