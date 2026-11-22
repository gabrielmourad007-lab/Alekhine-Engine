# Alekhine-Engine

Usage:
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/Alekhine-Engine -H runtime/history.txt -m runtime/move.txt