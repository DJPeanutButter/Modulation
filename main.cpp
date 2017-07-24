#include "Piece.h"
#include "Background.h"

#define GD_COLS 16
#define GD_ROWS 24

LRESULT CALLBACK  WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void EnableOpenGL  (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow){
  WNDCLASS  wc;
  HWND      hWnd;
  HDC       hDC;
  HGLRC     hRC;
  MSG       msg;
  BOOL      bQuit     = false;
  bool      homeTurn  = true;
  
  Color     bg1 (0.8f, 0.5f, 0.5f), bg2(0.2f, 0.5f, 0.5f);
  Piece     sel (COLOR(1.0f, 1.0f, 0.0f), 6, 1, PT_SELECT);
  
  std::vector<Piece>  home (GD_COLS),
                      away (GD_COLS),
                      moves;
  
  Piece *selPtr = NULL,
        *tarPtr = NULL,
        
        *hRookLeft,
        *hKnightLeft,
        *hBishopLeft,
        *hQueenLeft,
        *hQueenRight,
        *hBishopRight,
        *hKnightRight,
        *hRookRight,
        
        *aRookLeft,
        *aKnightLeft,
        *aBishopLeft,
        *aQueenLeft,
        *aQueenRight,
        *aBishopRight,
        *aKnightRight,
        *aRookRight;

  for (int i=0;i<home.size();i++){
    home[i].color   = COLOR (0.0f, 1.0f, 1.0f);
    home[i].row     = (char)-1;
  }

  hRookLeft       = &home[0];
  hRookLeft->row  = GD_ROWS-1;
  hRookLeft->col  = 0;
  hRookLeft->type = PT_ROOK;
  
  hKnightLeft       = &home[1];
  hKnightLeft->row  = GD_ROWS-1;
  hKnightLeft->col  = 1;
  hKnightLeft->type = PT_KNIGHT;
  
  hBishopLeft       = &home[2];
  hBishopLeft->row  = GD_ROWS-1;
  hBishopLeft->col  = 2;
  hBishopLeft->type = PT_BISHOP;
  
  hQueenLeft        = &home[3];
  hQueenLeft->row   = GD_ROWS-1;
  hQueenLeft->col   = 3;
  hQueenLeft->type  = PT_QUEEN;
  
  hQueenRight       = &home[4];
  hQueenRight->row  = GD_ROWS-1;
  hQueenRight->col  = GD_COLS-4;
  hQueenRight->type = PT_QUEEN;
  
  hBishopRight        = &home[5];
  hBishopRight->row   = GD_ROWS-1;
  hBishopRight->col   = GD_COLS-3;
  hBishopRight->type  = PT_BISHOP;
  
  hKnightRight        = &home[6];
  hKnightRight->row   = GD_ROWS-1;
  hKnightRight->col   = GD_COLS-2;
  hKnightRight->type  = PT_KNIGHT;
  
  hRookRight        = &home[7];
  hRookRight->row   = GD_ROWS-1;
  hRookRight->col   = GD_COLS-1;
  hRookRight->type  = PT_ROOK;

  for (int i=0;i<away.size();i++){
    away[i].color = COLOR (1.0f, 0.8f, 0.5f);
    away[i].row   = (char)-1;
  }
  
  aRookLeft       = &away[0];
  aRookLeft->row  = 0;
  aRookLeft->col  = 0;
  aRookLeft->type = PT_ROOK;
  
  aKnightLeft       = &away[1];
  aKnightLeft->row  = 0;
  aKnightLeft->col  = 1;
  aKnightLeft->type = PT_KNIGHT;
  
  aBishopLeft       = &away[2];
  aBishopLeft->row  = 0;
  aBishopLeft->col  = 2;
  aBishopLeft->type = PT_BISHOP;
  
  aQueenLeft        = &away[3];
  aQueenLeft->row   = 0;
  aQueenLeft->col   = 3;
  aQueenLeft->type  = PT_QUEEN;
  
  aQueenRight       = &away[4];
  aQueenRight->row  = 0;
  aQueenRight->col  = GD_COLS-4;
  aQueenRight->type = PT_QUEEN;
  
  aBishopRight        = &away[5];
  aBishopRight->row   = 0;
  aBishopRight->col   = GD_COLS-3;
  aBishopRight->type  = PT_BISHOP;
  
  aKnightRight        = &away[6];
  aKnightRight->row   = 0;
  aKnightRight->col   = GD_COLS-2;
  aKnightRight->type  = PT_KNIGHT;
  
  aRookRight        = &away[7];
  aRookRight->row   = 0;
  aRookRight->col   = GD_COLS-1;
  aRookRight->type  = PT_ROOK;

  wc.style          = CS_OWNDC;
  wc.lpfnWndProc    = WndProc;
  wc.cbClsExtra     = 0;
  wc.cbWndExtra     = 0;
  wc.hInstance      = hInstance;
  wc.hIcon          = LoadIcon (NULL, IDI_APPLICATION);
  wc.hCursor        = LoadCursor (NULL, IDC_ARROW);
  wc.hbrBackground  = (HBRUSH) GetStockObject (BLACK_BRUSH);
  wc.lpszMenuName   = NULL;
  wc.lpszClassName  = "GLWindowClass";
  RegisterClass (&wc);
  
  hWnd = CreateWindowEx (WS_EX_TOPMOST, "GLWindowClass", "Modulation",  WS_POPUP | WS_VISIBLE, 0, 0, GetSystemMetrics(1)*(GD_COLS/(float)GD_ROWS), GetSystemMetrics(1), NULL, NULL, hInstance, NULL);
  
  EnableOpenGL (hWnd, &hDC, &hRC);
  
  while (!bQuit){
    if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)){
      if (msg.message == WM_QUIT)
        bQuit = true;
      else if (msg.message == WM_KEYUP){
        switch (msg.wParam){
          case VK_ESCAPE:
            bQuit = true;
            break;
          case VK_LEFT:
            sel.col -= 1;
            break;
          case VK_UP:
            sel.row -= 1;
            break;
          case VK_RIGHT:
            sel.col += 1;
            break;
          case VK_DOWN:
            sel.row += 1;
            break;
          case VK_SPACE:
            //NOTHING ALREADY SELECTED
            if (selPtr == NULL){
              //*
              if ((selPtr = SelectPiece (sel.row, sel.col, (homeTurn?home:away))) != NULL){
                INVERT (sel.color);
                moves = FindMoves (*selPtr, (homeTurn?home:away), (homeTurn?away:home));
              }
              //*/
            }
            //SOMETHING ALREADY SELECTED
            else{
              //*
              bool killTar = false;
              if (SelectPiece (sel.row, sel.col, moves) != NULL){
                if ((tarPtr = SelectPiece (sel.row, sel.col, (homeTurn?away:home))) != NULL){
                  tarPtr->row = -1;
                  killTar = true;
                  selPtr->dir = 0;
                }
                MovePiece (*selPtr, sel.row, sel.col);
                
                homeTurn = not homeTurn;
              }
              if (killTar)
                (homeTurn?home:away).erase ((homeTurn?home:away).begin()+FindTarget (*tarPtr, (homeTurn?home:away)));
              INVERT (sel.color);
              selPtr = NULL;
              //*/
            }
            break;
          default:
            std::cout << "VK " << msg.wParam << " Pressed!" << std::endl;
            break;
        }
        if (sel.col==GD_COLS)
          sel.col = 0;
        if (sel.col==(char)-1)
          sel.col = GD_COLS-1;
        if (sel.row==GD_ROWS)
          sel.row = 0;
        if (sel.row==(char)-1)
          sel.row = GD_ROWS-1;
      }else{
        TranslateMessage(&msg);
        DispatchMessage  (&msg);
      }
    }else{
      glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
      glClear  (GL_COLOR_BUFFER_BIT);
      glPushMatrix();
      DrawBackground (bg1, bg2);
      
      for (int i=0;i<home.size();i++)
        home[i].draw();
      
      for (int i=0;i<away.size();i++)
        away[i].draw();
      
      if (selPtr != NULL)
        for (int i=0;i<moves.size();i++)
          moves[i].draw();
      
      sel.draw ();
      glPopMatrix  ();
      SwapBuffers  (hDC);
    }
  }
  
  DisableOpenGL (hWnd, hDC, hRC);
  DestroyWindow (hWnd);
  return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
  switch (message){
    case WM_CREATE:
      return 0;
    case WM_CLOSE:
      PostQuitMessage (0);
      return 0;
    case WM_DESTROY:
      return 0;
    default:
      return DefWindowProc (hWnd, message, wParam, lParam);
  }
}

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC){
  PIXELFORMATDESCRIPTOR  pfd;
  int      iFormat;
  
  *hDC = GetDC (hWnd);
  
  ZeroMemory (&pfd, sizeof (pfd));
  
  pfd.nSize       = sizeof (pfd);
  pfd.nVersion    = 1;
  pfd.dwFlags     = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
  pfd.iPixelType  = PFD_TYPE_RGBA;
  pfd.cColorBits  = 24;
  pfd.cDepthBits  = 16;
  pfd.iLayerType  = PFD_MAIN_PLANE;
  
  iFormat = ChoosePixelFormat (*hDC, &pfd);
  SetPixelFormat (*hDC, iFormat, &pfd);
  
  *hRC = wglCreateContext (*hDC);
  wglMakeCurrent (*hDC, *hRC);
  
  return;
}

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC){
  wglMakeCurrent (NULL, NULL);
  wglDeleteContext (hRC);
  ReleaseDC (hWnd, hDC);
  return;
}
