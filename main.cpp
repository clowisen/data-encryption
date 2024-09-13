#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <windows.h>

using namespace std;


class Encryption {
    public:
    int choice1;
    int choice2;
    string file;
    string word;
    char letter;
    bool exist = false;

    void EncryptWord(string word);
    void DecryptWord(string word);
    void EncryptFile(string file);
    void DecryptFile(string file);
};

void Encryption::EncryptWord(string word){
    fstream write;
    write.open("encrypted.txt", fstream::out);

    for (int i = 0; i < word.length(); i++)
    {
        word[i] += 1000;
    }
    write << word << endl;
        
    write.close();

    cout << "Word encrypted: " << word << endl;
    cout << "Check encrypted.txt" << "\n";
}

void Encryption::DecryptWord(string word){
    fstream write;
    write.open("decrypted.txt", fstream::out);

    for (int i = 0; i < word.length(); i++)
    {
        word[i] -= 1000;
    }
    write << word << endl;
        
    write.close();

    cout << "Word decrypted: " << word << endl;
    cout << "Check decrypted.txt" << "\n";
}

void Encryption::EncryptFile(string file){
    fstream read, write;
    read.open(file, fstream::in);
    write.open("encrypted.txt", fstream::out);

    if(read.is_open()){
        while(read >> noskipws >> letter){
            write << char(letter+1000);
        }
        read.close();
        write.close();

        cout << "Data encrypted." << endl;
        cout << "Check encrypted.txt" << "\n";
        exist = false;
    }
    else{
        cout << "File does not exists!" << "\n";
        exist = true;
    }
}

void Encryption::DecryptFile(string file){
    fstream read, write;
    read.open(file, fstream::in);
    write.open("decrypted.txt", fstream::out);
    if (read.is_open())
    {  
        while(read >> noskipws >> letter){
            write << char(letter-1000);
        }
        read.close();
        write.close();

        cout << "Data decrypted." << endl;
        cout << "Check decrypted.txt" << "\n";   
        exist = false;
    }
    else{
        cout << "File does not exists!" << "\n";
        exist = true;
    }
}

int main(){
    Encryption encryption;
    main: 
    cout << "Welcome to Data Encryption " << endl;
    cout << "Choose a service" << endl;
    cout << "1) Encrypt" << endl;
    cout << "2) Decrypt" << endl;
    cout << "3) Exit" << endl;
    cin >> encryption.choice1;
    if (encryption.choice1 ==3)
    {
        cout << "Exiting program...";
        return 0;
    }
    else if(encryption.choice1 != 1 && encryption.choice1 != 2){
        cout << "Invalid choice!" << endl;
        goto main;
    }

    if(encryption.choice1 == 1){
        cout << "1) Word" << endl;
        cout << "2) File" << endl;
        cin >> encryption.choice2;
        if(encryption.choice2 == 1){
            cout << "Enter a word" << endl;
            cin >> encryption.word;
            encryption.EncryptWord(encryption.word);
            system("pause");
        }
        else if(encryption.choice2 == 2){
            encryptFile:
            cout << "Filename: " << endl;
            cin >> encryption.file;
            encryption.EncryptFile(encryption.file);
            if(encryption.exist == true){
                goto encryptFile;
            }
            system("pause");
        }
        else{
            cout << "Invalid choice!" << endl;
            goto main;
        }
    }
    else if(encryption.choice1 ==2){
        cout << "1) Word" << endl;
        cout << "2) File" << endl;
        cin >> encryption.choice2;
        if(encryption.choice2 == 1){
            cout << "Enter a word" << endl;
            cin >> encryption.word;
            encryption.DecryptWord(encryption.word);
            system("pause");
        }
        else if(encryption.choice2 == 2){
            decryptFile: 
            cout << "Filename: " << endl;
            cin >> encryption.file;
            encryption.DecryptFile(encryption.file);
            if(encryption.exist == true){
                goto decryptFile;
            }
            system("pause");
        }
        else{
            cout << "Invalid choice!" << endl;
            goto main;           
        }
    }
}