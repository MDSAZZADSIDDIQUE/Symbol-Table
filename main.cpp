#include <iostream>
#include <string>
using namespace std;

class SymbolTable
{
	public:
		int maxSize = 1000;
	string firstString;
	string secondString;
	string thirdString;

	// identifiers
	char *identifiersStack = new char(maxSize);
	int identifiersStackTop = 0;
	bool checkIfIdentifiersStackIsEmpty()
	{
		return (identifiersStackTop == 0);
	}

	// operators
	char *operatorsStack = new char(maxSize);
	int operatorsStackTop = 0;
	bool checkIfOperatorssStackIsEmpty()
	{
		return (operatorsStackTop == 0);
	}

	// operators
	char *punctuationStack = new char(maxSize);
	int punctuationStackTop = 0;
	bool checkIfPunctuationStackIsEmpty()
	{
		return (punctuationStackTop == 0);
	}

	SymbolTable(string firstString, string secondString, string thirdString)
	{
		firstString = firstString;
		secondString = secondString;
		thirdString = thirdString;
	}

	SymbolTable() {}

	bool checkForIdentifier(char character)
	{
		if ((character == ' ' || character == '+' || character == '-' || character == '*' || character == '%' || character == '=' || character == '>' || character == '<' || character == '!' || character == '"' || character == '#' || character == '&' || character == '(' || character == ')' || character == ',' || character == '.' || character == ':' || character == ';' || character == '?' || character == '@' ||
				character == '[' || character == ']' || character == '^' || character == '_' || character == '{' || character == '|' || character == '}' || character == '~'))
			return true;
		else
			false;
	}

	void checkIdentifiers(string input)
	{
		for (int i = 0; i < input.length(); i++)
		{
		    if (!(input[0] >= '0' && input[0] <= '9'))
            {
                if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || ((input[i] >= '0' && input[i] <= '9')))
			{
					while (!checkForIdentifier(input[i] + 1))
					{
						identifiersStack[identifiersStackTop++] = input[i];
						i ++;
					}

				identifiersStack[identifiersStackTop++] = ',';
				identifiersStack[identifiersStackTop++] = ' ';
			}
            }

		}
	}

	void checkOperators(string input)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if ((input[i] == '+' && input[i + 1] == '+') || (input[i] == '-' && input[i + 1] == '-') || (input[i] == '+' && input[i + 1] == '=') || (input[i] == '-' && input[i + 1] == '=') || (input[i] == '*' && input[i + 1] == '=') || (input[i] == '/' && input[i + 1] == '=') || (input[i] == '%' && input[i + 1] == '=') || (input[i] == '=' && input[i + 1] == '=') || (input[i] == '!' && input[i + 1] == '=') || (input[i] == '>' && input[i + 1] == '=') || (input[i] == '<' && input[i + 1] == '=') || (input[i] == '&' && input[i + 1] == '&') || (input[i] == '|' && input[i + 1] == '|'))
			{
				operatorsStack[operatorsStackTop++] = input[i];
				operatorsStack[operatorsStackTop++] = input[i + 1];
				operatorsStack[operatorsStackTop++] = ',';
				operatorsStack[operatorsStackTop++] = ' ';
				i++;
			}
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '=' || input[i] == '>' || input[i] == '<' || input[i] == '!')

			{
				operatorsStack[operatorsStackTop++] = input[i];
				operatorsStack[operatorsStackTop++] = ',';
				operatorsStack[operatorsStackTop++] = ' ';
			}
		}
	}

	void checkPunctuation(string input)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '"' || input[i] == '#' || input[i] == '&' || input[i] == '(' || input[i] == ')' || input[i] == ',' || input[i] == '.' || input[i] == ':' || input[i] == ';' || input[i] == '?' ||
				input[i] == '[' || input[i] == ']' || input[i] == '^' || input[i] == '_' || input[i] == '{' || input[i] == '|' || input[i] == '}' || input[i] == '~')
			{
				punctuationStack[punctuationStackTop++] = input[i];
				punctuationStack[punctuationStackTop++] = ' ';
			}
		}
	}

	void printIdentifiers()
	{
		if (!checkIfIdentifiersStackIsEmpty())
			for (int i = 0; i < identifiersStackTop - 2; i++)
				cout << identifiersStack[i];
	}

	void printOperators()
	{
		if (!checkIfOperatorssStackIsEmpty())
			for (int i = 0; i < operatorsStackTop - 2; i++)
				cout << operatorsStack[i];
	}

	void printPunctuations()
	{
		if (!checkIfPunctuationStackIsEmpty())
			for (int i = 0; i < punctuationStackTop - 1; i++)
				cout << punctuationStack[i];
	}
};

int main()
{
	string firstString, secondString, thirdString;
	cout << "Input 1st string: ";
	getline(cin, firstString);
	cout << "Input 2nd string: ";
	getline(cin, secondString);
	cout << "Input 3rd string: ";
	getline(cin, thirdString);
	SymbolTable symbolTable(firstString, secondString, thirdString);
	symbolTable.maxSize = firstString.length() + secondString.length() + thirdString.length();

	symbolTable.checkIdentifiers(firstString);
	symbolTable.checkIdentifiers(secondString);
	symbolTable.checkIdentifiers(thirdString);

	symbolTable.checkOperators(firstString);
	symbolTable.checkOperators(secondString);
	symbolTable.checkOperators(thirdString);

	symbolTable.checkPunctuation(firstString);
	symbolTable.checkPunctuation(secondString);
	symbolTable.checkPunctuation(thirdString);

	cout << "============" << endl;
	cout << "SYMBOL TABLE" << endl;
	cout << "============" << endl;
	cout << "IDENTIFIER: ";
	symbolTable.printIdentifiers();
	cout << endl;
	cout << "============" << endl;
	cout << "OPERATORS: ";
	symbolTable.printOperators();
	cout << endl;
	cout << "============" << endl;
	cout << "PUNCTUATION: ";
	symbolTable.printPunctuations();
	cout << endl;
	cout << "============" << endl;
	return 0;
}
