#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    queue<const char*> q_out;
    queue<const char*> q_out2;
    char ipt[100];
    char delim[] = " ";
    cin.getline(ipt, 100);
    vector<char*> splited_ipt;
    int split_index_ = -1, split_index;
    char* token = strtok(ipt, delim);
    while (token != NULL) {
      if (!(token[0] == 'I' && token[1] == 'F')) {
        if (token[0] == 'T' && token[1] == 'H') {
          split_index = split_index_;
          /*
          *   A and B THEN C
          *         ^
          *         index=2=split_index
          */
          token = strtok(NULL, delim);
          continue;
        }
        char* token_ = new char[10];
        *token_ = *token;
        splited_ipt.push_back(token_);
        split_index_++;
      }
      token = strtok(NULL, delim);
    }
    bool insert_not = true;
    int split_index__ = split_index;
    int offset = 0;
    for (int i = 0; i <= split_index; i++) {
      if (*splited_ipt[i] > 96) {  // lowercase
        switch (*splited_ipt[i]) {
          case 'a':
            q_out.push("or");
            insert_not = true;
            break;
          case 'n':
            insert_not = false;
            if (i <= split_index) split_index__--;
            offset--;
            break;
          case 'o':
            q_out.push("and");
            insert_not = true;
            break;
        }
      } else {
        if (insert_not) {
          q_out.push("not");
          offset++;
          if (i <= split_index) {
            split_index__++;
          }
        }
        char* tmp = new char[2];
        tmp[0] = *splited_ipt[i];
        tmp[1] = '\0';
        q_out.push(tmp);
        insert_not = true;
      }
    }
    insert_not = true;
    for (int i = split_index + 1; i < splited_ipt.size(); i++) {
      if (*splited_ipt[i] > 96) {  // lowercase
        switch (*splited_ipt[i]) {
          case 'a':
            q_out2.push("or");
            insert_not = true;
            break;
          case 'n':
            insert_not = false;
            if (i <= split_index) split_index__--;
            offset--;
            break;
          case 'o':
            q_out2.push("and");
            insert_not = true;
            break;
        }
      } else {
        if (insert_not) {
          q_out2.push("not");
          offset++;
          if (i <= split_index) {
            split_index__++;
          }
        }
        char* tmp = new char[2];
        tmp[0] = *splited_ipt[i];
        tmp[1] = '\0';
        q_out2.push(tmp);
        insert_not = true;
      }
    }
    cout << "IF ";
    for (int i = split_index__ + 1; i < splited_ipt.size() + offset; i++) {
      cout << q_out2.front() << " ";
      q_out2.pop();
    }
    cout << "THEN ";
    for (int i = 0; i <= split_index__; i++) {
      cout << q_out.front();
      q_out.pop();
      if (i != split_index__) cout << " ";
    }
    cout << '\n';
  }
  return 0;
}