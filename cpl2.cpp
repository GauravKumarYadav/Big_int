/*
    NAME : GAURAV KUMAR YADAV
    ROLL NO. : BT17CSE025

                   "" CPL ASSIGNMENT 02""
*/
#include<bits/stdc++.h>
using namespace std;
#include <sstream>

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate lenght of both string
	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;

	// Initialy take carry zero
	int carry = 0;

	// Traverse from end of both strings
	for (int i=n1-1; i>=0; i--)
	{
		// compute sum of current digits and carry
		int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining digits of str2[]
	for (int i=n2-n1-1; i>=0; i--)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry+'0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}
// Returns true if str1 is smaller than str2,
// else false.
bool isSmaller(string str1, string str2)
{
	// Calculate lengths of both string
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 > n1)
		return false;

	for (int i=0; i<n1; i++)
	{
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;
	}
	return false;
}

// Function for finding difference of larger numbers
string findDiff(string str1, string str2)
{
	// Before proceeding further, make sure str1
	// is not smaller
	if (isSmaller(str1, str2))
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate lengths of both string
	int n1 = str1.length(), n2 = str2.length();
	int diff = n1 - n2;

	// Initially take carry zero
	int carry = 0;

	// Traverse from end of both strings
	for (int i=n2-1; i>=0; i--)
	{
		// Do school mathematics, compute difference of
		// current digits and carry
		int sub = ((str1[i+diff]-'0') - (str2[i]-'0') - carry);
		if (sub < 0)
		{
			sub = sub+10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of str1[]
	for (int i=n1-n2-1; i>=0; i--)
	{
		if (str1[i]=='0' && carry)
		{
			str.push_back('9');
			continue;
		}
		int sub = ((str1[i]-'0') - carry);
		if (i>0 || sub>0) // remove preceding 0's
			str.push_back(sub+'0');
		carry = 0;

	}

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}
// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0)
	return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(n1 + n2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1
	for (int i=n1-1; i>=0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;

		// Go from right to left in num2
		for (int j=n2-1; j>=0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum/10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
	return "0";

	// generate the result string
	string s = "";

	while (i >= 0)
		s+= std::to_string(result[i--]);

	return s;
}


// Driver code
int main()
{
	string str1 ;
	string str2 ;
	int choice;
	cout<<"enter first number\n";
	cin>>str1;
	cout<<"enter second number\n";
	cin>>str2;
	//cout << findSum(str1, str2);

	while(1)
	{
		cout<<"1.add\n";
		cout<<"2.subtract\n";
		cout<<"3.multiply\n";
		cout<<"4.exit\n";
		cout<<"enter your choice\n";
		cin>>choice;

	switch(choice)
	{

		case 1:
			{
				cout<< findSum(str1,str2)<<endl;
				break;
			}
		case 2:
			{
				cout<<findDiff(str1, str2)<<endl;
				break;
			}
		case 3:
			{
				if((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-' ))
					cout<<"-";

				if(str1.at(0) == '-' && str2.at(0)!='-')
				{
					str1 = str1.substr(1);
				}

				else if(str1.at(0) != '-' && str2.at(0) == '-')
				{
					str2 = str2.substr(1);
				}

				else if(str1.at(0) == '-' && str2.at(0) == '-')
				{
					str1 = str1.substr(1);
					str2 = str2.substr(1);
				}

				cout << multiply(str1, str2)<<endl;
				break;
			}

		case 4:
			{
				return 0;
				break;
			}
		default :
			{
				cout << " enter the proper choice" << endl;
			}
	}

	}
	return 0;
}

