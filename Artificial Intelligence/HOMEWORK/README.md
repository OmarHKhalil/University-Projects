
# Family Knowledge Base (Prolog)

## Description

A **Knowledge Representation** project using the Prolog language: a facts base about family members and their relationships, with rules to infer derived relationships (siblings, uncles, aunts, grandparents, cousins).

## Files

| File | Function |
|-------|---------|
| `HomeWorke.pl` | Main facts and rules |
| `HomeWorke.pl~` | Backup copy |

## Concepts Used

- Facts (`male/1`, `female/1`, `mother_of/2`, `father_of/2`)
- Derived rules: `parent_of`, `sblings`, `grandmother_of`, `grandfather_of`, `uncle_of`, `aunt_of`, `cousins`

## Running the Project

1. Install [SWI-Prolog](https://www.swi-prolog.org/).
2. From the project folder:

```bash
swipl -s HomeWorke.pl

```

3. Query examples inside the interpreter:

```prolog
?- parent_of(ana, rob).
?- cousins(kat, dom).
?- uncle_of(tio, fey).

```

## Project Structure

```
HOMEWORK/
├── README.md
├── HomeWorke.pl
├── HomeWorke.pl~

```