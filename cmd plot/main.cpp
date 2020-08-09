#include <bits/stdc++.h>
#include <windows.h>
struct _point_ {
  int x, y, z;
};
_point_ pnow = {0, 0, 0};
void _draw_(HDC hdc) {
  Graphics graphics(hdc);
  Pen pen(Color(255, 0, 0, 255));
  graphics.DrawLine(&pen, 0, 0, 200, 100);
}
double* f(double* nowY, double t) {
  for (int k = 0; k < nvar;k++){
      
  }
}
const double n = 1, m = 4, nvar, dt, Ndt, pair<int, int> tspan;
double Y0[n + m], Y[nvar][Ndt];
// init Y0 /////////////////---------------------------
void odeRK4() {
  dt = (tspan.second - tspan.first) / (Ndt - 1);
  for (int i = 0; i < nvar; i++) {
    Y[i][0] = Y0[i];
  }
  //t = linspace(tspan(1), tspan(2), Nt);
  for (int i = 0; i < Ndt - 1; i++) {
    double nowY1[nvar], nowY2[nvar], nowY3[nvar], nowY4[nvar];
    for (int k = 0; k < nvar; k++) {
      nowY1[k] = Y[k][i];
      nowY2[k] = 2 * nowY1[k] * (1 + dt / 2);
      nowY3[k] = 2 * nowY2[k] * (1 + dt / 2);
      nowY4[k] = 2 * nowY3[k] * (1 + dt);
    }
    double* k1 = f(nowY1, 0);  //t is not imporant
    double* k2 = f(nowY2, 0);  //t is not imporant
    double* k3 = f(nowY3, 0);  //t is not imporant
    double* k4 = f(nowY4, 0);  //t is not imporant
    for (int k = 0; k < nvar; k++) {
      Y[k][i + 1] = Y[k][i] + dt / 6 * (k1[k] - 2 * k2[k] + 2 * k3[k] + k4[k]);
    }
  }
  /*
 for ii=1:Nt-1
     K1 = f(Y(:,ii)          , t(ii)      );
     K2 = f(Y(:,ii)+K1*dt/2  , t(ii)+dt/2 );
     K3 = f(Y(:,ii)+K2*dt/2  , t(ii)+dt/2 );
     K4 = f(Y(:,ii)+K3*dt    , t(ii)+dt   );
     Y(:,ii+1) = Y(:,ii) + dt/6 * (K1+2*K2+2*K3+K4);*/
}
void _cacluate_() {
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // the handle for the window, filled by a function
  HWND hWnd;
  // this struct holds information for the window class
  WNDCLASSEX wc;

  // clear out the window class for use
  ZeroMemory(&wc, sizeof(WNDCLASSEX));

  // fill in the struct with the needed information
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  //wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.lpszClassName = ("WindowClass1");

  // register the window class
  RegisterClassEx(&wc);

  // this struct holds Windows event messages
  MSG msg = {0};

  // Enter the infinite message loop
  while (TRUE) {
    _cacluate_();

    // Check to see if any messages are waiting in the queue
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      // translate keystroke messages into the right format
      TranslateMessage(&msg);

      // send the message to the WindowProc function
      DispatchMessage(&msg);

      // check to see if it's time to quit
      if (msg.message == WM_QUIT)
        break;
    }
    RenderFrame();
  }

  // return this part of the WM_QUIT message to Windows
  return msg.wParam;
}
// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  HDC hdc;
  PAINTSTRUCT ps;

  // sort through and find what code to run for the message given
  switch (message) {
      // this message is read when the window is closed
    case WM_DESTROY:
      // close the application entirely
      PostQuitMessage(0);
      return 0;
    case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);
      _draw_(hdc);
      EndPaint(hWnd, &ps);
      return 0;
  }

  // Handle any messages the switch statement didn't
  return DefWindowProc(hWnd, message, wParam, lParam);
}