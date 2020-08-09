#include <bits/stdc++.h>
#define UNICODE
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nShowCmd) {
  std::setlocale(LC_ALL, "zh_TW.UTF-8");
  MessageBox(NULL,
             L"嗨",
             L"Just another Hello World program!",
             MB_ICONEXCLAMATION | MB_OK);
  return 0;
}