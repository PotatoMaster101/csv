# CSV Reader
I just want a quick and dirty header-only CSV reader in C++17.

## Usage
### Read line by line
```cpp
csv file{"file.csv"};
auto line = file.readline();
while (line) {
    // do things with line.value()
    line = file.readline();
}
```

### Read whole file
```cpp
csv file{"file.csv"};
for (const auto& line : file.readlines()) {
    // do things with line
}
```

### Write CSV
```cpp
std::vector<int> nums{1, 2, 3, 4, 5};
csv_write(std::cout, nums.begin(), nums.end());
```
