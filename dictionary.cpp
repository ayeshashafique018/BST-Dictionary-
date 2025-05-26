

#include <iostream>
#include <fstream>
#include <String>
using namespace std;

// Structure for Dictionary Entry
struct DictionaryEntry {
    string word;
    string meaning;
    string synonym;
    string antonym;
    string forms;
    DictionaryEntry* left;
    DictionaryEntry* right;
};

// Function to create a new dictionary entry
DictionaryEntry* createDictionaryEntry(string word, string meaning, string synonym, string antonym, string forms) {
    DictionaryEntry* newEntry = new DictionaryEntry;
    newEntry->word = word;
    newEntry->meaning = meaning;
    newEntry->synonym = synonym;
    newEntry->antonym = antonym;
    newEntry->forms = forms;
    newEntry->left = nullptr;
    newEntry->right = nullptr;
    return newEntry;
}

// Function to insert a dictionary entry into the binary search tree
DictionaryEntry* insert(DictionaryEntry* root, string word, string meaning, string synonym, string antonym, string forms) {
    if (root == nullptr) {
        return createDictionaryEntry(word, meaning, synonym, antonym, forms);
    }

    if (word < root->word) {
        root->left = insert(root->left, word, meaning, synonym, antonym, forms);
    }
    else if (word > root->word) {
        root->right = insert(root->right, word, meaning, synonym, antonym, forms);
    }

    return root;
}

// Function to search for a word in the binary search tree
DictionaryEntry* search(DictionaryEntry* root, string word) {
    if (root == nullptr || root->word == word) {
        return root;
    }

    if (word < root->word) {
        return search(root->left, word);
    }

    return search(root->right, word);
}

// Function to read words from file and insert into BST
DictionaryEntry* readWordsFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open the file: " << filePath << endl;
        return nullptr;
    }

    DictionaryEntry* root = nullptr;
    string word, meaning, synonym, antonym, forms;
    while (file >> word >> meaning >> synonym >> antonym >> forms) {
        root = insert(root, word, meaning, synonym, antonym, forms);
    }

    file.close();
    return root;
}
// Function to write all entries from BST to file
void writeEntriesToFile(DictionaryEntry* root, ofstream& file) {
    if (root != nullptr) {
        writeEntriesToFile(root->left, file);
        file << root->word << " " << root->meaning << " " << root->synonym << " " << root->antonym << " " << root->forms << endl;
        writeEntriesToFile(root->right, file);
    }
}

// Function to create a new dictionary entry in the file
void createDictionaryEntryInFile(const string& filePath, const string& word, const string& meaning, const string& synonym, const string& antonym, const string& forms) {
    ofstream file(filePath, ios::app);
    if (file.is_open()) {
        file << word << " " << meaning << " " << synonym << " " << antonym << " " << forms << endl;
        file.close();
        cout << "Entry added successfully." << endl;
    }
    else {
        cerr << "Failed to open the file: " << filePath << endl;
    }
}
// Function to delete a word from the binary search tree
// Function to delete a word from the binary search tree and file
DictionaryEntry* deleteWord(DictionaryEntry* root, string word) {
    if (root == nullptr) {
        return nullptr;
    }

    // If the word to be deleted is smaller than the root's word, then it lies in the left subtree
    if (word < root->word) {
        root->left = deleteWord(root->left, word);
    }
    // If the word to be deleted is greater than the root's word, then it lies in the right subtree
    else if (word > root->word) {
        root->right = deleteWord(root->right, word);
    }
    // If the word is the same as root's word, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            DictionaryEntry* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            DictionaryEntry* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        DictionaryEntry* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->synonym = temp->synonym;
        root->antonym = temp->antonym;
        root->forms = temp->forms;

        // Delete the inorder successor
        root->right = deleteWord(root->right, temp->word);
    }

    // Rewrite the entire file
    ofstream file("dict.txt");
    if (file.is_open()) {
        // Write all entries from the BST back to the file
        writeEntriesToFile(root, file);
        file.close();
    }

    return root;
}
// Function to update a word in the binary search tree
DictionaryEntry* updateWord(DictionaryEntry* root, string oldWord, string newWord, string meaning, string synonym, string antonym, string forms) {
    // First, delete the old word
    root = deleteWord(root, oldWord);
    // Then, insert the updated word
    root = insert(root, newWord, meaning, synonym, antonym, forms);
    return root;
}
// Function to rewrite the entire file
void rewriteFile(DictionaryEntry* root, const string& filePath) {
    ofstream file(filePath);
    if (file.is_open()) {
        // Write all entries from the BST back to the file
        writeEntriesToFile(root, file);
        file.close();
    }
}


// Function to display dictionary entry details
void displayEntryDetails(DictionaryEntry* entry) {
    if (entry != nullptr) {
        cout << "Word: " << entry->word << endl;
        cout << "Meaning: " << entry->meaning << endl;
        cout << "Synonyms: " << entry->synonym << endl;
        cout << "Antonyms: " << entry->antonym << endl;
        cout << "Part of Speech : " << entry->forms << endl;
    }
    else {
        cout << "Word not found." << endl;
    }
}



