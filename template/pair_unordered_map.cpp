unordered_map<pair<int, int>, int, decltype([](auto& pa) {
                return hash<int>()(pa.first) ^ hash<int>()(pa.second << 1);
              })>
    mp;