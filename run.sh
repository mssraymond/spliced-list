clear
rm -rf build
cmake -S . -B build && cmake --build build
black .
python main.py