// Function to display all words from file
void displayAllWordsFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open the file: " << filePath << endl;
        return;
    }

    string word, meaning, synonym, antonym, forms;
    while (file >> word >> meaning >> synonym >> antonym >> forms) {
        cout << "Word: " << word << endl;
        cout << "Meaning: " << meaning << endl;
        cout << "Synonyms: " << synonym << endl;
        cout << "Antonyms: " << antonym << endl;
        cout << "Part of speech : " << forms << endl;
        cout << "-----------------------" << endl;
    }

    file.close();
}


void head() {
    
        cout << "\t______ _____ _____ _____ _____ ___   _       ______ _____ _____ _____ _____ _____ _   _   ___  ________   __" << endl;
        cout << "\t|  _  \\_   _|  __ \\_   _|_   _/ _ \\ | |      |  _  \\_   _/  __ \\_   _|_   _|  _  | \\ | | / _ \\ | ___ \\ \\ / /" << endl;
        cout << "\t| | | | | | | |  \\/ | |   | |/ /_\\ \\| |      | | | | | | | /  \\/ | |   | | | | | |  \\| |/ /_\\ \\| |_/ /\\ V / " << endl;
        cout << "\t| | | | | | | | __  | |   | ||  _  || |      | | | | | | | |     | |   | | | | | | . ` ||  _  ||    /  \\ /  " << endl;
        cout << "\t| |/ / _| |_| |_\\ \\_| |_  | || | | || |____  | |/ / _| |_| \\__/\\ | |  _| |_\\ \\_/ / |\\  || | | || |\\ \\  | |  " << endl;
        cout << "\t|___/  \\___/ \\____/\\___/  \\_/\\_| |_/\\_____/  |___/  \\___/ \\____/ \\_/  \\___/ \\___/\\_| \\_/\\_| |_/\\_| \\_| \\_/  " << endl << endl;
}
int main() {
    head();
    string word, meaning, synonym, antonym, forms;
    string newWord; // Declare newWord outside of the switch statement

    // Read words from file and build the BST
    DictionaryEntry* root = readWordsFromFile("dict.txt");
    if (root == nullptr) {
        cerr << "Failed to build the binary search tree." << endl;
        return 1;
    }

    int choice;
    DictionaryEntry* foundEntry = nullptr; // Declare foundEntry outside the switch statement
    do {

        cout << endl << endl << endl;



        cout << endl << endl;
        cout << "\t\t       ----------------------------MAIN MENU--------------------------" << endl;

        cout << "\t\t ______________________________________ ____________________________________" << endl;
        cout << "\t\t|                                      |                                    |" << endl;
        cout << "\t\t|  (1) Insert Word                     |   (2) Search Word                  |" << endl;
        cout << "\t\t|  (3) Delete  Word                    |   (4) Update                       |" << endl;
        cout << "\t\t|  (5) Display All Words               |   (6) Exit                         |" << endl;
        cout << "\t\t|______________________________________|____________________________________|" << endl;
        cout << endl << endl;

        //// Display the main menu
        //cout << "\nMain Menu\n";
        //cout << "1. Insert word into file\n";
        //cout << "2. Search word from file\n";
        //cout << "3. Delete word from file\n";
        //cout << "4. Update word from file\n";
        //cout << "5. Display all words from file\n"; // Option to display all words
        //cout << "6. Exit\n"; // Corrected missing dot
        //cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Prompt the user to enter word details
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, meaning);
            cout << "Enter synonym: ";
            cin >> synonym;
            cout << "Enter antonym: ";
            cin >> antonym;
            cout << "Enter Part of speech: ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, forms);

            // Add the entry to the file
            createDictionaryEntryInFile("dict.txt", word, meaning, synonym, antonym, forms);
            break;
        case 2:
            // Prompt the user to enter the word to search
            cout << "Enter the word to search: ";
            cin >> word;

            // Search for the word in the BST
            foundEntry = search(root, word); // Assign the result to foundEntry
            // Display the details of the found entry
            displayEntryDetails(foundEntry);
            break;
        case 3:
            // Delete word from file
            cout << "Enter the word to delete: ";
            cin >> word;
            root = deleteWord(root, word);
            cout << "Word deleted Successfully! ";
           
            break;
        case 4:
            cout << "Enter the word to update: ";
            cin >> word;
            cout << "Enter new word: ";
            cin >> newWord; // Now using the previously declared newWord variable
            cout << "Enter meaning: ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, meaning);
            cout << "Enter synonym: ";
            cin >> synonym;
            cout << "Enter antonym: ";
            cin >> antonym;
            cout << "Enter part of speech : ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, forms);

            // Update the word in the file and BST
            root = updateWord(root, word, newWord, meaning, synonym, antonym, forms);
          

            // Rewrite the entire file
            rewriteFile(root, "dict.txt");
            cout << "Word Updated Successfully";
            break;
        case 5:
            // Display all words from file
            displayAllWordsFromFile("dict.txt");
            break;
        case 6:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.";
        }
    } while (choice != 6);

    return 0;
}
