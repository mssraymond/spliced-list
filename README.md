# Spliced List Library

## What's this?

Basically an *ordered set* module written in C++. I called it "spliced-list" because it's implemented as a linked-list that also supports "splicing in" new/existing elements in constant time. Note that since it holds unique elements, inserting existing entries simply reorders them to the newly designated spots.

## Getting started

- Ensure you have Python (3.10), Pip, and CMake installed.
- Install requirements via:

```bash
pip install -r requirements.txt
```

- Then run:

```bash
./run.sh
```

- The output should look something like:

```text
['1', '3']
['0', '1', '2', '3']
['1', '2', '3', '0']
['2', '1', '3']
['1', '2', '3']
Key 0 does not exist!
All assertions passed 👍
```
