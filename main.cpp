#include "TextClass2.hpp"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

int main(){

	string text;
	int size;
	 cout<<"introduce text whithout space"<<endl;
        cin>>text;
	size=text.size();
	TextClass t1(text,size);
	t1.dispText();
	cout<<"TextLength "<<t1.getTextLength()<<endl;
	cout<<" passing number dispSign"<<endl;
	t1.dispSign(2);
	cout<<"set text"<<endl;
	t1.setText("ah");
	 t1.dispText();	        
	return 0;
}
