#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<string>clothes;
queue<string>electronics;
queue<string>acessories;
queue<string>other;
void tags(){
 int choice; 
 string entry = "myentry"; 
 cout<< "Which sorting option you want to put your entry into?" << endl; 
 cout<< "1. Clothes" << endl; 
 cout<< "2. Electronics " << endl; 
 cout<< "3. Acessories:" << endl; 
 cout<< "4. Other:" << endl; 
 cin>>choice; 
 if(choice == 1){
    clothes.push(entry); }
 if(choice==2)
    electronics.push(entry); 
 if (choice==3)
    acessories.push(entry); 
 if (choice==4)
    other.push(entry); 
} // for choosing the tags in the entry

//print queue


void sorting(){
    int option;
    cout << "which sorting option you want to view? " << endl; 
    cin >> option;
 if(option == 1){
     if (clothes.empty()){
        cout << "Ooppss! Sorry there is has not been any entry of this tag.";
     }
    while (!clothes.empty())
   {
    cout << clothes.front() << " ";
    clothes.pop(); }
    }
 
 cout << endl; 
 if(option==2){
     if (electronics.empty()){
        cout << "Ooppss! Sorry there is has not been any entry of this tag.";
     }
    while (!electronics.empty())
   {
    cout << electronics.front() << " ";
    electronics.pop(); }
 }
  cout << endl;
 if (option==3) {
     if (acessories.empty()){
        cout << "Ooppss! Sorry there is has not been any entry of this tag.";
     }
    while (!acessories.empty())
   {
    cout << acessories.front() << " ";
    acessories.pop(); }
 }
  cout << endl;
 if (option==4){
     if (other.empty()){
        cout << "Ooppss! Sorry there is has not been any entry of this tag.";
     }
    while (!other.empty())
   {
    cout << other.front() << " ";
    other.pop(); }
  cout << endl;

 }
 }
int main(){
    cout << "myentry" << endl; 
  tags(); 
  sorting();
}

