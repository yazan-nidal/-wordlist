#include<iostream>
#include<string>
using  namespace std;
class wordlist {
private:
	string lan;
	int n;
	int max;
	string* maxwords;
public:
	void load_Word_List(char* fileName) {
		FILE* pt = NULL;				
		pt = fopen(fileName, "r");	
		if(pt== NULL)				
		{
			cout<< "the file name is wrong\n";
			return;
		}
		char tem[100];				
		int count = 0;				
		fscanf(pt, "%S", tem);		

		while (!feof(pt))
		{
			fscanf(pt, "%S", tem);	
			count++;				
		}

		if(count>= max)				
		{
	    cout<< "Cannot load list, the number of words in the file exceeds the maximum words in the list\n";
			return;
		}

		rewind(pt);					

		fscanf(pt, "%S", tem);
		lan = tem;					

		string temWord;				
		while (!feof(pt))
		{
			fscanf(pt, "%S", tem);	
			temWord = tem;			
			add_word(temWord);
		}
	}
	wordlist(int M = 5) {
		n = 0;
		max = M;
		maxwords = new string[max];
	}
	~wordlist() {
		if (maxwords)
			delete[] maxwords;
	}
	wordlist(const wordlist& obj) {
		max = obj.max;
		n = obj.n;
		lan = obj.lan;
		for (int i = 0; i < n; i++)
			maxwords[i] = obj.maxwords[i];

	}
	wordlist operator  =(const wordlist& obj) {
		max = obj.max;
		n = obj.n;
		lan = obj.lan;
		for (int i = 0; i < n; i++)
			maxwords[i] = obj.maxwords[i];
		return *this;
	}

	void add_word(const string& g) {

		if (n == max) {

			cout << "list full,word not added" << endl;
			return;

		}
		if (contains(g)) { return; }
		maxwords[n] = g;

	}
	bool contains(const string& s) {
		for (int i = 0; i < n; i++)
			if (s == maxwords[i])
				return true;
		return false;
	}
	void display_word_list() {
		for (int q = 0; q < n; q++)
		{
			cout<<maxwords[q] << " ";
			if (q % 4 == 0 && q)
				cout<< endl;
		}
		cout<< endl;
	}
	bool equal_lists(const  newwordlist& obj) {
		if (lan !=newwordlist.lan) return false;
		if (n !=newwordlist.n) return false;
		for (int i=0; i<n; i++) {
			if (contains (newwordlist.maxwords[i]) == false)
				return false;
		}
		return true;
	}
	string operator [](int index) {
		if (index > n)
			return NULL;
		return maxwords[index];
	
	}

};
void main() {
	wordlist mywords;
	char fileName[100];
	cout << "pls enter a text file name for list" << endl;
	cin >> fileName;
	mywords.load_Word_List( fileName);
	mywords.add_word();
	string tem = "first";
	if (mywords.contains(tem))
		cout << "i found the word";
	else cout << "i didn't foun the word";
	wordlist mywords2;
	cout << "pls enter a text file name for the new list" << endl;
	cin >> fileName;
	if (mywords.equal_lists(mywords2)) {
		cout << "the first and second list are equal" << endl;
	}
	else
		cout << "the first and second list are not equal" << endl;
	wordlist mywords3(mywords);
	wordlist mywords4;
	mywords4 = mywords2;
	int index;
	cout << "pls enter the index " << endl;
	cin >> index;
	cout << "first list at index(" << index << ")=" << mywords[index] << endl;
	cout << "two list at index(" << index << ")=" << mywords2[index] << endl;
	cout << "three list at index(" << index << ")=" << mywords3[index] << endl;
	cout << "four list at index(" << index << ")=" << mywords4[index] << endl;
	cout << "the first list word:\n";
	mywords.display_word_list();
	cout << endl;
	cout << "thetwo list word:\n";
	mywords2.display_word_list();
	cout << endl;
	cout << "the three list word:\n";
	mywords3.display_word_list();
	cout << endl;
	cout << "the four list word:\n";
	mywords.display_word_list();
	cout << endl;
}