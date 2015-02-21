#include <iostream>
#include <fstream>

using namespace std;


class FileFilter {
public:
    virtual void doFilter(ifstream &in, ofstream &out) {
        char character;

        character = in.peek();     //peek at first character
        
        while(character != EOF) {
            in.get(character);
            character = transform(character);
            out << character;

            character = in.peek();
        }
        in.seekg(0, ios::beg);
    }

    virtual char transform(char character) = 0;
};


class CopyFilter : public FileFilter {
public:
    virtual char transform(char character) {
        return character;
    } 

};


class EncryptionFilter : public FileFilter {
private:
    int encryptionKey;

public:
    EncryptionFilter(int encrypt) {
        this->encryptionKey = encrypt;
    }

    virtual char transform(char character) {
        int ranger; //character range finder
        if (isupper(character)) {
            ranger = 65;
        } else {
            ranger = 97;
        }

        char result;
        switch(character) {
            case ' ':
            case '\n':
            case '\t':
                result = character;
                break;
            default:
               result = (character + encryptionKey) % 26 + ranger; 
        }
        
        return result;
    } 
};

class UpperFilter : public FileFilter {
public:

    virtual char transform(char character) {
        char upperCharacter = toupper(character);
        return upperCharacter;
    } 

};


class CipherFilter : public FileFilter {
    int count = 0;
public:
    
    virtual void doFilter(ifstream &in, ofstream &out) {
        char character;

        character = in.peek();     //peek at first character
        
        while(character != EOF) {
            
            bool skip = false;
            switch(character) {
                case ' ':
                case '\n':
                case '\t':
                    skip = true;
                    break;
            }
            
            in.get(character);

            if (!skip) {
                count++;
                out << transform(character);
                if (count % 5 == 0) {
                    out << ' ';
                }
            }
             
            character = in.peek();
        }
        in.seekg(0, ios::beg);
    }

    virtual char transform(char character) {   
        return toupper(character);
    }

};

int main() {
    ifstream inputFile;
    inputFile.open("inputFile.txt");

     if(inputFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    ofstream outputFile;
    outputFile.open("outputFile.txt");

     if(outputFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    ofstream encryptFile;
    encryptFile.open("encryptedOutput.txt");

     if(encryptFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    ofstream upperFile;
    upperFile.open("upperOutput.txt");

     if(upperFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    ofstream cipherFile;
    cipherFile.open("cipherOutput.txt");

     if(cipherFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    CopyFilter copyFilter;
    copyFilter.doFilter(inputFile, outputFile);
    outputFile.close();

    EncryptionFilter encryptionFilter(3);
    encryptionFilter.doFilter(inputFile, encryptFile);
    encryptFile.close();

    UpperFilter upperFilter;
    upperFilter.doFilter(inputFile, upperFile);
    upperFile.close();


    ifstream encryptFileIn;
    encryptFileIn.open("encryptedOutput.txt");

     if(inputFile.fail()) {
        cout << "Error. File did not open!";
        return 1;
    }

    CipherFilter cipherFilter;
    cipherFilter.doFilter(encryptFileIn, cipherFile);
    cipherFile.close();

    inputFile.close();
    encryptFileIn.close();

    return 0;
}