cd ~/dev/aoc-2022 && mkdir d$1 && mkdir d$1/build
cp d0/main.cpp d$1/main.cpp
cd d$1/build && cmake ../../
