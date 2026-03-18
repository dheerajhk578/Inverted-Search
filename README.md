---

# 🔍 Inverted Search

## 📌 Overview

The **Inverted Search** project is a file indexing and searching system implemented in C. It builds an **inverted index** from multiple text files, allowing fast and efficient searching of words across files.

Instead of searching each file sequentially, this system maps each word to the files in which it appears, along with the frequency of occurrence.

---

## 🚀 Features

* 📂 Supports multiple input files
* 🔎 Fast word search using inverted indexing
* 📊 Displays word frequency across files
* 💾 Save index database to a file
* 📥 Load existing database for reuse
* ⚡ Efficient searching compared to linear search

---

## 🧠 Concept Used

* Hashing
* Linked Lists
* File Handling in C
* Data Structures (Indexing)
* Dynamic Memory Allocation

---

## 🏗️ Project Structure

```
Inverted_Search/
│
├── main.c
├── create_database.c
├── display_database.c
├── search.c
├── save_database.c
├── update_database.c
├── header.h
└── Makefile
```

---

## ⚙️ How It Works

1. Read multiple text files
2. Extract each word from files
3. Store words in a hash table
4. Maintain:

   * File name
   * Word frequency
5. Perform search in O(1) average time

---

## 🛠️ Compilation & Execution

### 🔧 Compile

```bash
gcc *.c
```

### ▶️ Run

```bash
./a.out file1.txt file2.txt file3.txt
```

---

## 📋 Menu Options

* Create Database
* Display Database
* Search Word
* Save Database
* Update Database
* Exit

---

## 🔍 Example

**Input Files:**

```
file1.txt → "hello world hello"
file2.txt → "hello C programming"
```

**Search Output:**

```
Word: hello
File: file1.txt → Count: 2
File: file2.txt → Count: 1
```

---

## 📈 Advantages

* Reduces search time significantly
* Scalable for large data
* Efficient memory usage with hashing

---

## ⚠️ Limitations

* Case-sensitive search (can be improved)
* Supports only text files
* No GUI (CLI-based)

---

## 🔮 Future Enhancements

* Case-insensitive search
* GUI-based interface
* Support for large datasets
* Stop-word filtering
* Ranking search results

---

## 🧑‍💻 Author

**Dheeraj H K**

---

## 🔗 GitHub Repository
dheerajhk578

---
