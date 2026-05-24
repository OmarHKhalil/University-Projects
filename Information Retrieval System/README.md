
# 🔍 Bilingual Web Crawler & Smart Search Engine

A comprehensive Information Retrieval (IR) and Natural Language Processing (NLP) system built from scratch in Python. This project features a cross-lingual web crawler that extracts data, builds an inverted index, scores document relevance using **TF-IDF**, and supports both Boolean operations and semantic keyword expansions for English and Arabic text.

---

## ✨ Key Features

* **🕸️ Custom Web Crawler:** Recursively traverses websites down to a specified depth, extracts all paragraph text (`<p>` tags), and discovers internal/external links dynamically using regex and BeautifulSoup.
* **🌐 Cross-Lingual Preprocessing (AR/EN):**
  * **English:** Tokenizes, removes English stopwords, applies `PorterStemmer` and `WordNetLemmatizer`.
  * **Arabic:** Tokenizes, filters Arabic stopwords, and applies native light stemming via `ISRIStemmer`.
* **🗂️ Inverted Index & TF-IDF Ranking:** Automatically maps processed tokens to their corresponding URLs. It calculates Term Frequency (TF) and Inverse Document Frequency (IDF) to rank search results based on relevance.
* **🧠 Semantic Expansion via WordNet:** If an exact keyword match is missing in the index, the engine computes Wu-Palmer similarity (`wup_similarity`) using NLTK's **WordNet** to fallback to the most conceptually similar indexed term.
* **⚙️ Advanced Boolean Query Parser:** Evaluates complex multi-word query intents including `AND`, `OR`, and `NOT` operations through logical filtering models.

---

## 🛠️ Built With

* **Core Language:** Python 3
* **Web Scraping:** `requests`, `BeautifulSoup` (bs4)
* **Mathematical Operations:** `numpy`
* **NLP & Semantics:** `nltk` (Tokenizers, PorterStemmer, WordNet, ISRIStemmer, Stopwords)

---

## 🚀 Setup & Usage Guide

### 1. Download Dependencies & Datasets
Install the required standard libraries and open a Python shell to fetch the necessary NLTK corpora:

```bash
pip install requests beautifulsoup4 numpy nltk

```

Run the following inside Python to download resource packages:

```python
import nltk
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
nltk.download('omw-1.4')

```

### 2. Run the Engine

Execute the notebook or script. The console interface will prompt you to initialize the pipeline:

```bash
python search_engine.py

```

* **Step 1:** Enter a seed URL (e.g., `https://example.com`).
* **Step 2:** Define the maximum web depth (integer representing crawl steps).
* **Step 3:** Type your query using logical conditions (e.g., `python and data`, `ذكاء or حاسوب`).

---

## 📁 Repository Structure

* `search_engine.ipynb` - The primary production notebook containing execution steps.
* `README.md` - Documentation of the architectural capabilities.
