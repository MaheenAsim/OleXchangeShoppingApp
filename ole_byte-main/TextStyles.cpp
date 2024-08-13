// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std; 
class Get_text{
    public:

    string text;
    string line;

    void userText()
    {
        cout << "Please type Description of your product, after you are done press enter twice: ";

        do
        {
            getline(cin, line);
            text += line;
        }
        while(line != "");
    }

    void to_string()
    {
        cout << "\n" << "User's Text: " << "\n" << text << endl;
    }

 void bold_on(){ // to make text bold
    char esc_char = 27; // the decimal code for escape character is 27
    cout << esc_char << "[1m" << text << endl; 
    }

 void bold_off(){
    char esc_char = 27; // the decimal code for escape character is 27
    cout << esc_char << "[0m" << text << endl; 
    }
 void italics(){ 
    char esc_char = 27; // the decimal code for escape character is 27
    cout << esc_char << "[3m" << text << endl; 
    }
 void underline(){
    char esc_char = 27; // the decimal code for escape character is 27
    cout << esc_char << "[4m" << text << endl; 
    }
 void highlighted(){ 
    char esc_char = 27; // the decimal code for escape character is 27
    cout << esc_char << "[7m" << text << endl; // 7 highlighted the text black
    }

};
int main() {
    //testing;
    // double tap the the Enter key/Return key on your keyboard to see the results of fonts
    Get_text test;
    test.userText();
    test.bold_on(); 
    test.underline();
    test.bold_off(); 
    test.italics();
    test.highlighted();
    // type ls n your terminal in the end to get your terminal back to original. 
}
