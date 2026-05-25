
# Islamic Inheritance Expert System ⚖️

[cite_start]An intelligent, rules-based Expert System designed to calculate and automate Islamic inheritance (Mirath) distribution based on specific deceased family status and parameters[cite: 3, 5, 12]. [cite_start]The system is built using Python and the **Experta** framework (a Python implementation of the Rete algorithm) to build a solid forward-chaining inference engine[cite: 3].

---

## 🏛️ Academic Context

* [cite_start]**Institution:** Arab International University (AIU) [cite: 1]
* [cite_start]**Faculty:** Information and Communication Engineering [cite: 2]
* [cite_start]**Project Title:** Islamic Inheritance System (EXP PROJECT) [cite: 4, 5]
* [cite_start]**Semester:** 2025-2 [cite: 9]
* **Supervised by:** Eng. [cite_start]Raghad Jihad Arab [cite: 11]

### 👥 Development Team
* [cite_start]**Omar Hafez Khalil** - (ID: 202110479) [cite: 6]
* [cite_start]**Abd Azeez Bawabh** - (ID: 202110414) [cite: 7]
* [cite_start]**Abd Azeez Arki** - (ID: 202110300) [cite: 8]

---

## 🛠️ System Architecture & Workflow

[cite_start]The architecture follows a dynamic decision tree modeled directly into logical rules inside a Knowledge Engine[cite: 3, 12]. The system takes real-time data inputs regarding the deceased's status, checks for data completeness and consistency, runs the inference process, and updates the knowledge base outputs accordingly.

### 🔄 Operational Flowchart

```

[START]
│
▼
[Enter Deceased's Data] ◄──────────────┐
│                                   │
▼                                   │ (If NO)
[Is Data Complete?] ──(YES)──► [Analyzing Deceased's Data]
│
▼
[Is Data Consistent with Law?]
│               │
(YES)            (NO)
│               │
▼               ▼
[Show Distribution]  [Update Knowledge Base]
│               │
▼               ▼
[STOP]     [Re-analyzing Data]
│
▼
[STOP]

```

---

## 📑 Rule-Base Breakdown

[cite_start]The system implements hierarchical rules starting from gender determination (**Rule 0**) down to specific legal inheritance quotas[cite: 13, 45, 270]:

1. [cite_start]**Gender & Marital Isolation:** Separates execution branches based on whether the deceased is Male or Female, and checks their corresponding marital ties[cite: 13, 18, 21].
2. [cite_start]**Spouse Share Allocation:** Calculates fixed legal fractions ($1/8$, $1/4$, $1/2$) based on the existence of a surviving wife or husband[cite: 45, 184, 244].
3. [cite_start]**Descendant Assessment (Children):** Adapts quotas dynamically depending on the presence of single/multiple daughters, sons, or a combination of both (with a 2:1 male-to-female ratio structure)[cite: 27, 49, 90].
4. [cite_start]**Ascendant Assessment (Parents):** Resolves edge cases involving surviving mothers and fathers, ensuring appropriate remnants are distributed correctly or addressing the need for custom overrides[cite: 36, 114, 273].

---

## 🚀 Installation & Prerequisites

Make sure you have Python 3.x installed on your machine.

### 1. Clone the repository
```bash
# Clone the entire repository
git clone https://github.com/OmarHKhalil/University-Projects.git

# Navigate into the Multimedia Networking Project directory
cd Expert Systems/islamic_inheritance_system
```

### 2. Install Dependencies

This system leverages the `experta` rule engine framework. Install it via pip:

```bash
pip install experta

```
---

## 💻 How To Run

Execute the main python script to trigger the interactive command-line expert system console:

```bash
python main.py

```

### Example Terminal Interaction:

```text
--- Islamic Inheritance Expert System ---
Rule 0: What is the gender of the deceased? (male/female): male
Rule 0.1: Is he married? (yes/no): yes
Rule 1: Is there a wife for the deceased alive? (yes/no): yes
Rule 2: Are there children for the deceased?
1- nothing
2- boys only
3- girls only
4- boys and girls
Answer (1/2/3/4): 2
Rule 3: Is there a father or a mother of the deceased alive?
1- There is a father.
2- There is a mother.
3- There is a father and a mother.
4- There is no.
Answer (1/2/3/4): 1

[Result]: The wife has the eighth - the father has a sixth - the rest is distributed between boys equally.

```

---

## 🗃️ Knowledge Dictionary Map

The core system stores predefined textual results bound directly to rule float IDs within `Inheritance_distribution_system`:

| Rule Key | Legal Inheritance Output Description |
| --- | --- |
| **3.1 - 3.4** | Wife takes $1/8$, manages remnants equally distributed to sons alongside optional parents' fractions.

 |
| **4.3 - 4.10** | Wife takes $1/8$, daughters take $1/2$ or $2/3$, with residual shares going to ascendants if alive.

 |
| **5.1 - 5.4** | Wife takes $1/8$, remnants distributed using Islamic Ta'seeb criteria (Male gets double Female share).

 |
| **12.1 - 12.4** | Husband takes $1/4$, remaining shares evaluated towards sons and parents.

 |
| **15.1 - 15.4** | Special Spousal cases without children (Husband takes $1/2$, Mother gets $1/3$ of remainder, Father inherits the rest).

 |
| **17.1 - 17.4** | General fallback state when no spouses/descendants exist (e.g., Father inherits all via innervation, or prompts system update).

 |

---
