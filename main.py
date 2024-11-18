import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), "build"))

from splicedList import SplicedList, SplicedListNonexistentKeyException

if __name__ == "__main__":
    spliced_list = SplicedList()
    spliced_list.insert("1")
    spliced_list.insert("3")
    print(spliced_list.get_all())
    spliced_list.insert("2", after="3")
    spliced_list.insert("0", after="1")
    print(spliced_list.get_all())
    spliced_list.insert("0")
    print(spliced_list.get_all())
    assert spliced_list.pop_value("0") == "0"
    result = spliced_list.get_all()
    assert len(result) == 3
    print(result)
    try:
        spliced_list.pop_value("0")
    except SplicedListNonexistentKeyException as e:
        print(e)
    print("All assertions passed 👍")
