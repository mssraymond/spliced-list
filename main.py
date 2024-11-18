import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), "build"))

from splicedList import SplicedList, SplicedListNonexistentKeyException

if __name__ == "__main__":
    spliced_list = SplicedList()
    spliced_list.insert("1")
    spliced_list.insert("3")
    print(spliced_list.get_all())  # ['1', '3']
    spliced_list.insert("2", after="3")
    spliced_list.insert("0", after="1")
    print(spliced_list.get_all())  # ['0', '1', '2', '3']
    spliced_list.insert("0")
    print(spliced_list.get_all())  # ['1', '2', '3', '0']
    assert spliced_list.pop("0") == "0"
    spliced_list.insert("2", after="1")
    print(spliced_list.get_all())  # ['2', '1', '3']
    spliced_list.insert("1", after="2")
    result = spliced_list.get_all()
    assert len(result) == 3
    print(result)  # ['1', '2', '3']
    try:
        spliced_list.pop("0")
    except SplicedListNonexistentKeyException as e:
        print(e)
    print("All assertions passed 👍")
