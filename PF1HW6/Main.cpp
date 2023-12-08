#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void accountRead(string const filename, vector<Account>& accounts) { //Reads info from accounts.txt to tempAcc

    string fName, lName, PNum, aNum; //Declaring strings for all info

    Account tempAcc;  

    ifstream infile; //Opening accounts.txt
    infile.open(filename);

    while (infile >> fName >> lName >> PNum >> aNum) { //Uses setters to put info into tempAcc

        tempAcc.setFirstName(fName);
        tempAcc.setLastName(lName);
        tempAcc.setPIN(PNum);
        tempAcc.setAccountNumber(aNum);

        accounts.push_back(tempAcc);
    }

    infile.close(); //Closing accounts.txt

}

void transactionRead(string const filename2, vector<Transaction>& transactions) { //Reads info from transactions.txt to tempTrans

    string fromAccount, toAccount, amount, pin, numAccount; //Declaring strings for all info

    Transaction tempTrans;

    ifstream infile2; //Opening transactions.txt
    infile2.open(filename2);

    while (infile2 >> fromAccount >> toAccount >> amount >> pin >> numAccount) { //Uses setters to put info into tempTrans

        tempTrans.setFromAccountNumber(fromAccount);
        tempTrans.setToAccountNumber(toAccount);
        tempTrans.setAmount(amount);
        transactions.push_back(tempTrans);
    }

    infile2.close(); //Closes transactions.txt
}
void transactionWrite(string const filename, vector<Transaction> decryptions) { //Outputs decrypted tansaction info

    ofstream outfile; //Opening filename 
    outfile.open(filename);

    for (int i = 0; i < decryptions.size(); i++) {
        
        outfile << decryptions[i].getFromAccountNumber() << " " << decryptions[i].getToAccountNumber() << " " << decryptions[i].getAmount() << endl; //Outputting decrypted info
       
    }

    outfile.close(); //Closing filename
}
 
void findHackers(vector<Account> & accounts, vector <Transaction> & decryptions, vector <Account> & hackers) { //Finds info of hackers

    string numAccount; //Declaring strings aacount number and from account number
    string numFromAccount;

    for (int i = 0; i < accounts.size(); i++) {

        numAccount = accounts[i].getAccountNumber(); //Initializing with getter and accounts vector to numAccount
        hackers.push_back(accounts[i]);

        for (int j = 0; j < decryptions.size(); j++) {

            numFromAccount = decryptions[j].getFromAccountNumber(); //Initialzing with decrypted from account number getter
            if (numAccount == numFromAccount) {

                hackers.pop_back();
                break;
            }
        }
    }
}


int main() {

    string file1;
    string file2;
    string file3;

    file1 = "accounts.txt";
    file2 = "encryptedTransactions.txt";
    file3 = "decryptedTransactions.txt";

    string tempAccount;
    string tempPIN;

    vector<Account> accounts;
    accountRead(file1, accounts);

    for (int i = 0; i < accounts.size(); i++) {
        cout << i + 1 << " ";
        accounts[i].print();
    }

    vector<Transaction> transactions;
    transactionRead(file2, transactions);

    vector<Transaction> decryptions;
    vector<Account> hackers;

    //for loop to print transactions
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i].print();

    }

    //nested loops to decrypt transactions
    for (int i = 0; i < transactions.size(); i++) {
        
        for (int j = 0; j < accounts.size(); j++) {
            tempAccount = accounts[j].getAccountNumber();
            tempPIN = accounts[j].getPIN();

            if (transactions[i].decrypt(tempAccount, tempPIN)) {
                Transaction decryption(transactions[i]);
                decryptions.push_back(decryption);
                break;
            }
        }
    }

    transactionWrite(file3, decryptions);
    findHackers(accounts, decryptions, hackers);
    
    cout << endl << "The hackers have been indentified." << endl << endl;
    
    ofstream outfile(file3);
    
    for (int i = 0; i < hackers.size(); i++) {
        
        outfile << hackers[i].getFirstName() << " " << hackers[i].getLastName() << endl;
    }
    
    outfile.close();

    return 0;

}
