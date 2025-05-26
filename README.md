# 📘 BST Dictionary Management System

A console-based Dictionary Management System built using **C++** and the **Binary Search Tree (BST)** data structure. This system allows users to insert, search, update, delete, and display dictionary words efficiently. It also supports persistent storage through file handling, ensuring that dictionary entries are retained across sessions.

---

## 🔍 Overview

This project demonstrates how fundamental **Data Structures and Algorithms (DSA)** concepts—particularly BSTs—can be applied in real-world scenarios such as dictionary management. The system supports:

* Word insertion with meaning, synonyms, antonyms, and word forms
* Efficient word search, update, and deletion
* Display of all stored words in sorted order
* Persistent file storage using C++ file handling

---

## 🚀 Features

* 📘 **Insert Word**: Add new entries with full details.
* 🔎 **Search Word**: Quickly retrieve meaning, synonyms, antonyms, and forms.
* 📝 **Update Word**: Modify existing entries easily.
* ❌ **Delete Word**: Remove any word from the dictionary.
* 📂 **Display All**: View all words alphabetically.
* 🔚 **Exit**: Close the application safely.

---

## 🧰 Tools & Technologies

| Category             | Tools Used                       |
| -------------------- | -------------------------------- |
| Programming Language | C++                              |
| Data Structure       | Binary Search Tree (BST)         |
| IDE                  | Visual Studio / Code::Blocks     |
| File Handling        | C++ file I/O (`fstream`)         |
| Platform             | Windows / Linux (cross-platform) |

---

## ⚙ Functional Requirements

* Add, search, update, and delete dictionary entries.
* Display all words with complete information.
* Maintain persistent storage using files.

---

## 📈 Non-Functional Requirements

* 💡 **User-Friendly**: Console interface with clear prompts and error messages.
* ⚡ **Performance**: BST ensures fast operations even with large data.
* 🔒 **Reliability**: Handles incorrect inputs and file I/O errors.
* 📆 **Scalability**: Modular code structure for future improvements.
* 🔐 **Security**: Protects against accidental data loss.
* 🌐 **Portability**: Platform-independent C++ code.

---

## 🧠 DSA Concepts Used

* ✅ **Binary Search Tree (BST)**: For fast insert, delete, and search operations.
* ♻ **Recursion**: Core logic for BST functions.
* 🧾 **Tree Traversals**: Used for displaying data in sorted order (inorder).
* 📀 **File Handling**: Reads from and writes to text files to ensure data persistence.

---

## 🗂 Code Structure

| File / Module            | Purpose                                         |
| ------------------------ | ----------------------------------------------- |
| `DictionaryEntry` struct | Stores word, meaning, synonyms, antonyms, forms |
| `insert()`               | Adds a new word to the BST                      |
| `search()`               | Searches for a word                             |
| `deleteWord()`           | Deletes a word from the BST                     |
| `updateWord()`           | Modifies existing word details                  |
| `inorderTraversal()`     | Displays all dictionary entries alphabetically  |
| `readWordsFromFile()`    | Loads data from file at startup                 |
| `writeEntriesToFile()`   | Saves dictionary data back to file              |

---

## 📊 Example Usage (Console UI)

```
1. Insert Word
2. Search Word
3. Update Word
4. Delete Word
5. Display All Words
6. Exit
```

---

## 📝 Conclusion

This project showcases the power and utility of BSTs in organizing and managing structured data efficiently. With file-based persistence, the Dictionary Management System becomes a powerful, extensible learning tool for mastering data structures in C++.

---

## 📚 References

* [Binary Search Trees – Wikipedia](https://en.wikipedia.org/wiki/Binary_search_tree)
* [C++ File Handling – cplusplus.com](https://www.cplusplus.com/doc/tutorial/files/)
* [Recursion in C++ – GeeksforGeeks](https://www.geeksforgeeks.org/recursion-in-cpp/)
* [C++ Standard Library](https://en.cppreference.com/w/cpp)
