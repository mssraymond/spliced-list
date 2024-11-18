clear
rm -rf build
cmake -S cplusplus -B build && cmake --build build
black .
python main.py